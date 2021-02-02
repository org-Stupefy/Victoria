#pragma once

#include "Victoria/Core/Base.h"

namespace Victoria
{
	class Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application *CreateApplication();
} // namespace Victoria
