#pragma once

#include "Victoria/Core/Base.h"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Victoria
{
	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

} 

// Core log macros
#define VC_CORE_TRACE(...) ::Victoria::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VC_CORE_INFO(...) ::Victoria::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VC_CORE_WARN(...) ::Victoria::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VC_CORE_ERROR(...) ::Victoria::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VC_CORE_CRITICAL(...) ::Victoria::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define VC_TRACE(...) ::Victoria::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VC_INFO(...) ::Victoria::Log::GetClientLogger()->info(__VA_ARGS__)
#define VC_WARN(...) ::Victoria::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VC_ERROR(...) ::Victoria::Log::GetClientLogger()->error(__VA_ARGS__)
#define VC_CRITICAL(...) ::Victoria::Log::GetClientLogger()->critical(__VA_ARGS__)
