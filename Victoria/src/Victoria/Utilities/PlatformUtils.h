#pragma once

#include <string>
#include <optional>

namespace Victoria
{
	class FileHandling
	{
	public:
		static std::optional<std::string> OpenFile(const char* filter);
		static std::optional<std::string> SaveFile(const char* filter);
	};
}
