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

#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

// scanner config
#ifdef FS_USE_SCANNER
#define FS_SCANNER_NUM_ROWS    (3)
#define FS_SCANNER_NUM_COLUMNS (3)
#define FS_SCANNER_ROWS        {0x34, 0x33, 0x45}
#define FS_SCANNER_COLUMNS     {0x47, 0x30, 0x46}
#define FS_SCANNER_EVENTS      {0, 1, 2, 3, 4, 5, 6, 7, 8}
#endif

// layout config
#include "common/layout.h"
#define FS_LAYER_NUM (2)
#define FS_EVENT_NUM (9)
#define FS_LAYOUT_SPEC {                               \
	{                                                  \
		KB_A, KB_B, KB_C,                              \
		KB_D, KB_E, KB_F,                              \
		{.type = PACKET_LAYER, .num = 1}, KB_H, KB_I,  \
	},	{                                              \
		KB_1, KB_2, KB_3,                              \
		KB_4, KB_5, KB_6,                              \
		{.type = PACKET_LAYER, .num = 1}, KB_8, _____, \
	},                                                 \
}

#endif /* APP_CONFIG_H_ */
