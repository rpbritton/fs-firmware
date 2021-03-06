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

#ifndef COMMON_PACKET_H_
#define COMMON_PACKET_H_

#include "osal.h"

typedef enum PacketType
{
	PACKET_LAYOUT,
	PACKET_EVENT,
	PACKET_KEYBOARD,
	PACKET_MOUSE,
	PACKET_CONSUMER,
	PACKET_LAYER,
	PACKET_TYPE_TOTAL,

	PACKET_TYPE_MAX = 0xFF,
} PacketType;

typedef struct PacketSpec
{
	PacketType type :8;
	uint8_t num :8;
} PacketSpec;

typedef enum PacketState
{
	PACKET_OFF = false,
	PACKET_ON = true,
} PacketState;

typedef struct Packet
{
	PacketSpec spec;
	PacketState state :1;
} Packet;

#endif /* COMMON_PACKET_H_ */
