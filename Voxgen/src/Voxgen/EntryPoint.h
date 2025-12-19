#pragma once

#ifdef VG_PLATFORM_WINDOWS

extern Voxgen::Application* Voxgen::CreateApplication();

int main(int argc, char** argv)
{
	printf("Voxgen Engine\n");
	auto app = Voxgen::CreateApplication();

	app->Run();
	delete app;
}

#endif