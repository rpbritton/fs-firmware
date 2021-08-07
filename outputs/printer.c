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

#if FS_USE_PRINTER

#include "printer.h"

#include <stdio.h>

static void printer_task(void *data);

QueueHandle_t queue_handle = NULL;
TaskHandle_t task_handle = NULL;

void printer_init()
{
	queue_handle = xQueueCreate(20, sizeof(Packet));
}

void printer_run()
{
	// do nothing if running
	if (task_handle)
		return;

	// start task
	xTaskCreate(printer_task, "router_task",
	            configMINIMAL_STACK_SIZE * sizeof(StackType_t),
	            NULL, 1, &task_handle);
}

void printer_stop()
{
	// do nothing if not running
	if (!task_handle)
		return;

	// stop task
	vTaskDelete(task_handle);
	task_handle = NULL;
}

QueueHandle_t printer_get_queue()
{
	return queue_handle;
}

static void printer_task(void *data)
{
	// start with empty queue
	xQueueReset(queue_handle);

	// wait for items to enter the queue
	while (true)
	{
		Packet packet;
		xQueueReceive(queue_handle, &packet, portMAX_DELAY);

		printf("got packet! %d %d %d\n", packet.type, packet.num, packet.state);
	}
}

#endif /* OUTPUTS_PRINTER_H_ */
