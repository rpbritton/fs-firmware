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

#ifndef CONFIG_CUSTOM_CONFIG_QSPI_H_
#define CONFIG_CUSTOM_CONFIG_QSPI_H_

#include "bsp_definitions.h"

// retarget printf to uart1
#define CONFIG_RETARGET
#define CONFIG_RETARGET_UART			HW_UART1

// system config
#define dg_configUSE_LP_CLK 			LP_CLK_RCX
#define dg_configEXEC_MODE 				MODE_IS_CACHED
#define dg_configCODE_LOCATION          NON_VOLATILE_IS_FLASH
#define dg_configEXT_CRYSTAL_FREQ 		EXT_CRYSTAL_IS_16M

// storage config
#define dg_configFLASH_CONNECTED_TO 	(FLASH_CONNECTED_TO_1V8)
#define dg_configFLASH_POWER_DOWN 		(0)

#define dg_configPOWER_1V8_ACTIVE 		(1)
#define dg_configPOWER_1V8_SLEEP 		(1)

// free rtos config
#define OS_FREERTOS
#define configTOTAL_HEAP_SIZE 			14000

// hardware adapter config
#define dg_configFLASH_ADAPTER 			(0)
#define dg_configNVMS_ADAPTER			(0)
#define dg_configNVMS_VES 				(0)
#define dg_configRF_ADAPTER 			(0)
#define dg_configCRYPTO_ADAPTER 		(0)

#include "bsp_defaults.h"
#include "bsp_memory_layout.h"

#endif /* CONFIG_CUSTOM_CONFIG_QSPI_H_ */
