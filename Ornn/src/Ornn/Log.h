#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Ornn {

	class ORNN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define ORNN_CORE_TRACE(...)    ::Ornn::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ORNN_CORE_INFO(...)     ::Ornn::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ORNN_CORE_WARN(...)     ::Ornn::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ORNN_CORE_ERROR(...)    ::Ornn::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ORNN_CORE_FATAL(...)    ::Ornn::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros			  
#define ORNN_TRACE(...)	        ::Ornn::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ORNN_INFO(...)	        ::Ornn::Log::GetClientLogger()->info(__VA_ARGS__)
#define ORNN_WARN(...)	        ::Ornn::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ORNN_ERROR(...)	        ::Ornn::Log::GetClientLogger()->error(__VA_ARGS__)
#define ORNN_FATAL(...)	        ::Ornn::Log::GetClientLogger()->critical(__VA_ARGS__)
