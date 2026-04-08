#include <Voxgen.h>

class Sandbox : public Voxgen::Application
{
public:
	Sandbox()
	{
		Voxgen::Logger logger;
		logger.Log(Voxgen::Logger::LogType::DEBUG, "debug string");
	}

	~Sandbox()
	{

	}
};

Voxgen::Application* Voxgen::CreateApplication()
{
	return new Sandbox();
}	