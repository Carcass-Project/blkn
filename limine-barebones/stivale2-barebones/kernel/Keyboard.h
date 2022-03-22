#include <stdint.h>
#include <stddef.h>


char buffer[4096]; // The Input Buffer.

enum VirKey
{
	VK_ESC,
	VK_1,
	VK_2,
	VK_3,
	VK_4,
	VK_5,
	VK_6,
	VK_7,
	VK_8,
	VK_9,
	VK_0,
	VK_F1,
	VK_F2,
	VK_F3,
	VK_F4,
	VK_F5,
	VK_F6,
	VK_F7,
	VK_F8,
	VK_F9,
	VK_F10,
	VK_F11,
	VK_F12,
	VK_PRINTSC,
	VK_SCROLL_LK,
	VK_PAUSE,
	VK_BACKTICK,
	VK_DASH,
	VK_EQUAL,
	VK_BACKSPACE,
	VK_INSERT,
	VK_HOME,
	VK_PAGE_UP,
	VK_PAGE_DOWN,
	VK_NUMLOCK,
	VK_NP_SLASH,
	VK_NP_ASTERISK,
	VK_NP_ENTER,
	VK_NP_DASH,
	VK_NP_PLUS,
	VK_TAB,
	VK_A = 0x1E,
	VK_B = 0x30,
	VK_C = 0x2E,
	VK_D = 0x20,
	VK_E = 0x12,
	VK_F = 0x21,
	VK_G = 0x22,
	VK_H = 0x23,
	VK_I = 0x17,
	VK_J = 0x24,
	VK_K = 0x25,
	VK_L = 0x26,
	VK_M = 0x32,
	VK_N = 0x31,
	VK_O = 0x18,
	VK_P = 0x19,
	VK_Q = 0x10,
	VK_R = 0x13,
	VK_S = 0x1F,
	VK_T = 0x14,
	VK_U = 0x16,
	VK_V = 0x2F,
	VK_W = 0x11,
	VK_X = 0x2D,
	VK_Y = 0x15,
	VK_Z = 0x2C,
	VK_OPEN_BRACK,
	VK_CLOSE_BRACK,
	VK_BACKSLASH,
	VK_PIPE,
	VK_DEL,
	VK_END,
	VK_NP1,
	VK_NP2,
	VK_NP3,
	VK_NP4,
	VK_NP5,
	VK_NP6,
	VK_NP7,
	VK_NP8,
	VK_NP9,
	VK_NP0,
	VK_SEMICOLON,
	VK_APOSTROPHE,
	VK_ENTER = 0x1C,
	VK_LSHIFT,
	VK_RSHIFT,
	VK_COMMA,
	VK_DOT = 0x34,
	VK_SLASH,
	VK_UP,
	VK_LEFT,
	VK_RIGHT,
	VK_DOWN,
	VK_LCTRL,
	VK_LLOGO,
	VK_LALT,
	VK_SPACE = 0x39,
	VK_RALT,
	VK_RLOGO,
	VK_CONMENU,
	VK_RCTRL,
	VK_NP_DOT,
	VK_SOFT_G,
	VK_UPPER_I,
	VK_SOFT_S, // ş
	VK_SOFT_C, // ç
	VK_SOFT_U, // ü
	VK_SOFT_O, // ö
	VK_QUOTE,
	VK_CAPSLOCK,
	VK_ASTERISK
};

void KeyboardHandler0(uint8_t key);