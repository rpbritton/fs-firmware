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

#include "hid_receiver.h"

#include "common/hid_descriptor.h"
#include "core/router.h"

#ifndef FS_HID_LED_NUM_LOCK
#define FS_HID_LED_NUM_LOCK (-1)
#endif

#ifndef FS_HID_LED_CAPS_LOCK
#define FS_HID_LED_CAPS_LOCK (-1)
#endif

#ifndef FS_HID_LED_SCROLL_LOCK
#define FS_HID_LED_SCROLL_LOCK (-1)
#endif

#ifndef FS_HID_LED_COMPOSE
#define FS_HID_LED_COMPOSE (-1)
#endif

#ifndef FS_HID_LED_KANA
#define FS_HID_LED_KANA (-1)
#endif

static const uint8_t hid_led_events[5] = {
FS_HID_LED_NUM_LOCK,
FS_HID_LED_CAPS_LOCK,
FS_HID_LED_SCROLL_LOCK,
FS_HID_LED_COMPOSE,
FS_HID_LED_KANA,
};

static struct
{
	uint8_t leds;
} hid_receiver;

static void hid_receiver_leds(uint8_t *report)
{
	uint8_t leds = report[HID_OFFSET_KEYBOARD_LEDS];
	for (int index = 0; index < 5; index++)
	{
		bool current_state = !!(leds & (1 << index));
		bool previous_state = !!(hid_receiver.leds & (1 << index));
		if (current_state == previous_state)
			continue;

		Packet packet;
		packet.state = (current_state) ? PACKET_ON : PACKET_OFF;
		packet.spec.type = PACKET_EVENT;
		packet.spec.num = hid_led_events[index];
		router_send(packet);
	}
	hid_receiver.leds = leds;
}

void hid_receiver_send(uint8_t *report)
{
	hid_receiver_leds(report);
}
