#pragma once

#ifdef ORNN_PLATFORM_WINDOWS
	#ifdef ORNN_BUILD_DLL
		#define ORNN_API __declspec(dllexport)
	#else
		#define ORNN_API __declspec(dllimport)
	#endif // ORNN_BUILD_DLL
#else
	#error Ornn only support Windows!
#endif