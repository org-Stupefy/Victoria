#pragma once

#include "Victoria/Core/Base.h"
#include "Victoria/Core/Log.h"
#include <filesystem>

#ifdef VC_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define VC_INTERNAL_ASSERT_IMPL(type, check, msg, ...) \
	{                                                  \
		if (!(check))                                  \
		{                                              \
			VC##type##ERROR(msg, __VA_ARGS__);         \
			VC_DEBUGBREAK();                           \
		}                                              \
	}
#define VC_INTERNAL_ASSERT_WITH_MSG(type, check, ...) VC_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define VC_INTERNAL_ASSERT_NO_MSG(type, check) VC_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", VC_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define VC_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define VC_INTERNAL_ASSERT_GET_MACRO(...) VC_EXPAND_MACRO(VC_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, VC_INTERNAL_ASSERT_WITH_MSG, VC_INTERNAL_ASSERT_NO_MSG))

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define VC_ASSERT(...) VC_EXPAND_MACRO(VC_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__))
#define VC_CORE_ASSERT(...) VC_EXPAND_MACRO(VC_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__))
#else
#define VC_ASSERT(...)
#define VC_CORE_ASSERT(...)
#endif
