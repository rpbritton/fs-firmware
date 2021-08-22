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

#include "usb_hid_sender.h"

#include "common/hid_descriptor.h"

static void task_func(void *data);

static uint8_t usb_buffer[USB_MAX_PACKET_SIZE];

static USB_HID_HANDLE usb_hid_handle = -1;
static QueueHandle_t queue_handle = NULL;
static TaskHandle_t task_handle = NULL;

void usb_hid_sender_init()
{
	queue_handle = xQueueCreate(1, HID_INPUT_REPORT_SIZE);
}

void usb_hid_sender_run(USB_HID_HANDLE usb_handle)
{
	// do nothing if running
	if (task_handle)
		return;

	// set the usb handle
	usb_hid_handle = usb_handle;

	// start the task
	BaseType_t status = xTaskCreate(task_func, "usb_hid_sender_task",
	                                configMINIMAL_STACK_SIZE,
	                                NULL, 1, &task_handle);
}

void usb_hid_sender_stop()
{
	// do nothing if not running
	if (!task_handle)
		return;

	// stop the task
	vTaskDelete(task_handle);
	task_handle = NULL;

	// unset usb hid handle
	usb_hid_handle = -1;
}

unsigned usb_hid_sender_endpoint()
{
	return USBD_AddEP(USB_DIR_OUT, USB_TRANSFER_TYPE_INT, 0, usb_buffer,
	                  sizeof(usb_buffer));
}

void usb_hid_sender_send(uint8_t *report)
{
	if (usb_hid_handle == -1)
		return;
	// todo: how should this work, maybe have a queue of a certain length and block when full?
	xQueueOverwrite(queue_handle, report);
}

static void task_func(void *data)
{
	while (true)
	{
		uint8_t report[HID_INPUT_REPORT_SIZE];
		BaseType_t state = xQueueReceive(queue_handle, report, portMAX_DELAY);
		USBD_HID_Write(usb_hid_handle, report, HID_INPUT_REPORT_SIZE, 0);
	}
}

#endif /* FS_USE_USB */
