/**
 * Copyright 2021 Ryan Britton
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "outputs/hid_sender.h"

#include <stdio.h>

#include "common/hid_descriptor.h"
#include "outputs/usb_hid_sender.h"

uint8_t report[HID_INPUT_REPORT_SIZE];

#if FS_HID_KEYBOARD_BOOT
static bool set_keyboard_boot_modifiers(Packet packet)
{
	uint8_t index = HID_OFFSET_KEYBOARD_BOOT;
	uint8_t map = (1 << (packet.spec.num - 0xE0));

	if ((report[index] & map) == (packet.state == PACKET_ON))
		return false;

	report[index] ^= map;
	return true;
}

static bool set_keyboard_boot_keys(Packet packet)
{
	if (packet.state == PACKET_ON)
	{
		// check check report for existing or opening
		uint8_t free_index = 0;
		for (uint8_t index = HID_OFFSET_KEYBOARD_BOOT + 2; index < 8; index++)
			if (report[index] == packet.spec.num)
				return false;
			else if (report[index] == 0)
				free_index = index;

		// do nothing if already have 6 keys depressed
		if (!free_index)
			return false;

		// set key as active
		report[free_index] = packet.spec.num;
		return true;
	}
	else
	{
		// search for the code in the report
		for (uint8_t index = HID_OFFSET_KEYBOARD_BOOT + 2; index < 8; index++)
		{
			if (report[index] == packet.spec.num)
			{
				report[index] = 0;
				return true;
			}
		}

		return false;
	}
}

static bool set_keyboard_boot(Packet packet)
{
	// set modifiers or keys
	if (packet.spec.num > 0xE0 && packet.spec.num < 0xE7)
		return set_keyboard_boot_modifiers(packet);
	else
		return set_keyboard_boot_keys(packet);
}
#endif

#if FS_HID_KEYBOARD_NKRO
static bool set_keyboard_nkro(Packet packet)
{
	// calculate placement in the bitmap
	uint8_t index = HID_OFFSET_KEYBOARD_NKRO + packet.spec.num / 8;
	uint8_t map = (1 << (packet.spec.num % 8));

	// check whether will change
	if ((report[index] & map) == (packet.state == PACKET_ON))
		return false;

	// set the bit
	report[index] ^= map;
	return true;
}
#endif

void hid_sender_keyboard(Packet packet)
{
	bool report_changed = false;

#if FS_HID_KEYBOARD_BOOT
	report_changed |= set_keyboard_boot(packet);
#endif

#if FS_HID_KEYBOARD_NKRO
	report_changed |= set_keyboard_nkro(packet);
#endif

	if (!report_changed)
		return;

	hid_sender_report();
}

void hid_sender_mouse(Packet packet)
{
// todo
}

void hid_sender_consumer(Packet packet)
{
// todo
}

void hid_sender_report()
{
#if FS_USE_USB
	usb_hid_sender_send(report);
#endif
}
