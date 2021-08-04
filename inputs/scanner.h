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

#ifndef INPUTS_SCANNER_H_
#define INPUTS_SCANNER_H_

#include "osal.h"

typedef struct ScannerConfig
{
	const uint8_t num_columns;
	const uint8_t *columns;
	const uint8_t num_rows;
	const uint8_t *rows;
	const uint8_t *events;
} ScannerConfig;

void scanner_init(const ScannerConfig *config);
void scanner_run();
void scanner_stop();

#endif /* INPUTS_SCANNER_H_ */
