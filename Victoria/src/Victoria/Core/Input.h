#pragma once

#include <glm/glm.hpp>

#include "Victoria/Core/KeyCodes.h"
#include "Victoria/Core/MouseCodes.h"

namespace Victoria {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
