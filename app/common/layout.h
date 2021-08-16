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

#ifndef COMMON_LAYOUT_H_
#define COMMON_LAYOUT_H_

#include "hidcodes.h"
#include "packet.h"

// todo: can these files be better organized?

// todo: can you fit an enum to determine the numbers? maybe LAYOUT_NONE_NUM
#define LAYOUT_NONE { .type = PACKET_LAYOUT, .num = 0x00 }
#define _XXX_ LAYOUT_NONE

#define LAYOUT_FALLTHROUGH { .type = PACKET_LAYOUT, .num = 0x01 }
#define _____ LAYOUT_FALLTHROUGH

#endif /* COMMON_LAYOUT_H_ */