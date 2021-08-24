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

#include "events.h"

#include "config.h"
#include "core/layout.h"
#include "core/router.h"

typedef struct EventState
{
	bool active;
	PacketSpec spec;
} EventState;

static struct
{
	EventState states[FS_EVENT_NUM];
} events;

void events_send(Packet packet)
{
	Event event = packet.spec.num;
	if (event > FS_EVENT_NUM)
		return;

	// save the event state
	if (packet.state == PACKET_ON)
	{
		if (events.states[event].active)
			return;

		events.states[event].active = true;
		events.states[event].spec = layout_lookup(event);
	}
	else
	{
		if (!events.states[event].active)
			return;

		events.states[event].active = false;
	}

	// send the event's command to the router
	packet.spec = events.states[event].spec;
	router_send(packet);
}

void events_refresh()
{
	for (Event event = 0; event < FS_EVENT_NUM; event++)
	{
		if (!events.states[event].active)
			continue;

		PacketSpec old_packet_spec = events.states[event].spec;
		PacketSpec new_packet_spec = layout_lookup(event);

		if (new_packet_spec.type == old_packet_spec.type &&
		    new_packet_spec.num == old_packet_spec.num)
			continue;

		events.states[event].spec = new_packet_spec;

		// todo: send to front?
		Packet old_packet = { .state = PACKET_OFF, .spec = old_packet_spec };
		router_send(old_packet);

		Packet new_packet = { .state = PACKET_ON, .spec = new_packet_spec };
		router_send(new_packet);
	}
}
