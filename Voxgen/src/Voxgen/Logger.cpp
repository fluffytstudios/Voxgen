#include <stdio.h>

#include "Logger.h"

namespace Voxgen {
	void Logger::Log_Debug(std::string str, std::vector<std::variant<int, float, double, long, std::string, bool>> params)
	{
		Logger::Log(Logger::LogType::DEBUG, str, params);
	}
	void Logger::Log_Info(std::string str, std::vector<std::variant<int, float, double, long, std::string, bool>> params)
	{
		Logger::Log(Logger::LogType::INFO, str, params);
	}
	void Logger::Log_Warn(std::string str, std::vector<std::variant<int, float, double, long, std::string, bool>> params)
	{
		Logger::Log(Logger::LogType::WARN, str, params);
	}
	void Logger::Log_Error(std::string str, std::vector<std::variant<int, float, double, long, std::string, bool>> params)
	{
		Logger::Log(Logger::LogType::ERROR, str, params);
	}

	void Logger::Log(LogType type, std::string str, std::vector<std::variant<int, float, double, long, std::string, bool>> params)
	{
		const char* TypeStrings[4] = { "[DEBUG]", "[INFO]", "[WARN]", "[ERROR]" };

		std::vector<std::string> sParams;
		sParams.reserve(params.size());

		for (size_t i = 0; i < params.size(); i++)
		{
			sParams.push_back(Stringify(params[i]));
		}

		std::vector<std::array<size_t, 2>> paramIndicies;

		size_t sSize = str.size();

		for (size_t i = 0; i < sSize; i++)
		{
			if (i != 0)
			{
				if (str[i] == '#' && ((i == 0 && i < sSize - 1) || str[i - 1] != '\\'))
				{
					for (size_t j = i + 1; j <= sSize; j++)
					{
						if (str[j] == ' ' || j == sSize)
						{
							paramIndicies.push_back({ i, j - 1 });
							break;
						}
					}
				}
			}
		}

		int deltaI = 0;

		for (size_t i = 0; i < paramIndicies.size(); i++)
		{
			size_t paramI = GetParamI(paramIndicies[i], deltaI, str);
			auto vParam = params[paramI];
			std::string param = Stringify(vParam);
			str.replace(paramIndicies[i][0] + deltaI, paramIndicies[i][1] - paramIndicies[i][0] + 1, param);
			//change deltaI by the inserted length minus the syntax required for param placement. +1 comes from inclusive indexing
			deltaI += param.length() - (paramIndicies[i][1] - paramIndicies[i][0] + 1);
		}

		std::cout << TypeStrings[static_cast<int>(type)] << " " << str;
	}

	std::string Logger::Stringify(std::variant<int, float, double, long, std::string, bool> param)
	{
		if (std::holds_alternative<std::string>(param)) return std::get<std::string>(param);

		if (std::holds_alternative<bool>(param)) return std::get<bool>(param) ? "true" : "false";

		if (std::holds_alternative<int>(param)) return std::to_string(std::get<int>(param));
		if (std::holds_alternative<long>(param)) return std::to_string(std::get<long>(param));
		if (std::holds_alternative<float>(param)) return std::to_string(std::get<float>(param));
		if (std::holds_alternative<double>(param)) return std::to_string(std::get<double>(param));

		throw std::logic_error("Unhandled std::variant type");
	}

	int Logger::GetParamI(const std::array<size_t, 2> ind, int deltaI, const std::string& str)
	{
		//+1 due to inclusive indexing
		size_t len = ind[1] - ind[0] + 1	;

		std::string sstr = str.substr(ind[0] + deltaI + 1, len);

		return std::stoi(sstr);
	}

	//Log(LogType::DEBUG, "Param 2 is: #2 , Param 1 is #1", [197, "str"])
}