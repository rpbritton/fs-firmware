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

#include "core/event.h"

typedef struct LayerState
{
	uint8_t activations;
} LayerState;

LayerState layer_states[FS_LAYER_NUM];
Layer active_layer = 0;

void layer_refresh()
{
	Layer new_active_layer = 0;
	for (Layer layer = FS_LAYER_NUM; layer > 0; layer--)
	{
		if (layer_states[layer].activations > 0)
		{
			new_active_layer = layer;
			break;
		}
	}

	if (new_active_layer == active_layer)
		return;

	active_layer = new_active_layer;
	event_refresh();
}

Layer layer_lookup()
{
	return active_layer;
}

void layer_send(Packet packet)
{
	Layer layer = packet.spec.num;
	if (layer >= FS_LAYER_NUM)
		return;

	if (packet.state == PACKET_ON)
	{
		// increase the activations
		layer_states[layer].activations++;

		// reevaluate active layer
		if (layer > active_layer)
			layer_refresh();
	}
	else
	{
		// decrease the activations
		if (layer_states[layer].activations == 0)
			return;
		layer_states[layer].activations--;

		// reevaluate active layer
		if (layer == active_layer && layer_states[layer].activations == 0)
			layer_refresh();
	}
}
