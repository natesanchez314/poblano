#pragma once

#ifdef PB_PLATFORM_WINDOWS
	#ifdef PB_BUILD_DLL
		#define POBLANO_API __declspec(dllexport)
	#else
		#define POBLANO_API __declspec(dllimport)
	#endif
#else
	#error Poblano only supports Windows!
#endif

#define BIT(x) (1 << x)