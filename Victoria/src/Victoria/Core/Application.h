#pragma once

#include "Victoria/Core/Base.h"

#include "Victoria/Core/Window.h"
#include "Victoria/Layer/LayerStack.h"
#include "Victoria/Events/Events.h"
#include "Victoria/Events/ApplicationEvents.h"

#include "Victoria/Core/Timestep.h"

namespace Victoria
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
} // namespace Victoria
