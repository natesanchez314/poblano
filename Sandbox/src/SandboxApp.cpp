#include <Poblano.h>

class SandboxApp : public Poblano::App
{
public:
	SandboxApp()
	{

	}

	~SandboxApp()
	{

	}
};

Poblano::App* Poblano::createApp()
{
	return new SandboxApp();
}