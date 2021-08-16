/*----------------------------------------------------------------------------*
 * Copyright 2018 Ryan Britton
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License.  You may obtain a copy
 * of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations under
 * the License.
 *----------------------------------------------------------------------------*/

#ifndef COMMON_HIDCODES_H_
#define COMMON_HIDCODES_H_

#include "packet.h"

// HID Keyboard and Keypad Page (0x07)
#define KB_RESERVED { .type = PACKET_HID, .num = 0x00 }
#define KB_ERR_ROLL_OVER { .type = PACKET_HID, .num = 0x01 }
#define KB_POST_FAIL { .type = PACKET_HID, .num = 0x02 }
#define KB_ERR_UNDEFINED { .type = PACKET_HID, .num = 0x03 }
#define KB_A { .type = PACKET_HID, .num = 0x04 } // a and A
#define KB_B { .type = PACKET_HID, .num = 0x05 } // b and B
#define KB_C { .type = PACKET_HID, .num = 0x06 } // c and C
#define KB_D { .type = PACKET_HID, .num = 0x07 } // d and D
#define KB_E { .type = PACKET_HID, .num = 0x08 } // e and E
#define KB_F { .type = PACKET_HID, .num = 0x09 } // f and F
#define KB_G { .type = PACKET_HID, .num = 0x0a } // g and G
#define KB_H { .type = PACKET_HID, .num = 0x0b } // h and H
#define KB_I { .type = PACKET_HID, .num = 0x0c } // i and I
#define KB_J { .type = PACKET_HID, .num = 0x0d } // j and J
#define KB_K { .type = PACKET_HID, .num = 0x0e } // k and K
#define KB_L { .type = PACKET_HID, .num = 0x0f } // l and L
#define KB_M { .type = PACKET_HID, .num = 0x10 } // m and M
#define KB_N { .type = PACKET_HID, .num = 0x11 } // n and N
#define KB_O { .type = PACKET_HID, .num = 0x12 } // o and O
#define KB_P { .type = PACKET_HID, .num = 0x13 } // p and P
#define KB_Q { .type = PACKET_HID, .num = 0x14 } // q and Q
#define KB_R { .type = PACKET_HID, .num = 0x15 } // r and R
#define KB_S { .type = PACKET_HID, .num = 0x16 } // s and S
#define KB_T { .type = PACKET_HID, .num = 0x17 } // t and T
#define KB_U { .type = PACKET_HID, .num = 0x18 } // u and U
#define KB_V { .type = PACKET_HID, .num = 0x19 } // v and V
#define KB_W { .type = PACKET_HID, .num = 0x1a } // w and W
#define KB_X { .type = PACKET_HID, .num = 0x1b } // x and X
#define KB_Y { .type = PACKET_HID, .num = 0x1c } // y and Y
#define KB_Z { .type = PACKET_HID, .num = 0x1d } // z and Z
#define KB_1 { .type = PACKET_HID, .num = 0x1e } // 1 and !
#define KB_2 { .type = PACKET_HID, .num = 0x1f } // 2 and @
#define KB_3 { .type = PACKET_HID, .num = 0x20 } // 3 and #
#define KB_4 { .type = PACKET_HID, .num = 0x21 } // 4 and $
#define KB_5 { .type = PACKET_HID, .num = 0x22 } // 5 and %
#define KB_6 { .type = PACKET_HID, .num = 0x23 } // 6 and ^
#define KB_7 { .type = PACKET_HID, .num = 0x24 } // 7 and &
#define KB_8 { .type = PACKET_HID, .num = 0x25 } // 8 and *
#define KB_9 { .type = PACKET_HID, .num = 0x26 } // 9 and (
#define KB_0 { .type = PACKET_HID, .num = 0x27 } // 0 and )
#define KB_ENTER { .type = PACKET_HID, .num = 0x28 }
#define KB_ESC { .type = PACKET_HID, .num = 0x29 }
#define KB_BSPC { .type = PACKET_HID, .num = 0x2a }
#define KB_TAB { .type = PACKET_HID, .num = 0x2b }
#define KB_SPC { .type = PACKET_HID, .num = 0x2c }
#define KB_DASH { .type = PACKET_HID, .num = 0x2d }     // - and _
#define KB_EQUAL { .type = PACKET_HID, .num = 0x2e }    // = and +
#define KB_LBRACKET { .type = PACKET_HID, .num = 0x2f } // [ and {
#define KB_RBRACKET { .type = PACKET_HID, .num = 0x30 } // ] and }
#define KB_BSLASH { .type = PACKET_HID, .num = 0x31 }   // \ and |
#define KB_NU_POUND { .type = PACKET_HID, .num = 0x32 } // Non-US # and ~
#define KB_SCOLON { .type = PACKET_HID, .num = 0x33 }   // ; and :
#define KB_SQUOTE { .type = PACKET_HID, .num = 0x34 }   // ' and "
#define KB_GRAVE { .type = PACKET_HID, .num = 0x35 }    // ` and ~
#define KB_COMMA { .type = PACKET_HID, .num = 0x36 }    // , and <
#define KB_DOT { .type = PACKET_HID, .num = 0x37 }      // . and >
#define KB_FSLASH { .type = PACKET_HID, .num = 0x38 }   // / and ?
#define KB_CLCK { .type = PACKET_HID, .num = 0x39 }
#define KB_F1 { .type = PACKET_HID, .num = 0x3a }
#define KB_F2 { .type = PACKET_HID, .num = 0x3b }
#define KB_F3 { .type = PACKET_HID, .num = 0x3c }
#define KB_F4 { .type = PACKET_HID, .num = 0x3d }
#define KB_F5 { .type = PACKET_HID, .num = 0x3e }
#define KB_F6 { .type = PACKET_HID, .num = 0x3f }
#define KB_F7 { .type = PACKET_HID, .num = 0x40 }
#define KB_F8 { .type = PACKET_HID, .num = 0x41 }
#define KB_F9 { .type = PACKET_HID, .num = 0x42 }
#define KB_F10 { .type = PACKET_HID, .num = 0x43 }
#define KB_F11 { .type = PACKET_HID, .num = 0x44 }
#define KB_F12 { .type = PACKET_HID, .num = 0x45 }
#define KB_PRTSC { .type = PACKET_HID, .num = 0x46 }
#define KB_SLCK { .type = PACKET_HID, .num = 0x47 }
#define KB_PAUSE { .type = PACKET_HID, .num = 0x48 }
#define KB_INS { .type = PACKET_HID, .num = 0x49 }
#define KB_HOME { .type = PACKET_HID, .num = 0x4a }
#define KB_PGUP { .type = PACKET_HID, .num = 0x4b }
#define KB_DEL { .type = PACKET_HID, .num = 0x4c }
#define KB_END { .type = PACKET_HID, .num = 0x4d }
#define KB_PGDN { .type = PACKET_HID, .num = 0x4e }
#define KB_RIGHT { .type = PACKET_HID, .num = 0x4f }
#define KB_LEFT { .type = PACKET_HID, .num = 0x50 }
#define KB_DOWN { .type = PACKET_HID, .num = 0x51 }
#define KB_UP { .type = PACKET_HID, .num = 0x52 }
#define KB_NLOCK { .type = PACKET_HID, .num = 0x53 } // Num Lock and Clear
#define KP_DIVIDE { .type = PACKET_HID, .num = 0x54 }
#define KP_MULTIPLY { .type = PACKET_HID, .num = 0x55 }
#define KP_MINUS { .type = PACKET_HID, .num = 0x56 }
#define KP_PLUS { .type = PACKET_HID, .num = 0x57 }
#define KP_ENTER { .type = PACKET_HID, .num = 0x58 }
#define KP_1 { .type = PACKET_HID, .num = 0x59 } // 1 and End
#define KP_2 { .type = PACKET_HID, .num = 0x5a } // 2 and Down Arrow
#define KP_3 { .type = PACKET_HID, .num = 0x5b } // 3 and PageDn
#define KP_4 { .type = PACKET_HID, .num = 0x5c } // 4 and Left Arrow
#define KP_5 { .type = PACKET_HID, .num = 0x5d }
#define KP_6 { .type = PACKET_HID, .num = 0x5e }         // 6 and Right Arrow
#define KP_7 { .type = PACKET_HID, .num = 0x5f }         // 7 and Home
#define KP_8 { .type = PACKET_HID, .num = 0x60 }         // 8 and Up Arrow
#define KP_9 { .type = PACKET_HID, .num = 0x61 }         // 9 and PageUp
#define KP_0 { .type = PACKET_HID, .num = 0x62 }         // 0 and Insert
#define KP_DOT { .type = PACKET_HID, .num = 0x63 }       // . and Delete
#define KB_NU_BSLASH { .type = PACKET_HID, .num = 0x64 } // Non-US \ and |
#define KB_APPLICATION { .type = PACKET_HID, .num = 0x65 }
#define KB_POWER { .type = PACKET_HID, .num = 0x66 }
#define KP_EQUAL { .type = PACKET_HID, .num = 0x67 }
#define KB_F13 { .type = PACKET_HID, .num = 0x68 }
#define KB_F14 { .type = PACKET_HID, .num = 0x69 }
#define KB_F15 { .type = PACKET_HID, .num = 0x6a }
#define KB_F16 { .type = PACKET_HID, .num = 0x6b }
#define KB_F17 { .type = PACKET_HID, .num = 0x6c }
#define KB_F18 { .type = PACKET_HID, .num = 0x6d }
#define KB_F19 { .type = PACKET_HID, .num = 0x6e }
#define KB_F20 { .type = PACKET_HID, .num = 0x6f }
#define KB_F21 { .type = PACKET_HID, .num = 0x70 }
#define KB_F22 { .type = PACKET_HID, .num = 0x71 }
#define KB_F23 { .type = PACKET_HID, .num = 0x72 }
#define KB_F24 { .type = PACKET_HID, .num = 0x73 }
#define KB_EXEC { .type = PACKET_HID, .num = 0x74 }
#define KB_HELP { .type = PACKET_HID, .num = 0x75 }
#define KB_MENU { .type = PACKET_HID, .num = 0x76 }
#define KB_SELECT { .type = PACKET_HID, .num = 0x77 }
#define KB_STOP { .type = PACKET_HID, .num = 0x78 }
#define KB_AGAIN { .type = PACKET_HID, .num = 0x79 }
#define KB_UNDO { .type = PACKET_HID, .num = 0x7a }
#define KB_CUT { .type = PACKET_HID, .num = 0x7b }
#define KB_COPY { .type = PACKET_HID, .num = 0x7c }
#define KB_PASTE { .type = PACKET_HID, .num = 0x7d }
#define KB_FIND { .type = PACKET_HID, .num = 0x7e }
#define KB_MUTE { .type = PACKET_HID, .num = 0x7f }
#define KB_VOLUP { .type = PACKET_HID, .num = 0x80 }
#define KB_VOLDN { .type = PACKET_HID, .num = 0x81 }
#define KB_LCKN_CLCK { .type = PACKET_HID, .num = 0x82 }
#define KB_LCKN_NLCK { .type = PACKET_HID, .num = 0x83 }
#define KB_LCKN_SLOCK { .type = PACKET_HID, .num = 0x84 }
#define KP_COMMA { .type = PACKET_HID, .num = 0x85 }
#define KP_EQUAL_SIGN { .type = PACKET_HID, .num = 0x86 }
#define KB_INT1 { .type = PACKET_HID, .num = 0x87 }
#define KB_INT2 { .type = PACKET_HID, .num = 0x88 }
#define KB_INT3 { .type = PACKET_HID, .num = 0x89 }
#define KB_INT4 { .type = PACKET_HID, .num = 0x8a }
#define KB_INT5 { .type = PACKET_HID, .num = 0x8b }
#define KB_INT6 { .type = PACKET_HID, .num = 0x8c }
#define KB_INT7 { .type = PACKET_HID, .num = 0x8d }
#define KB_INT8 { .type = PACKET_HID, .num = 0x8e }
#define KB_INT9 { .type = PACKET_HID, .num = 0x8f }
#define KB_LANG1 { .type = PACKET_HID, .num = 0x90 }
#define KB_LANG2 { .type = PACKET_HID, .num = 0x91 }
#define KB_LANG3 { .type = PACKET_HID, .num = 0x92 }
#define KB_LANG4 { .type = PACKET_HID, .num = 0x93 }
#define KB_LANG5 { .type = PACKET_HID, .num = 0x94 }
#define KB_LANG6 { .type = PACKET_HID, .num = 0x95 }
#define KB_LANG7 { .type = PACKET_HID, .num = 0x96 }
#define KB_LANG8 { .type = PACKET_HID, .num = 0x97 }
#define KB_LANG9 { .type = PACKET_HID, .num = 0x98 }
#define KB_ALT_ERASE { .type = PACKET_HID, .num = 0x99 }
#define KB_SYSREQ { .type = PACKET_HID, .num = 0x9a }
#define KB_CANCEL { .type = PACKET_HID, .num = 0x9b }
#define KB_CLR { .type = PACKET_HID, .num = 0x9c }
#define KB_PRIOR { .type = PACKET_HID, .num = 0x9d }
#define KB_RETURN { .type = PACKET_HID, .num = 0x9e }
#define KB_SEPARATOR { .type = PACKET_HID, .num = 0x9f }
#define KB_OUT { .type = PACKET_HID, .num = 0xa0 }
#define KB_OPER { .type = PACKET_HID, .num = 0xa1 }
#define KB_CLR_AGAIN { .type = PACKET_HID, .num = 0xa2 }
#define KB_CRSEL { .type = PACKET_HID, .num = 0xa3 }
#define KB_EXSEL { .type = PACKET_HID, .num = 0xa4 }
#define KP_00 { .type = PACKET_HID, .num = 0xb0 }
#define KP_000 { .type = PACKET_HID, .num = 0xb1 }
#define KB_THOUSANDS_SEPARATOR { .type = PACKET_HID, .num = 0xb2 }
#define KB_DECIMAL_SEPARATOR { .type = PACKET_HID, .num = 0xb3 }
#define KB_CURRENCY_UNIT { .type = PACKET_HID, .num = 0xb4 }
#define KB_CURRENCY_SUB_UNIT { .type = PACKET_HID, .num = 0xb5 }
#define KP_LPAREN { .type = PACKET_HID, .num = 0xb6 }
#define KP_RPAREN { .type = PACKET_HID, .num = 0xb7 }
#define KP_LCBRACKET { .type = PACKET_HID, .num = 0xb8 }
#define KP_RCBRACKET { .type = PACKET_HID, .num = 0xb9 }
#define KP_TAB { .type = PACKET_HID, .num = 0xba }
#define KP_BACKSPACE { .type = PACKET_HID, .num = 0xbb }
#define KP_A { .type = PACKET_HID, .num = 0xbc }
#define KP_B { .type = PACKET_HID, .num = 0xbd }
#define KP_C { .type = PACKET_HID, .num = 0xbe }
#define KP_D { .type = PACKET_HID, .num = 0xbf }
#define KP_E { .type = PACKET_HID, .num = 0xc0 }
#define KP_F { .type = PACKET_HID, .num = 0xc1 }
#define KP_XOR { .type = PACKET_HID, .num = 0xc2 }
#define KP_CARET { .type = PACKET_HID, .num = 0xc3 }
#define KP_PERCENT { .type = PACKET_HID, .num = 0xc4 }
#define KP_LESS_THAN { .type = PACKET_HID, .num = 0xc5 }
#define KP_GREATER_THAN { .type = PACKET_HID, .num = 0xc6 }
#define KP_AND { .type = PACKET_HID, .num = 0xc7 }
#define KP_DOUBLE_AND { .type = PACKET_HID, .num = 0xc8 }
#define KP_PIPE { .type = PACKET_HID, .num = 0xc9 }
#define KP_DOUBLE_PIPE { .type = PACKET_HID, .num = 0xca }
#define KP_COLON { .type = PACKET_HID, .num = 0xcb }
#define KP_POUND { .type = PACKET_HID, .num = 0xcc }
#define KP_SPACE { .type = PACKET_HID, .num = 0xcd }
#define KP_AT { .type = PACKET_HID, .num = 0xce }
#define KP_EXCLAMATION { .type = PACKET_HID, .num = 0xcf }
#define KP_MEM_STORE { .type = PACKET_HID, .num = 0xd0 }
#define KP_MEM_RECALL { .type = PACKET_HID, .num = 0xd1 }
#define KP_MEM_CLR { .type = PACKET_HID, .num = 0xd2 }
#define KP_MEM_ADD { .type = PACKET_HID, .num = 0xd3 }
#define KP_MEM_SUBTRACT { .type = PACKET_HID, .num = 0xd4 }
#define KP_MEM_MULTIPLY { .type = PACKET_HID, .num = 0xd5 }
#define KP_MEM_DIVIDE { .type = PACKET_HID, .num = 0xd6 }
#define KP_PLUS_MINUS { .type = PACKET_HID, .num = 0xd7 }
#define KP_CLR { .type = PACKET_HID, .num = 0xd8 }
#define KP_CLR_ENTRY { .type = PACKET_HID, .num = 0xd9 }
#define KP_BINARY { .type = PACKET_HID, .num = 0xda }
#define KP_OCTAL { .type = PACKET_HID, .num = 0xdb }
#define KP_DECIMAL { .type = PACKET_HID, .num = 0xdc }
#define KP_HEXADECIMAL { .type = PACKET_HID, .num = 0xdd }
#define KB_LCTRL { .type = PACKET_HID, .num = 0xe0 }
#define KB_LSHIFT { .type = PACKET_HID, .num = 0xe1 }
#define KB_LALT { .type = PACKET_HID, .num = 0xe2 }
#define KB_LGUI { .type = PACKET_HID, .num = 0xe3 }
#define KB_RCTRL { .type = PACKET_HID, .num = 0xe4 }
#define KB_RSHIFT { .type = PACKET_HID, .num = 0xe5 }
#define KB_RALT { .type = PACKET_HID, .num = 0xe6 }
#define KB_RGUI { .type = PACKET_HID, .num = 0xe7 }

// HID Consumer Page (0x0c)
// todo

#endif /* COMMON_HIDCODES_H_ */
