#include <Victoria.h>
#include <Victoria/Core/EntryPoint.h>

class SandBox : public Victoria::Application
{
public:
	SandBox()
	{
	}

	~SandBox()
	{
	}
};

Victoria::Application *Victoria::CreateApplication()
{
	return new SandBox();
}
