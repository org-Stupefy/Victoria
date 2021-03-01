#pragma once

#include <memory>

#include "Victoria/Core/PlatformDetection.h"

#ifdef VC_DEBUG
#if defined(VC_PLATFORM_WINDOWS)
#define VC_DEBUGBREAK() __debugbreak()
#elif defined(VC_PLATFORM_LINUX)
#include <signal.h>
#define VC_DEBUGBREAK() raise(SIGTRAP)
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define VC_ENABLE_ASSERTS
#else
#define VC_DEBUGBREAK()
#endif

#define VC_EXPAND_MACRO(x) x
#define VC_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define VC_BIND_EVENT_FN(fn) [this](auto &&...args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Victoria
{

	template <typename T>
	using Scope = std::unique_ptr<T>;
	template <typename T, typename... Args>
	constexpr Scope<T> CreateScope(Args &&...args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template <typename T>
	using Ref = std::shared_ptr<T>;
	template <typename T, typename... Args>
	constexpr Ref<T> CreateRef(Args &&...args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

} 

#include "Victoria/Core/Log.h"
#include "Victoria/Core/Assert.h"
