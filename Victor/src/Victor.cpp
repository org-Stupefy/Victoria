#include <Victoria.h>
#include <Victoria/Core/EntryPoint.h>

namespace Victoria
{
    class Victor : public Application
    {
    public:
        Victor()
        {
        }
    };

    Application *CreateApplication()
    {
        return new Victor();
    }
} // namespace Victoria
