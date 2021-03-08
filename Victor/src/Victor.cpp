#include <Victoria.h>
#include "Victoria/Core/EntryPoint.h"

#include "EditorLayer.h"

namespace Victoria
{
    class Victor : public Application
    {
    public:
        Victor()
			: Application("Victor")
        {
			PushLayer(new EditorLayer());
        }

		~Victor()
		{
		}
    };

    Application *CreateApplication()
    {
        return new Victor();
    }
} 
