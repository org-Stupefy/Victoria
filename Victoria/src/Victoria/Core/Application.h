#pragma once

#include "Victoria/Core/Base.h"

#include "Victoria/Core/Window.h"
#include "Victoria/Layer/LayerStack.h"
#include "Victoria/Events/Events.h"
#include "Victoria/Events/ApplicationEvents.h"

#include "Victoria/ImGui/ImGuiLayer.h"

#include "Victoria/Core/Timestep.h"

namespace Victoria
{
	class Application
	{
	public:
		Application(const std::string& name = "Victoria");
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		void Close();

		Window& GetWindow() { return *m_Window; }
		static Application& Get() { return *s_Instance; }

		void Run();

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
} 
