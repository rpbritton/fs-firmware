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

#include "layer.h"

#include "config.h"

typedef struct LayerState
{
	bool active :1;
} LayerState;

LayerState layer_states[FS_LAYER_NUM];

Layer layer_lookup(int depth)
{
	// todo: check layer states
	return 0;
}

void layer_send(Packet packet)
{
	// todo: update layer stack
}
