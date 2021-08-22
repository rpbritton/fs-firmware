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

#if FS_USE_USB

#include "usb.h"

#include <stdbool.h>

#include "hw_usb.h"
#include "sys_charger.h"

#include "usb_hid.h"

static struct
{
	bool started;
} usb;

void usb_init()
{
	usb_hid_init();
}

void usb_start_enumeration_cb()
{
	if (usb.started)
		return;
	usb.started = true;

	// start usb
	hw_usb_init();
	hw_usb_bus_attach();

	// start usb hid
	usb_hid_run();
}

void usb_detach_cb()
{
	if (!usb.started)
		return;
	usb.started = false;

	// stop usb hid
	usb_hid_stop();

	// stop usb
	hw_usb_bus_detach();
}

#endif /* FS_USE_USB */
