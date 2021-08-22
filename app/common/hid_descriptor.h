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

#ifndef APP_COMMON_HID_DESCRIPTOR_H_
#define APP_COMMON_HID_DESCRIPTOR_H_

#include "config.h"

#ifndef FS_HID_KEYBOARD_BOOT
#define FS_HID_KEYBOARD_BOOT (1)
#endif
#ifndef FS_HID_KEYBOARD_NKRO
#define FS_HID_KEYBOARD_NKRO (1)
#endif
#ifndef FS_HID_KEYBOARD_LEDS
#define FS_HID_KEYBOARD_LEDS (1)
#endif
#ifndef FS_HID_MOUSE
#define FS_HID_MOUSE         (0)
#endif
#ifndef FS_HID_CONSUMER
#define FS_HID_CONSUMER      (0)
#endif

#define HID_SET_OFFSET(name, offset) HID_OFFSET_ ## name, HID_OFFSET_PADDING_ ## name = HID_OFFSET_ ## name + offset - 1
enum HID_REPORT_INPUT
{
#if FS_HID_KEYBOARD_BOOT
	HID_SET_OFFSET(KEYBOARD_BOOT, 8), // HID_OFFSET_KEYBOARD_BOOT
#endif
#if FS_HID_KEYBOARD_NKRO
	HID_SET_OFFSET(KEYBOARD_NKRO, 32), // HID_OFFSET_KEYBOARD_NKRO
#endif
#if FS_HID_MOUSE
	HID_SET_OFFSET(MOUSE, 4), // HID_OFFSET_MOUSE
#endif
#if FS_HID_CONSUMER
	HID_SET_OFFSET(CONSUMER, 4), // HID_OFFSET_CONSUMER
#endif
	HID_INPUT_REPORT_SIZE,
};
enum HID_REPORT_OUTPUT
{
#if FS_HID_KEYBOARD_LEDS
	HID_SET_OFFSET(KEYBOARD_LEDS, 1), // HID_OFFSET_KEYBOARD_LEDS
#endif
	HID_OUTPUT_REPORT_SIZE,
};

#if FS_HID_KEYBOARD_BOOT
#define HID_DESCRIPTOR_KEYBOARD_BOOT \
    0x05, 0x07,       /* Usage Page (Key Codes) */ \
    0x19, 0xE0,       /* Usage Minimum (0xE0) */ \
    0x29, 0xE7,       /* Usage Maximum (0xE7) */ \
    0x15, 0x00,       /* Logical Minimum (0) */ \
    0x25, 0x01,       /* Logical Maximum (1) */ \
    0x75, 0x01,       /* Report Size (1) */ \
    0x95, 0x08,       /* Report Count (8) */ \
    0x81, 0x02,       /* Input (Data, Variable, Absolute) */ \
    \
    0x75, 0x08,       /* Report Size (8) */ \
	0x95, 0x01,       /* Report Count (1) */ \
	0x81, 0x01,       /* Input (Constant) */ \
	\
	0x05, 0x07,       /* Usage Page (Key Codes) */ \
	0x19, 0x00,       /* Usage Minimum (0x00) */ \
	0x29, 0xFF,       /* Usage Maximum (0xFF) */ \
	0x15, 0x00,       /* Logical Minimum (0) */ \
	0x26, 0xFF, 0x00, /* Logical Maximum (255) */ \
	0x75, 0x08,       /* Report Size (8) */ \
	0x95, 0x06,       /* Report Count (6) */ \
	0x81, 0x00,       /* Input (Data, Array, Absolute) */
#else
#define HID_DESCRIPTOR_KEYBOARD_BOOT
#endif

#if FS_HID_KEYBOARD_BOOT && FS_HID_KEYBOARD_NKRO
// neat trick for platforms (BIOS, probably) that only support boot keyboards:
// under the hood this boot report will still be set but anything that parses
// descriptors will ignore it, while the basic implementors will only check it.
#undef HID_DESCRIPTOR_KEYBOARD_BOOT
#define HID_DESCRIPTOR_KEYBOARD_BOOT \
    0x75, 0x08, /* Report Size (8) */ \
	0x95, 0x08, /* Report Count (8) */ \
    0x81, 0x01, /* Input (Constant) */
#endif

