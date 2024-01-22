#pragma once

#include <memory>

#ifdef ORNN_PLATFORM_WINDOWS
	#if ORNN_DYNAMIC_LINK
		#ifdef ORNN_BUILD_DLL
			#define ORNN_API __declspec(dllexport)
		#else
			#define ORNN_API __declspec(dllimport)
		#endif // ORNN_BUILD_DLL
	#else
		#define ORNN_API
	#endif
#else
	#error Ornn only support Windows!
#endif

#ifdef ORNN_DEBUG
	#define ORNN_ENABLE_ASSERTS
#endif

#ifdef ORNN_ENABLE_ASSERTS
	#define ORNN_ASSERT(x, ...) { if(!(x)) { ORNN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ORNN_CORE_ASSERT(x, ...) { if(!(x)) { ORNN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ORNN_ASSERT(x, ...)
	#define ORNN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define ORNN_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Ornn {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

}