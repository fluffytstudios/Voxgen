#pragma once

#include "Core.h"

namespace Voxgen {
	class VOXGEN_API Logger {

	public:
		Logger();
		~Logger();

		enum class LogType
		{
			DEBUG,
			INFO,
			WARN,
			ERROR
		};

		void Log(LogType type, const char* str);
	};
}