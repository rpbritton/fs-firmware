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

static void task_func(void *data);

static USB_HID_HANDLE usb_hid_handle = -1;
static TaskHandle_t task_handle = NULL;

void usb_hid_receiver_init()
{

}

void usb_hid_receiver_run(USB_HID_HANDLE usb_handle)
{
	// do nothing if running
	if (task_handle)
		return;

	// set the usb handle
	usb_hid_handle = usb_handle;

	// start the task
	xTaskCreate(task_func, "usb_hid_receiver_task",
	            configMINIMAL_STACK_SIZE,
	            NULL, 1, &task_handle);
}

void usb_hid_receiver_stop()
{
	// do nothing if not running
	if (!task_handle)
		return;

	// stop the task
	vTaskDelete(task_handle);
	task_handle = NULL;

	// unset usb hid handle
	usb_hid_handle = 0;
}

unsigned usb_hid_receiver_endpoint()
{
	return USBD_AddEP(USB_DIR_IN, USB_TRANSFER_TYPE_INT, 0, NULL, 0);
}

static void task_func(void *data)
{
	// todo
	vTaskSuspend(NULL);
}

#endif /* FS_USE_USB */
