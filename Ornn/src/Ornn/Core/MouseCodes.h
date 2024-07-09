#pragma once

namespace Ornn {
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define ORNN_MOUSE_BUTTON_0      ::Ornn::Mouse::Button0
#define ORNN_MOUSE_BUTTON_1      ::Ornn::Mouse::Button1
#define ORNN_MOUSE_BUTTON_2      ::Ornn::Mouse::Button2
#define ORNN_MOUSE_BUTTON_3      ::Ornn::Mouse::Button3
#define ORNN_MOUSE_BUTTON_4      ::Ornn::Mouse::Button4
#define ORNN_MOUSE_BUTTON_5      ::Ornn::Mouse::Button5
#define ORNN_MOUSE_BUTTON_6      ::Ornn::Mouse::Button6
#define ORNN_MOUSE_BUTTON_7      ::Ornn::Mouse::Button7
#define ORNN_MOUSE_BUTTON_LAST   ::Ornn::Mouse::ButtonLast
#define ORNN_MOUSE_BUTTON_LEFT   ::Ornn::Mouse::ButtonLeft
#define ORNN_MOUSE_BUTTON_RIGHT  ::Ornn::Mouse::ButtonRight
#define ORNN_MOUSE_BUTTON_MIDDLE ::Ornn::Mouse::ButtonMiddle