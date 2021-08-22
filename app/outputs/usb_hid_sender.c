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

static void usb_hid_sender_task(void *data);

static struct
{
	uint8_t usb_buffer[USB_MAX_PACKET_SIZE];
	USB_HID_HANDLE usb_hid;
	QueueHandle_t queue;
	TaskHandle_t task;
} usb_hid_sender = { .usb_hid = -1 };

void usb_hid_sender_init()
{
	usb_hid_sender.queue = xQueueCreate(1, HID_INPUT_REPORT_SIZE);
}

void usb_hid_sender_run(USB_HID_HANDLE usb_handle)
{
	// do nothing if running
	if (usb_hid_sender.task)
		return;

	// set the usb handle
	usb_hid_sender.usb_hid = usb_handle;

	// start the task
	BaseType_t status = xTaskCreate(usb_hid_sender_task, "usb_hid_sender_task",
	                                configMINIMAL_STACK_SIZE,
	                                NULL, 1, &usb_hid_sender.task);
}

void usb_hid_sender_stop()
{
	// do nothing if not running
	if (!usb_hid_sender.task)
		return;

	// stop the task
	vTaskDelete(usb_hid_sender.task);
	usb_hid_sender.task = NULL;

	// unset usb hid handle
	usb_hid_sender.usb_hid = -1;
}

unsigned usb_hid_sender_endpoint()
{
	return USBD_AddEP(USB_DIR_OUT, USB_TRANSFER_TYPE_INT, 0,
	                  usb_hid_sender.usb_buffer,
	                  sizeof(usb_hid_sender.usb_buffer));
}

void usb_hid_sender_send(uint8_t *report)
{
	if (!usb_hid_sender.queue)
		return;
	// todo: how should this work, maybe have a queue of a certain length and block when full?
	xQueueOverwrite(usb_hid_sender.queue, report);
}

static void usb_hid_sender_task(void *data)
{

	// start with empty queue
	xQueueReset(usb_hid_sender.queue);

	while (true)
	{
		// wait for a report
		uint8_t report[HID_INPUT_REPORT_SIZE];
		BaseType_t state = xQueueReceive(usb_hid_sender.queue, report,
		                                 portMAX_DELAY);

		// write the usb report
		USBD_HID_Write(usb_hid_sender.usb_hid, report, HID_INPUT_REPORT_SIZE,
		               0);
	}
}

#endif /* FS_USE_USB */
