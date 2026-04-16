#pragma once

#include <source_location>
#include <string>
#include <vector>
#include <variant>
#include <iostream>
#include <array>

#include "Core.h"

namespace Voxgen {
	class VOXGEN_API Logger {

	public:
		enum class LogType
		{
			DEBUG,
			INFO,
			WARN,
			ERROR
		};
		static void Log_Debug(std::string str, std::vector<std::variant<int, float, double, long, std::string, bool>> params);
		static void Log_Info(std::string str, std::vector<std::variant<int, float, double, long, std::string, bool>> params);
		static void Log_Warn(std::string str, std::vector<std::variant<int, float, double, long, std::string, bool>> params);
		static void Log_Error(std::string str, std::vector<std::variant<int, float, double, long, std::string, bool>> params);

	protected:
		static int GetParamI(const std::array<size_t, 2> ind, int deltaI, const std::string& str);
		static void Log(LogType type, std::string str, std::vector<std::variant<int, float, double, long, std::string, bool>> params);
		static std::string Stringify(std::variant<int, float, double, long, std::string, bool> param);
	};

}