#if	FS_HID_KEYBOARD_NKRO
#define HID_DESCRIPTOR_KEYBOARD_NKRO \
    0x05, 0x07,       /* Usage Page (Key Codes) */ \
    0x19, 0x00,       /* Usage Minimum (0x00) */ \
	0x29, 0xFF,       /* Usage Maximum (0xFF) */ \
    0x15, 0x00,       /* Logical Minimum (0) */ \
    0x25, 0x01,       /* Logical Maximum (1) */ \
    0x75, 0x01,       /* Report Size (1) */ \
	0x96, 0xFF, 0x00, /* Report Count (255) */ \
    0x81, 0x02,       /* Input (Data, Variable, Absolute) */
#else
#define HID_DESCRIPTOR_KEYBOARD_NKRO
#endif

#if	FS_HID_KEYBOARD_LEDS
#define HID_DESCRIPTOR_KEYBOARD_LEDS \
    0x05, 0x08, /* Usage Page (LEDs) */ \
    0x19, 0x01, /* Usage Minimum (Num Lock) */ \
    0x29, 0x05, /* Usage Maximum (Kana) */ \
    0x15, 0x00, /* Logical Minimum (0) */ \
    0x25, 0x01, /* Logical Maximum (1) */ \
    0x75, 0x01, /* Report Size (1) */ \
    0x95, 0x05, /* Report Count (5) */ \
    0x91, 0x02, /* Output (Data, Variable, Absolute) */ \
    0x75, 0x01, /* Report Size (1) */ \
	0x95, 0x03, /* Report Count (3) */ \
	0x91, 0x01, /* Output (Constant) */
#else
#define HID_DESCRIPTOR_KEYBOARD_LEDS
#endif

#if	FS_HID_MOUSE
#define HID_DESCRIPTOR_MOUSE \
	0x05, 0x09, /* Usage Page (Button) */ \
    0x19, 0x01, /* Usage Minimum (0x01) */ \
	0x29, 0x08, /* Usage Maximum (0x08) */ \
	0x15, 0x00, /* Logical Minimum (0) */ \
	0x25, 0x01, /* Logical Maximum (1) */ \
	0x75, 0x01, /* Report Size (1) */ \
	0x95, 0x08, /* Report Count (8) */ \
	0x81, 0x02, /* Input (Data, Variable, Absolute) */ \
	0x05, 0x01, /* Usage Page (Generic Desktop Ctrls) */ \
	0x09, 0x30, /* Usage (X) */ \
	0x09, 0x31, /* Usage (Y) */ \
	0x15, 0x80, /* Logical Minimum (-128) */ \
	0x25, 0x7F, /* Logical Maximum (127) */ \
	0x75, 0x08, /* Report Size (8) */ \
	0x95, 0x02, /* Report Count (2) */ \
	0x81, 0x06, /* Input (Data, Variable, Absolute) */ \
	0x09, 0x38, /* Usage (Wheel) */ \
	0x15, 0x80, /* Logical Minimum (-128) */ \
	0x25, 0x7F, /* Logical Maximum (127) */ \
	0x75, 0x08, /* Report Size (8) */ \
	0x95, 0x01, /* Report Count (1) */ \
	0x81, 0x06, /* Input (Data, Variable, Absolute) */
#else
#define HID_DESCRIPTOR_MOUSE
#endif

// todo: convert this to use 16-bit codes?
#if	FS_HID_CONSUMER
#define HID_DESCRIPTOR_CONSUMER \
	0x05, 0x0C, /* Usage Page (Consumer) */ \
	0x19, 0x00, /* Usage Minimum (0x00) */ \
	0x29, 0xFF, /* Usage Maximum (0xFF) */ \
	0x15, 0x00, /* Logical Minimum (0xFF) */ \
	0x25, 0x01, /* Logical Maximum (0xFF) */ \
    0x75, 0x01, /* Report Size (8) */ \
    0x95, 0xFF, /* Report Count (4) */ \
    0x81, 0x02, /* Input (Data, Variable, Absolute) */
#else
#define HID_DESCRIPTOR_CONSUMER
#endif

#define HID_DESCRIPTOR {\
	0x05, 0x01, /* Usage Page (Generic Desktop) */ \
    0x09, 0x06, /* Usage (Keyboard) */ \
    0xA1, 0x01, /* Collection (Application) */ \
	HID_DESCRIPTOR_KEYBOARD_BOOT \
	HID_DESCRIPTOR_KEYBOARD_NKRO \
	HID_DESCRIPTOR_KEYBOARD_LEDS \
	HID_DESCRIPTOR_MOUSE \
	HID_DESCRIPTOR_CONSUMER \
	0xC0, /* End Collection */ \
}

#endif /* APP_COMMON_HID_DESCRIPTOR_H_ */
