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

#ifndef COMMON_KEYCODES_SHORT_H_
#define COMMON_KEYCODES_SHORT_H_

enum KEYCODES_SHORT
{
	KB_RESERVED = 0x00,
	KB_ERR_ROLL_OVER,
	KB_POST_FAIL,
	KB_ERR_UNDEFINED,
	KB_A, // a and A
	KB_B, // b and B
	KB_C, // c and C
	KB_D, // d and D
	KB_E, // e and E
	KB_F, // f and F
	KB_G, // g and G
	KB_H, // h and H
	KB_I, // i and I
	KB_J, // j and J
	KB_K, // k and K
	KB_L, // l and L
	KB_M, // m and M
	KB_N, // n and N
	KB_O, // o and O
	KB_P, // p and P
	KB_Q, // q and Q
	KB_R, // r and R
	KB_S, // s and S
	KB_T, // t and T
	KB_U, // u and U
	KB_V, // v and V
	KB_W, // w and W
	KB_X, // x and X
	KB_Y, // y and Y
	KB_Z, // z and Z
	KB_1, // 1 and !
	KB_2, // 2 and @
	KB_3, // 3 and #
	KB_4, // 4 and $
	KB_5, // 5 and %
	KB_6, // 6 and ^
	KB_7, // 7 and &
	KB_8, // 8 and *
	KB_9, // 9 and (
	KB_0, // 0 and )
	KB_ENTER,
	KB_ESC,
	KB_BSPC,
	KB_TAB,
	KB_SPC,
	KB_DASH, // - and _
	KB_EQUAL, // = and +
	KB_LBRACKET, // [ and {
	KB_RBRACKET, // ] and }
	KB_BSLASH, // \ and |
	KB_NU_POUND, // Non-US # and ~
	KB_SCOLON, // ; and :
	KB_SQUOTE, // ' and "
	KB_GRAVE, // ` and ~
	KB_COMMA, // , and <
	KB_DOT, // . and >
	KB_FSLASH, // / and ?
	KB_CLCK,
	KB_F1,
	KB_F2,
	KB_F3,
	KB_F4,
	KB_F5,
	KB_F6,
	KB_F7,
	KB_F8,
	KB_F9,
	KB_F10,
	KB_F11,
	KB_F12,
	KB_PRTSC,
	KB_SLCK,
	KB_PAUSE,
	KB_INS,
	KB_HOME,
	KB_PGUP,
	KB_DEL,
	KB_END,
	KB_PGDN,
	KB_RIGHT,
	KB_LEFT,
	KB_DOWN,
	KB_UP,
	KB_NLOCK, // Num Lock and Clear
	KP_DIVIDE,
	KP_MULTIPLY,
	KP_MINUS,
	KP_PLUS,
	KP_ENTER,
	KP_1, // 1 and End
	KP_2, // 2 and Down Arrow
	KP_3, // 3 and PageDn
	KP_4, // 4 and Left Arrow
	KP_5,
	KP_6, // 6 and Right Arrow
	KP_7, // 7 and Home
	KP_8, // 8 and Up Arrow
	KP_9, // 9 and PageUp
	KP_0, // 0 and Insert
	KP_DOT, // . and Delete
	KB_NU_BSLASH, // Non-US \ and |
	KB_APPLICATION,
	KB_POWER,
	KP_EQUAL,
	KB_F13,
	KB_F14,
	KB_F15,
	KB_F16,
	KB_F17,
	KB_F18,
	KB_F19,
	KB_F20,
	KB_F21,
	KB_F22,
	KB_F23,
	KB_F24,
	KB_EXEC,
	KB_HELP,
	KB_MENU,
	KB_SELECT,
	KB_STOP,
	KB_AGAIN,
	KB_UNDO,
	KB_CUT,
	KB_COPY,
	KB_PASTE,
	KB_FIND,
	KB_MUTE,
	KB_VOLUP,
	KB_VOLDN,
	KB_LCKN_CLCK,
	KB_LCKN_NLCK,
	KB_LCKN_SLOCK,
	KP_COMMA,
	KP_EQUAL_SIGN,
	KB_INT1,
	KB_INT2,
	KB_INT3,
	KB_INT4,
	KB_INT5,
	KB_INT6,
	KB_INT7,
	KB_INT8,
	KB_INT9,
	KB_LANG1,
	KB_LANG2,
	KB_LANG3,
	KB_LANG4,
	KB_LANG5,
	KB_LANG6,
	KB_LANG7,
	KB_LANG8,
	KB_LANG9,
	KB_ALT_ERASE,
	KB_SYSREQ,
	KB_CANCEL,
	KB_CLR,
	KB_PRIOR,
	KB_RETURN,
	KB_SEPARATOR,
	KB_OUT,
	KB_OPER,
	KB_CLR_AGAIN,
	KB_CRSEL,
	KB_EXSEL,
	// 165-175: Reserved
	KP_00 = 0xB0,
	KP_000,
	KB_THOUSANDS_SEPARATOR,
	KB_DECIMAL_SEPARATOR,
	KB_CURRENCY_UNIT,
	KB_CURRENCY_SUB_UNIT,
	KP_LPAREN,
	KP_RPAREN,
	KP_LCBRACKET,
	KP_RCBRACKET,
	KP_TAB,
	KP_BACKSPACE,
	KP_A,
	KP_B,
	KP_C,
	KP_D,
	KP_E,
	KP_F,
	KP_XOR,
	KP_CARET,
	KP_PERCENT,
	KP_LESS_THAN,
	KP_GREATER_THAN,
	KP_AND,
	KP_DOUBLE_AND,
	KP_PIPE,
	KP_DOUBLE_PIPE,
	KP_COLON,
	KP_POUND,
	KP_SPACE,
	KP_AT,
	KP_EXCLAMATION,
	KP_MEM_STORE,
	KP_MEM_RECALL,
	KP_MEM_CLR,
	KP_MEM_ADD,
	KP_MEM_SUBTRACT,
	KP_MEM_MULTIPLY,
	KP_MEM_DIVIDE,
	KP_PLUS_MINUS,
	KP_CLR,
	KP_CLR_ENTRY,
	KP_BINARY,
	KP_OCTAL,
	KP_DECIMAL,
	KP_HEXADECIMAL,
	// 222-223: Reserved */
	KB_LCTRL = 0xE0,
	KB_LSHIFT,
	KB_LALT,
	KB_LGUI,
	KB_RCTRL,
	KB_RSHIFT,
	KB_RALT,
	KB_RGUI,
};

#endif /* COMMON_KEYCODES_SHORT_H_ */
