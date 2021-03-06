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
#define CONFIG_RETARGET_UART				HW_UART1

// system config
#define dg_configUSE_LP_CLK 				LP_CLK_RCX
#define dg_configEXEC_MODE 					MODE_IS_CACHED
#define dg_configCODE_LOCATION          	NON_VOLATILE_IS_FLASH
#define dg_configEXT_CRYSTAL_FREQ 			EXT_CRYSTAL_IS_16M

// storage config
#define dg_configFLASH_CONNECTED_TO 		(FLASH_CONNECTED_TO_1V8)
#define dg_configFLASH_POWER_DOWN 			(0)

#define dg_configPOWER_1V8_ACTIVE 			(1)
#define dg_configPOWER_1V8_SLEEP 			(1)

// free rtos config
#define OS_FREERTOS
#define configTOTAL_HEAP_SIZE 				14000

// disable default adapters
#define dg_configFLASH_ADAPTER          (0)
#define dg_configNVMS_ADAPTER           (0)
#define dg_configNVMS_VES               (0)
#define dg_configRF_ADAPTER             (0)
#define dg_configCRYPTO_ADAPTER         (0)

// scanner config
#define dg_configKEYBOARD_SCANNER_ADAPTER  (1)
#define dg_configUSE_HW_KEYBOARD_SCANNER   (1)
#define CONFIG_KEYBOARD_SCANNER_DEGHOSTING (0)
#define FS_USE_SCANNER                     (1)

// debug config
#define FS_USE_BLINKY  (1)
#define FS_USE_PRINTER (1)

// usb config
#define dg_configUSE_USB             (1)
#define dg_configUSE_HW_USB        	 (1)
#define dg_configUSE_USB_ENUMERATION (1)
#define USB_SUPPORT_HIGH_SPEED       (0)
#define FS_USE_USB                   (1)

#include "bsp_defaults.h"
#include "bsp_memory_layout.h"

#endif /* CONFIG_CUSTOM_CONFIG_QSPI_H_ */
