#pragma once

#include "Victoria/Core/SplashWindow.h"

namespace Victoria
{
	class WindowsSplashWindow : public SplashWindow
	{
	public:
		WindowsSplashWindow(const SplashWindowProps& props);
		~WindowsSplashWindow() = default;
		virtual void Destroy() override;
	private:
		HWND mSplashWindow;
	};
}

