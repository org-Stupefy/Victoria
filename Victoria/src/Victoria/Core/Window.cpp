#include "vcpch.h"
#include "Victoria/Core/Window.h"

#ifdef VC_PLATFORM_WINDOWS
#include "Platform/Windows/WindowWindows.h"
#endif

namespace Victoria
{
	Scope<Window> Window::Create(const WindowProperties& props)
	{
#ifdef VC_PLATFORM_WINDOWS
		return CreateScope<WindowWindows>(props);
#else
		VC_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}
