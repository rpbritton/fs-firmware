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

#include "event.h"

#include "config.h"
#include "core/layout.h"
#include "core/router.h"

typedef struct EventState
{
	bool active :1;
	Packet packet;
} EventState;

EventState event_states[FS_EVENT_NUM];

void event_send(Packet packet)
{
	// todo: update event states
	Packet packet_lookup = {
	    .spec = layout_lookup(packet.spec.num),
	    .state = packet.state,
	};
	router_send(packet_lookup);
}
