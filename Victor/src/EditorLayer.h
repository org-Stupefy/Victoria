#pragma once

#include <Victoria.h>

namespace Victoria
{
	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate(Timestep ts);

		virtual void OnImGuiRender() override;
		void OnEvent(Event& event) override;

	private:
		bool OnKeyPressed(KeyPressedEvent& event);

		void NewScene();
		void OpenScene();
		void SaveSceneAs();
	};
}
