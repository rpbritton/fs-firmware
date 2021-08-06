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

#include "router.h"

#include <stdio.h>

#include "osal.h"

static void router_task(void *data);

QueueHandle_t router_queue = NULL;
TaskHandle_t router_handle = NULL;

void router_init()
{
	router_queue = xQueueCreate(20, sizeof(Packet));
}

void router_run()
{
	// do nothing if running
	if (router_handle)
		return;

	// stop router task
	xTaskCreate(router_task, "router_task",
	            configMINIMAL_STACK_SIZE * sizeof(StackType_t),
	            NULL, 1, &router_handle);
}

void router_end()
{
	// do nothing if not running
	if (!router_handle)
		return;

	// stop router task
	vTaskDelete(router_task);
	router_handle = NULL;
}

void router_send(Packet packet)
{
	xQueueSend(router_queue, &packet, 0);
}

void router_send_from_isr(Packet packet)
{
	xQueueSendFromISR(router_queue, &packet, NULL);
}

static void router_task(void *data)
{
	// start with empty queue
	xQueueReset(router_queue);

	// wait for items to enter the queue
	while (true)
	{
		Packet packet;
		xQueueReceive(router_queue, &packet, portMAX_DELAY);

		// route the packet
		switch (packet.type)
		{
		case PACKET_USB:
			break;
		case PACKET_EVENT:
			printf("yay got event packet, num: %d, state: %d\n", packet.num,
			       packet.state);
			break;
		case PACKET_LAYER:
			break;
		default:
			break;
		}
	}
}
