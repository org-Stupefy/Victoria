#pragma once

#include "Victoria/Layer/Layer.h"

#include "Victoria/Events/ApplicationEvents.h"
#include "Victoria/Events/KeyEvents.h"
#include "Victoria/Events/MouseEvents.h"

namespace Victoria
{
    class ImGuiLayer : public Layer
    {
    public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }

		void SetDarkThemeColors();
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
    };
}
