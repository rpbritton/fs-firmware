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

#include "layers.h"

#include "config.h"
#include "core/events.h"

typedef struct LayerState
{
	uint8_t activations;
} LayerState;

static struct
{
	LayerState states[FS_LAYER_NUM];
	Layer active;
} layers;

void layers_refresh()
{
	Layer new_active_layer = 0;
	for (Layer layer = FS_LAYER_NUM - 1; layer > 0; layer--)
	{
		if (layers.states[layer].activations > 0)
		{
			new_active_layer = layer;
			break;
		}
	}

	if (new_active_layer == layers.active)
		return;

	layers.active = new_active_layer;
	events_refresh();
}

Layer layers_lookup()
{
	return layers.active;
}

void layers_send(Packet packet)
{
	Layer layer = packet.spec.num;
	if (layer >= FS_LAYER_NUM)
		return;

	if (packet.state == PACKET_ON)
	{
		// increase the activations
		layers.states[layer].activations++;

		// reevaluate active layer
		if (layer > layers.active)
			layers_refresh();
	}
	else
	{
		// decrease the activations
		if (layers.states[layer].activations == 0)
			return;
		layers.states[layer].activations--;

		// reevaluate active layer
		if (layer == layers.active && layers.states[layer].activations == 0)
			layers_refresh();
	}
}
