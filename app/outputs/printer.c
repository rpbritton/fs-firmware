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

#include "hw_gpio.h"

void printer_init()
{
#ifdef CONFIG_RETARGET
	hw_gpio_set_pin_function(HW_GPIO_PORT_1, HW_GPIO_PIN_3, HW_GPIO_MODE_OUTPUT,
	                         HW_GPIO_FUNC_UART_TX);
	hw_gpio_set_pin_function(HW_GPIO_PORT_2, HW_GPIO_PIN_3, HW_GPIO_MODE_INPUT,
	                         HW_GPIO_FUNC_UART_RX);
	extern void retarget_init(void);
	retarget_init();
#endif
}

void printer_run()
{
}

void printer_stop()
{
}

void printer_send(Packet packet)
{
	printf("got packet! %d %d %d\n", packet.spec.type, packet.spec.num,
	       packet.state);
}

#endif /* OUTPUTS_PRINTER_H_ */
