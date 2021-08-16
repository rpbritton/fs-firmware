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
#include "core/router.h"
#include "core/layer.h"

const PacketSpec layout_spec[FS_LAYER_NUM][FS_EVENT_NUM] =
FS_LAYOUT_SPEC;

PacketSpec layout_lookup(Event event)
{

	Layer layer = layer_lookup(0);
	// todo: check for layout packets (fallthrough, none)
	return layout_spec[layer][event];
}
