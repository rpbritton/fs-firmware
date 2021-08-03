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

#include "blinky.h"

#include "osal.h"
#include "hw_led.h"
#include "hw_breath.h"

static void blinky_task(void *data);

static TaskHandle_t blinky_handle;

void blinky_init()
{
	breath_config config =
	{ .dc_min = 239, .dc_max = 240, .dc_step = 1, .freq_div = 255, .polarity =
			HW_BREATH_PWM_POL_POS };

	hw_breath_init(&config);

	hw_led_set_led2_src(HW_LED_SRC2_BREATH);
	hw_led_set_led3_src(HW_LED_SRC3_BREATH);
	hw_led_enable_led2(true);
	hw_led_enable_led3(true);
}

void blinky_run()
{
	if (blinky_handle)
		return;

	xTaskCreate(blinky_task, "print_task",
			configMINIMAL_STACK_SIZE * sizeof(StackType_t), NULL, 1,
			&blinky_handle);
}

void blinky_stop()
{
	if (!blinky_handle)
		return;

	vTaskDelete(blinky_handle);
	blinky_handle = NULL;
}

static void blinky_task(void *data)
{
	int counter = 0;
	TickType_t next_wake = xTaskGetTickCount();
	while (true)
	{
		vTaskDelayUntil(&next_wake, portCONVERT_MS_2_TICKS(500));

		if (counter++ % 2)
			hw_breath_enable();
		else
			hw_breath_disable();
	}
}
