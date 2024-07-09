#pragma once

#include "Ornn/Core/Core.h"
#include "Ornn/Core/KeyCodes.h"
#include "Ornn/Core/MouseCodes.h"

namespace Ornn {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}