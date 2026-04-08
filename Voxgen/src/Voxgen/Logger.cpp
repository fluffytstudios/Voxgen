#include <stdio.h>

#include "Logger.h"

namespace Voxgen {
	Logger::Logger()
	{
		
	}
	Logger::~Logger()
	{

	}

	void Logger::Log(LogType type, const char* str)
	{
		const char* TypeStrings[4] = {"[DEBUG]", "[INFO]", "[WARN]", "[ERROR]"};
		printf("%s: %s\n", TypeStrings[static_cast<int>(type)], str);
	}
}