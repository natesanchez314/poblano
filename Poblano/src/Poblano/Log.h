#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Poblano
{
	class POBLANO_API Log
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
#define PB_CORE_TRACE(...)		::Poblano::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PB_CORE_INFO(...)		::Poblano::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PB_CORE_WARN(...)		::Poblano::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PB_CORE_ERROR(...)		::Poblano::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PB_CORE_FATAL(...)		::Poblano::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define PB_CLIENT_TRACE(...)	::Poblano::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PB_CLIENT_INFO(...)		::Poblano::Log::GetClientLogger()->info(__VA_ARGS__)
#define PB_CLIENT_WARN(...)		::Poblano::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PB_CLIENT_ERROR(...)	::Poblano::Log::GetClientLogger()->error(__VA_ARGS__)
#define PB_CLIENT_FATAL(...)	::Poblano::Log::GetClientLogger()->fatal(__VA_ARGS__)