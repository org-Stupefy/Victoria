#define VICTORIA_ENTRYPOINT
#include <Victoria.h>

#include "ExampleLayer.h"

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

Victoria::Application* Victoria::CreateApplication()
{
	return new Sandbox();
}
