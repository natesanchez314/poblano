#pragma once

#include "Core.h"

namespace Poblano
{
	class __declspec(dllexport) App
	{
	public:
		App();
		virtual ~App();

		void run();
	};

	App* CreateApp();
}