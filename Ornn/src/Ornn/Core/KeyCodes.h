#pragma once

namespace Ornn {
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define ORNN_KEY_SPACE           ::Ornn::Key::Space
#define ORNN_KEY_APOSTROPHE      ::Ornn::Key::Apostrophe    /* ' */
#define ORNN_KEY_COMMA           ::Ornn::Key::Comma         /* , */
#define ORNN_KEY_MINUS           ::Ornn::Key::Minus         /* - */
#define ORNN_KEY_PERIOD          ::Ornn::Key::Period        /* . */
#define ORNN_KEY_SLASH           ::Ornn::Key::Slash         /* / */
#define ORNN_KEY_0               ::Ornn::Key::D0
#define ORNN_KEY_1               ::Ornn::Key::D1
#define ORNN_KEY_2               ::Ornn::Key::D2
#define ORNN_KEY_3               ::Ornn::Key::D3
#define ORNN_KEY_4               ::Ornn::Key::D4
#define ORNN_KEY_5               ::Ornn::Key::D5
#define ORNN_KEY_6               ::Ornn::Key::D6
#define ORNN_KEY_7               ::Ornn::Key::D7
#define ORNN_KEY_8               ::Ornn::Key::D8
#define ORNN_KEY_9               ::Ornn::Key::D9
#define ORNN_KEY_SEMICOLON       ::Ornn::Key::Semicolon     /* ; */
#define ORNN_KEY_EQUAL           ::Ornn::Key::Equal         /* = */
#define ORNN_KEY_A               ::Ornn::Key::A
#define ORNN_KEY_B               ::Ornn::Key::B
#define ORNN_KEY_C               ::Ornn::Key::C
#define ORNN_KEY_D               ::Ornn::Key::D
#define ORNN_KEY_E               ::Ornn::Key::E
#define ORNN_KEY_F               ::Ornn::Key::F
#define ORNN_KEY_G               ::Ornn::Key::G
#define ORNN_KEY_H               ::Ornn::Key::H
#define ORNN_KEY_I               ::Ornn::Key::I
#define ORNN_KEY_J               ::Ornn::Key::J
#define ORNN_KEY_K               ::Ornn::Key::K
#define ORNN_KEY_L               ::Ornn::Key::L
#define ORNN_KEY_M               ::Ornn::Key::M
#define ORNN_KEY_N               ::Ornn::Key::N
#define ORNN_KEY_O               ::Ornn::Key::O
#define ORNN_KEY_P               ::Ornn::Key::P
#define ORNN_KEY_Q               ::Ornn::Key::Q
#define ORNN_KEY_R               ::Ornn::Key::R
#define ORNN_KEY_S               ::Ornn::Key::S
#define ORNN_KEY_T               ::Ornn::Key::T
#define ORNN_KEY_U               ::Ornn::Key::U
#define ORNN_KEY_V               ::Ornn::Key::V
#define ORNN_KEY_W               ::Ornn::Key::W
#define ORNN_KEY_X               ::Ornn::Key::X
#define ORNN_KEY_Y               ::Ornn::Key::Y
#define ORNN_KEY_Z               ::Ornn::Key::Z
#define ORNN_KEY_LEFT_BRACKET    ::Ornn::Key::LeftBracket   /* [ */
#define ORNN_KEY_BACKSLASH       ::Ornn::Key::Backslash     /* \ */
#define ORNN_KEY_RIGHT_BRACKET   ::Ornn::Key::RightBracket  /* ] */
#define ORNN_KEY_GRAVE_ACCENT    ::Ornn::Key::GraveAccent   /* ` */
#define ORNN_KEY_WORLD_1         ::Ornn::Key::World1        /* non-US #1 */
#define ORNN_KEY_WORLD_2         ::Ornn::Key::World2        /* non-US #2 */

/* Function keys */
#define ORNN_KEY_ESCAPE          ::Ornn::Key::Escape
#define ORNN_KEY_ENTER           ::Ornn::Key::Enter
#define ORNN_KEY_TAB             ::Ornn::Key::Tab
#define ORNN_KEY_BACKSPACE       ::Ornn::Key::Backspace
#define ORNN_KEY_INSERT          ::Ornn::Key::Insert
#define ORNN_KEY_DELETE          ::Ornn::Key::Delete
#define ORNN_KEY_RIGHT           ::Ornn::Key::Right
#define ORNN_KEY_LEFT            ::Ornn::Key::Left
#define ORNN_KEY_DOWN            ::Ornn::Key::Down
#define ORNN_KEY_UP              ::Ornn::Key::Up
#define ORNN_KEY_PAGE_UP         ::Ornn::Key::PageUp
#define ORNN_KEY_PAGE_DOWN       ::Ornn::Key::PageDown
#define ORNN_KEY_HOME            ::Ornn::Key::Home
#define ORNN_KEY_END             ::Ornn::Key::End
#define ORNN_KEY_CAPS_LOCK       ::Ornn::Key::CapsLock
#define ORNN_KEY_SCROLL_LOCK     ::Ornn::Key::ScrollLock
#define ORNN_KEY_NUM_LOCK        ::Ornn::Key::NumLock
#define ORNN_KEY_PRINT_SCREEN    ::Ornn::Key::PrintScreen
#define ORNN_KEY_PAUSE           ::Ornn::Key::Pause
#define ORNN_KEY_F1              ::Ornn::Key::F1
#define ORNN_KEY_F2              ::Ornn::Key::F2
#define ORNN_KEY_F3              ::Ornn::Key::F3
#define ORNN_KEY_F4              ::Ornn::Key::F4
#define ORNN_KEY_F5              ::Ornn::Key::F5
#define ORNN_KEY_F6              ::Ornn::Key::F6
#define ORNN_KEY_F7              ::Ornn::Key::F7
#define ORNN_KEY_F8              ::Ornn::Key::F8
#define ORNN_KEY_F9              ::Ornn::Key::F9
#define ORNN_KEY_F10             ::Ornn::Key::F10
#define ORNN_KEY_F11             ::Ornn::Key::F11
#define ORNN_KEY_F12             ::Ornn::Key::F12
#define ORNN_KEY_F13             ::Ornn::Key::F13
#define ORNN_KEY_F14             ::Ornn::Key::F14
#define ORNN_KEY_F15             ::Ornn::Key::F15
#define ORNN_KEY_F16             ::Ornn::Key::F16
#define ORNN_KEY_F17             ::Ornn::Key::F17
#define ORNN_KEY_F18             ::Ornn::Key::F18
#define ORNN_KEY_F19             ::Ornn::Key::F19
#define ORNN_KEY_F20             ::Ornn::Key::F20
#define ORNN_KEY_F21             ::Ornn::Key::F21
#define ORNN_KEY_F22             ::Ornn::Key::F22
#define ORNN_KEY_F23             ::Ornn::Key::F23
#define ORNN_KEY_F24             ::Ornn::Key::F24
#define ORNN_KEY_F25             ::Ornn::Key::F25

/* Keypad */
#define ORNN_KEY_KP_0            ::Ornn::Key::KP0
#define ORNN_KEY_KP_1            ::Ornn::Key::KP1
#define ORNN_KEY_KP_2            ::Ornn::Key::KP2
#define ORNN_KEY_KP_3            ::Ornn::Key::KP3
#define ORNN_KEY_KP_4            ::Ornn::Key::KP4
#define ORNN_KEY_KP_5            ::Ornn::Key::KP5
#define ORNN_KEY_KP_6            ::Ornn::Key::KP6
#define ORNN_KEY_KP_7            ::Ornn::Key::KP7
#define ORNN_KEY_KP_8            ::Ornn::Key::KP8
#define ORNN_KEY_KP_9            ::Ornn::Key::KP9
#define ORNN_KEY_KP_DECIMAL      ::Ornn::Key::KPDecimal
#define ORNN_KEY_KP_DIVIDE       ::Ornn::Key::KPDivide
#define ORNN_KEY_KP_MULTIPLY     ::Ornn::Key::KPMultiply
#define ORNN_KEY_KP_SUBTRACT     ::Ornn::Key::KPSubtract
#define ORNN_KEY_KP_ADD          ::Ornn::Key::KPAdd
#define ORNN_KEY_KP_ENTER        ::Ornn::Key::KPEnter
#define ORNN_KEY_KP_EQUAL        ::Ornn::Key::KPEqual

#define ORNN_KEY_LEFT_SHIFT      ::Ornn::Key::LeftShift
#define ORNN_KEY_LEFT_CONTROL    ::Ornn::Key::LeftControl
#define ORNN_KEY_LEFT_ALT        ::Ornn::Key::LeftAlt
#define ORNN_KEY_LEFT_SUPER      ::Ornn::Key::LeftSuper
#define ORNN_KEY_RIGHT_SHIFT     ::Ornn::Key::RightShift
#define ORNN_KEY_RIGHT_CONTROL   ::Ornn::Key::RightControl
#define ORNN_KEY_RIGHT_ALT       ::Ornn::Key::RightAlt
#define ORNN_KEY_RIGHT_SUPER     ::Ornn::Key::RightSuper
#define ORNN_KEY_MENU            ::Ornn::Key::Menu