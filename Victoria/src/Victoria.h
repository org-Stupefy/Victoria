#pragma once

// For use by Victoria applications

// ---Core------------------------
#include "Victoria/Core/Application.h"
#include "Victoria/Core/Assert.h"
#include "Victoria/Core/Base.h"
#include "Victoria/Core/Input.h"
#include "Victoria/Core/Log.h"
#include "Victoria/Core/Timestep.h"
#include "Victoria/Core/UUID.h"
#include "Victoria/Core/Window.h"

#include "Victoria/Core/KeyCodes.h"
#include "Victoria/Core/MouseCodes.h"

// ---Events------------------------
#include "Victoria/Events/Events.h"
#include "Victoria/Events/ApplicationEvents.h"
#include "Victoria/Events/KeyEvents.h"
#include "Victoria/Events/MouseEvents.h"

// ---ImGui------------------------
#include "Victoria/ImGui/ImGuiLayer.h"

// ---Layer------------------------
#include "Victoria/Layer/Layer.h"
#include "Victoria/Layer/LayerStack.h"

// ---Math------------------------
#include "Victoria/Math/Cone.h"
#include "Victoria/Math/Sphere.h"
#include "Victoria/Math/Torus.h"

// ---Renderer------------------------
#include "Victoria/Renderer/Buffer.h"
#include "Victoria/Renderer/Camera.h"
#include "Victoria/Renderer/EditorCamera.h"
#include "Victoria/Renderer/FrameBuffer.h"
#include "Victoria/Renderer/GraphicsContext.h"
#include "Victoria/Renderer/OrthographicCamera.h"
#include "Victoria/Renderer/OrthographicCameraController.h"
#include "Victoria/Renderer/PerspectiveCamera.h"
#include "Victoria/Renderer/RenderCommand.h"
#include "Victoria/Renderer/Renderer.h"
#include "Victoria/Renderer/RendererAPI.h"
#include "Victoria/Renderer/Shader.h"
#include "Victoria/Renderer/Texture.h"
#include "Victoria/Renderer/VertexArray.h"

// ---Scene------------------------
#include "Victoria/Scene/Components.h"
#include "Victoria/Scene/Entity.h"
#include "Victoria/Scene/Scene.h""
#include "Victoria/Scene/SceneCamera.h"

// -----------------------------------

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#ifdef VICTORIA_ENTRYPOINT
#   include "Victoria/Core/EntryPoint.h"
#endif
