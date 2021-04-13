#include "vcpch.h"
#include "Victoria/Renderer/RenderCommand.h"

namespace Victoria
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}
