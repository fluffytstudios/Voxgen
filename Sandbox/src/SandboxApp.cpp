#include <Voxgen.h>

class Sandbox : public Voxgen::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Voxgen::Application* Voxgen::CreateApplication()
{
	return new Sandbox();
}	