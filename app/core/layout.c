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

#include "layout.h"

#include "config.h"

typedef struct EventState
{
	bool on :1;
	Packet packet;
} EventState;

typedef struct LayerState
{
	bool on :1;
} LayerState;

const PacketSpec layout_spec[FS_LAYOUT_LAYERS][FS_LAYOUT_EVENTS] =
FS_LAYOUT_SPEC;

LayerState layer_state[FS_LAYOUT_LAYERS];
EventState event_state[FS_LAYOUT_EVENTS];

void layout_init()
{
	for (int index = 0; index < FS_LAYOUT_LAYERS; index++)
		layer_state[index].on = false;
	for (int index = 0; index < FS_LAYOUT_EVENTS; index++)
		event_state[index].on = false;
}

void layout_run()
{
}

void layout_stop()
{
}

void layout_send(Packet packet)
{

}
