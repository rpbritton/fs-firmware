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

#include "scanner.h"

#include <stdio.h>

#include "ad_keyboard_scanner.h"

static void scanner_cb(AD_KBSCN_EVENT event, char key);

static ad_kbscn_config kbscn;

void scanner_init(const ScannerConfig *config)
{
	// parse rows
	kbscn.num_rows = config->num_rows;
	ad_kbscn_pin_setup *rows = pvPortMalloc(
			sizeof(ad_kbscn_pin_setup) * kbscn.num_rows);
	for (int index = 0; index < kbscn.num_rows; index++)
	{
		rows[index].in_use = true;
		rows[index].port = (config->rows[index] >> 4);
		rows[index].pin = (config->rows[index] & 0x0F);
	}
	kbscn.rows = rows;

	// parse columns
	kbscn.num_columns = config->num_columns;
	ad_kbscn_pin_setup *columns = pvPortMalloc(
			sizeof(ad_kbscn_pin_setup) * kbscn.num_columns);
	for (int index = 0; index < kbscn.num_columns; index++)
	{
		columns[index].in_use = true;
		columns[index].port = (config->columns[index] >> 4);
		columns[index].pin = (config->columns[index] & 0x0F);
	}
	kbscn.columns = columns;

	// parse events
	char *key_matrix = pvPortMalloc(kbscn.num_rows * kbscn.num_columns);
	for (int event = 0; event < kbscn.num_rows * kbscn.num_columns; event++)
		key_matrix[event] = (char) config->events[event];
	kbscn.key_matrix = key_matrix;

	// other settings
	kbscn.clock_div = AD_KBSCN_CLOCK_DIV_16;
	kbscn.row_scan_time = 150;
	kbscn.debounce_press_time = 10;
	kbscn.debounce_release_time = 10;
	kbscn.inactive_time = 1;
	kbscn.cb = scanner_cb;
}

void scanner_run()
{
	ad_kbscn_init(&kbscn);
}

void scanner_stop()
{
	ad_kbscn_cleanup();
}

static void scanner_cb(AD_KBSCN_EVENT event, char key)
{
	printf("yay got event %d and key %d\n", event, (uint8_t) key);
}
