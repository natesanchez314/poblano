#include <Poblano.h>

class SandboxApp : public Poblano::App
{
public:
	SandboxApp()
	{

	}

	~SandboxApp() {

	}
};

Poblano::App* Poblano::CreateApp()
{
	return new SandboxApp();
}