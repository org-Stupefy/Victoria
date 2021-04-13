#pragma once
#include "Victoria/Core/Base.h"

#ifdef VC_PLATFORM_WINDOWS

extern Victoria::Application *Victoria::CreateApplication();

int main(int argc, char **argv)
{
	Victoria::Log::Init();

	VC_PROFILE_BEGIN_SESSION("Startup", "VictoriaProfile-Startup.json");
	auto app = Victoria::CreateApplication();
	VC_PROFILE_END_SESSION();

	VC_PROFILE_BEGIN_SESSION("Runtime", "VictoriaProfile-Runtime.json");
	app->Run();
	VC_PROFILE_END_SESSION();

	VC_PROFILE_BEGIN_SESSION("Shutdown", "VictoriaProfile-Shutdown.json");
	delete app;
	VC_PROFILE_END_SESSION();
}
#endif
