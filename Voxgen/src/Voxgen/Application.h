#pragma once

#include "Core.h"

namespace Voxgen
{
	class VOXGEN_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}