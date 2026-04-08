#include <ctime>
#include <stdio.h>

#include "Application.h"


namespace Voxgen
{
	Application::Application() 
	{
	
	}

	Application::~Application() 
	{
	
	}

	void Application::Run() 
	{
		while (true);
	}

	void Application::Update(double dt)
	{
		printf("%e\n", dt);
	}
}
