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

#ifdef ORNN_ENABLE_ASSERTS
	#define ORNN_ASSERT(x, ...) { if(!(x)) { ORNN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ORNN_CORE_ASSERT(x, ...) { if(!(x)) { ORNN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ORNN_ASSERT(x, ...)
	#define ORNN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)