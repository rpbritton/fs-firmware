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

#include "usb_hid.h"

#include "USB.h"
#include "USB_HID.h"

#include "config.h"
#include "core/hid.h"
#include "inputs/usb_hid_receiver.h"
#include "outputs/usb_hid_sender.h"

static void task_func(void *data);

static const USB_DEVICE_INFO usb_device_info = {
    .VendorId = FS_HID_VENDOR_ID,
    .ProductId = FS_HID_PRODUCT_ID,
    .sVendorName = FS_HID_VENDOR_NAME,
    .sProductName = FS_HID_PRODUCT_NAME,
    .sSerialNumber = FS_HID_SERIAL_NUMBER,
};

static TaskHandle_t task_handle = NULL;

void usb_hid_run()
{
	// do nothing if running
	if (task_handle)
		return;

	// start usb hid task
	xTaskCreate(task_func, "usb_hid_task",
	            configMINIMAL_STACK_SIZE,
	            NULL, 1, &task_handle);
}

void usb_hid_stop()
{
	// do nothing if not running
	if (!task_handle)
		return;

	// stop usb hid task
	vTaskDelete(task_handle);
	task_handle = NULL;

	// stop usb hid receiver and sender
	usb_hid_receiver_stop();
	usb_hid_sender_stop();

	// stop usb
	USBD_DeInit();
}

static void task_func(void *data)
{
	// init usb
	USBD_Init();

	// set device info
	USBD_SetDeviceInfo(&usb_device_info);

	// set the init data
	USB_HID_INIT_DATA usb_hid_init_data = {
	    .EPIn = usb_hid_receiver_endpoint(),
	    .EPOut = usb_hid_sender_endpoint(),
	    .pReport = hid_descriptor(),
	    .NumBytesReport = hid_descriptor_size(),
	    .BuffSize = 0, // todo: this may need to be set
	    .pBuff = NULL,
	};
	USB_HID_HANDLE usb_hid_handle = USBD_HID_Add(&usb_hid_init_data);

	// todo: handle required events like get_report
	// (see page 78 of https://www.usb.org/sites/default/files/hid1_11.pdf)

	// start usb
	USBD_Start();

	// wait for configuration
	while ((USBD_GetState() & (USB_STAT_CONFIGURED | USB_STAT_SUSPENDED)) != USB_STAT_CONFIGURED)
	{
		vTaskDelay(50);
		continue;
	}

	// start hid receiver and sender
	usb_hid_receiver_run(usb_hid_handle);
	usb_hid_sender_run(usb_hid_handle);

	// wait forever
	vTaskSuspend(NULL);
}

#endif /* FS_USE_USB */
