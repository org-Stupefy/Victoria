#include <Victoria.h>
#include <Victoria/Core/EntryPoint.h>

class ExampleLayer : public Victoria::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		VC_INFO("ExampleLayer::Update");
	}

	void OnEvent(Victoria::Event &event) override
	{
		VC_TRACE("{0}", event);
	}
};

class Sandbox : public Victoria::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{
	}
};

Victoria::Application *Victoria::CreateApplication()
{
	return new Sandbox();
}
