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

#ifndef CONFIG_H_
#define CONFIG_H_

#include "inputs/scanner.h"

// scanner config
#define SCANNER_NUM_ROWS 3
#define SCANNER_NUM_COLUMNS 3
const uint8_t SCANNER_ROWS[SCANNER_NUM_ROWS] =
{ 0x34, 0x33, 0x45 };
const uint8_t SCANNER_COLUMNS[SCANNER_NUM_COLUMNS] =
{ 0x47, 0x30, 0x46 };
const uint8_t SCANNER_EVENTS[SCANNER_NUM_ROWS * SCANNER_NUM_COLUMNS] =
{ 0, 1, 2, 3, 4, 5, 6, 7, 8 };
const ScannerConfig SCANNER_CONFIG =
{ .num_rows = SCANNER_NUM_ROWS, .rows = SCANNER_ROWS, .num_columns =
SCANNER_NUM_COLUMNS, .columns = SCANNER_COLUMNS, .events = SCANNER_EVENTS, };

#endif /* CONFIG_H_ */
