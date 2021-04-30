#pragma once

#include "Victoria.h"

class ExampleLayer : public Victoria::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Victoria::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Victoria::Event& e) override;
private:
	Victoria::ShaderLibrary m_ShaderLibrary;
	Victoria::Ref<Victoria::Shader> m_Shader;
	Victoria::Ref<Victoria::VertexArray> m_VertexArray;

	Victoria::Ref<Victoria::Shader> m_FlatColorShader;
	Victoria::Ref<Victoria::VertexArray> m_SquareVA;

	Victoria::Ref<Victoria::Texture2D> m_Texture, m_TestTexture;
	Victoria::OrthographicCameraController m_CameraController;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

