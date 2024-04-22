#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Poblano
{
	class POBLANO_API Log
	{
	public:
		static void init();
		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define PB_CORE_TRACE(...)		::Poblano::Log::getCoreLogger()->trace(__VA_ARGS__)
#define PB_CORE_INFO(...)		::Poblano::Log::getCoreLogger()->info(__VA_ARGS__)
#define PB_CORE_WARN(...)		::Poblano::Log::getCoreLogger()->warn(__VA_ARGS__)
#define PB_CORE_ERROR(...)		::Poblano::Log::getCoreLogger()->error(__VA_ARGS__)
#define PB_CORE_FATAL(...)		::Poblano::Log::getCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define PB_CLIENT_TRACE(...)	::Poblano::Log::getClientLogger()->trace(__VA_ARGS__)
#define PB_CLIENT_INFO(...)		::Poblano::Log::getClientLogger()->info(__VA_ARGS__)
#define PB_CLIENT_WARN(...)		::Poblano::Log::getClientLogger()->warn(__VA_ARGS__)
#define PB_CLIENT_ERROR(...)	::Poblano::Log::getClientLogger()->error(__VA_ARGS__)
#define PB_CLIENT_FATAL(...)	::Poblano::Log::getClientLogger()->fatal(__VA_ARGS__)