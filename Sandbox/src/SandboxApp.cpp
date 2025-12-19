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

void main()
{
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}