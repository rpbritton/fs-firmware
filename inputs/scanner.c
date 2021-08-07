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

#if FS_USE_SCANNER

#include "scanner.h"

#include "ad_keyboard_scanner.h"

#include "../common/packet.h"

static void scanner_cb(AD_KBSCN_EVENT event, char key);

static const uint8_t rows[FS_SCANNER_NUM_ROWS] = FS_SCANNER_ROWS;
static const uint8_t columns[FS_SCANNER_NUM_COLUMNS] = FS_SCANNER_COLUMNS;

static ad_kbscn_pin_setup kbscn_rows[FS_SCANNER_NUM_ROWS];
static ad_kbscn_pin_setup kbscn_columns[FS_SCANNER_NUM_COLUMNS];

static const char kbscn_matrix[FS_SCANNER_NUM_ROWS * FS_SCANNER_NUM_COLUMNS] =
FS_SCANNER_EVENTS;

static const ad_kbscn_config kbscn_config = {
    .num_rows = FS_SCANNER_NUM_ROWS,
    .rows = kbscn_rows,
    .num_columns = FS_SCANNER_NUM_COLUMNS,
    .columns = kbscn_columns,
    .key_matrix = kbscn_matrix,
    .clock_div = AD_KBSCN_CLOCK_DIV_16,
    .row_scan_time = 150,
    .debounce_press_time = 10,
    .debounce_release_time = 10,
    .inactive_time = 1,
    .cb = scanner_cb,
};

static QueueHandle_t queue_handle = NULL;

void scanner_init(QueueHandle_t router_queue)
{
	// parse rows
	for (int index = 0; index < FS_SCANNER_NUM_ROWS; index++)
	{
		kbscn_rows[index].in_use = true;
		kbscn_rows[index].port = (rows[index] >> 4);
		kbscn_rows[index].pin = (rows[index] & 0x0F);
	}

	// parse columns
	for (int index = 0; index < FS_SCANNER_NUM_COLUMNS; index++)
	{
		kbscn_columns[index].in_use = true;
		kbscn_columns[index].port = (columns[index] >> 4);
		kbscn_columns[index].pin = (columns[index] & 0x0F);
	}
}

void scanner_run()
{
	// todo: should this be in "init"?
	ad_kbscn_init(&kbscn_config);
}

void scanner_stop()
{
	ad_kbscn_cleanup();
}

void scanner_route(QueueHandle_t queue)
{
	queue_handle = queue;
}

static void scanner_cb(AD_KBSCN_EVENT event, char key)
{
	Packet packet = {
	    .type = PACKET_EVENT,
	    .num = (uint8_t) key,
	    .state = (event == AD_KBSCN_EVENT_PRESSED) ? PACKET_ON : PACKET_OFF,
	};
	xQueueSendFromISR(queue_handle, &packet, NULL);
}

#endif /* FS_USE_SCANNER */
