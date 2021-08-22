/**
 #include <app/inputs/scanner.h>
 #include <app/outputs/blinky.h>
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

#include "osal.h"
#include "resmgmt.h"
#include "sys_clock_mgr.h"
#include "sys_power_mgr.h"
#include "hw_gpio.h"

#include "app/app.h"

static void system_init(void *data);

int main(void)
{
	cm_clk_init_low_level();

	TaskHandle_t handle;
	xTaskCreate(system_init, "system_init",
	            configMINIMAL_STACK_SIZE,
	            NULL,
	            configMAX_PRIORITIES - 1,
	            &handle);

	vTaskStartScheduler();
}

static void system_init(void *data)
{
	cm_sys_clk_init(sysclk_PLL96);
	cm_apb_set_clock_divider(apb_div1);
	cm_ahb_set_clock_divider(ahb_div1);
	cm_lp_clk_init();

	pm_system_init(NULL);
	app_init();

	resource_init();

	app_run();

	vTaskDelete(NULL);
}

void vApplicationMallocFailedHook(void)
{
}

void vApplicationIdleHook()
{
}

void vApplicationStackOverflowHook(TaskHandle_t task, char *task_name)
{
	(void) task;
	(void) task_name;
}
