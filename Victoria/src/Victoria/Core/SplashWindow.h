#pragma once

#include "Victoria/Core/Base.h"

namespace Victoria
{
	struct SplashWindowProps
	{
		const char* Name;
		const char* ImagePath;
		int Width;
		int Height;
	};

	class SplashWindow
	{
	public:
		virtual ~SplashWindow() = default;
		virtual void Destroy() = 0;
		static Scope<SplashWindow> Create(const SplashWindowProps& props);
	};
}
