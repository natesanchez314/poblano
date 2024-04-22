#pragma once

#ifdef PB_PLATFORM_WINDOWS

extern Poblano::App* Poblano::createApp();

int main(int argc, char** argv)
{
	Poblano::Log::init();

	auto app = Poblano::createApp();
	app->run();
	delete app;
}
#else
	#error Poblano only supports Windows!
#endif