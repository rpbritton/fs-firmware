/**
 #include <app/outputs/printer.h>
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

#include "router.h"

#include "osal.h"

#include "core/layout.h"
#include "core/events.h"
#include "core/layer.h"
#include "outputs/printer.h"
#include "outputs/hid_sender.h"

#ifndef FS_ROUTER_QUEUE_SIZE
#define FS_ROUTER_QUEUE_SIZE (20)
#endif

static void router_task(void *data);

static QueueHandle_t queue_handle = NULL;
static TaskHandle_t task_handle = NULL;

void router_init()
{
	queue_handle = xQueueCreate(FS_ROUTER_QUEUE_SIZE, sizeof(Packet));
}

void router_run()
{
	// do nothing if running
	if (task_handle)
		return;

	// start router task
	xTaskCreate(router_task, "router_task",
	            configMINIMAL_STACK_SIZE,
	            NULL, 1, &task_handle);
}

void router_stop()
{
	// do nothing if not running
	if (!task_handle)
		return;

	// stop router task
	vTaskDelete(task_handle);
	task_handle = NULL;
}

void router_send(Packet packet)
{
	xQueueSend(queue_handle, &packet, 0);
}

static void router_task(void *data)
{
	// start with empty queue
	xQueueReset(queue_handle);

	// loop this forever
	while (true)
	{
		// wait for packets to enter the queue
		Packet packet;
		xQueueReceive(queue_handle, &packet, portMAX_DELAY);

		// route based on packet type
		switch (packet.spec.type)
		{
		case PACKET_LAYOUT:
			layout_send(packet);
			break;
		case PACKET_EVENT:
			events_send(packet);
			break;
		case PACKET_KEYBOARD:
			hid_sender_keyboard(packet);
			break;
		case PACKET_MOUSE:
			hid_sender_mouse(packet);
			break;
		case PACKET_CONSUMER:
			hid_sender_consumer(packet);
			break;
		case PACKET_LAYER:
			layer_send(packet);
			break;
		}
	}
}
