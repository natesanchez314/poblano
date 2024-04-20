#pragma once

#ifdef PB_PLATFORM_WINDOWS

extern Poblano::App* Poblano::CreateApp();

int main(int argc, char** argv)
{
	Poblano::Log::Init();

	auto app = Poblano::CreateApp();
	app->run();
	delete app;
}
#else
	#error Poblano only supports Windows!
#endif