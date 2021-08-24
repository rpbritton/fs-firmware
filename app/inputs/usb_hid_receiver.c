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

#include "usb_hid_receiver.h"

#include "osal.h"
#include "USB.h"

#include "common/hid_descriptor.h"
#include "inputs/hid_receiver.h"

static void usb_hid_receiver_task(void *data);

static struct
{
	USB_HID_HANDLE usb_hid;
	TaskHandle_t task;
} usb_hid_receiver = { .usb_hid = -1 };

void usb_hid_receiver_init()
{

}

void usb_hid_receiver_run(USB_HID_HANDLE usb_handle)
{
	// do nothing if running
	if (usb_hid_receiver.task)
		return;

	// set the usb handle
	usb_hid_receiver.usb_hid = usb_handle;

	// start the task
	xTaskCreate(usb_hid_receiver_task, "usb_hid_receiver_task",
	            configMINIMAL_STACK_SIZE,
	            NULL, 1, &usb_hid_receiver.task);
}

void usb_hid_receiver_stop()
{
	// do nothing if not running
	if (!usb_hid_receiver.task)
		return;

	// stop the task
	vTaskDelete(usb_hid_receiver.task);
	usb_hid_receiver.task = NULL;

	// unset usb hid handle
	usb_hid_receiver.usb_hid = -1;
}

unsigned usb_hid_receiver_endpoint()
{
	return USBD_AddEP(USB_DIR_IN, USB_TRANSFER_TYPE_INT, 0, NULL, 0);
}

static void usb_hid_receiver_task(void *data)
{
	while (true)
	{
		uint8_t report[HID_OUTPUT_REPORT_SIZE];
		USBD_HID_Read(usb_hid_receiver.usb_hid,
		              report,
		              HID_OUTPUT_REPORT_SIZE,
		              0);
		hid_receiver_send(report);
	}
}

#endif /* FS_USE_USB */
