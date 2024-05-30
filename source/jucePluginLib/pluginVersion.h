#pragma once
#include <string>

namespace pluginLib
{
	class Version
	{
	public:
		static std::string getVersionString();
		static uint32_t getVersionNumber();
		static std::string getVersionDate();
		static std::string getVersionTime();
		static std::string getVersionDateTime();
	};
}