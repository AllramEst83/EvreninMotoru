#pragma once

#include <memory>
#include "Core/Base.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace EvreninMotoru {

	class EvreninMotoru_API Log
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

//Core log macros
#define EM_CORE_TRACE(...)    ::EvreninMotoru::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EM_CORE_INFO(...)     ::EvreninMotoru::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EM_CORE_WARN(...)     ::EvreninMotoru::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EM_CORE_ERROR(...)    ::EvreninMotoru::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EM_CORE_CRITICAL(...) ::EvreninMotoru::Log::GetCoreLogger()->critical(__VA_ARGS__)
				
// ClienEMlog macros			
#define EM_TRACE(...)         ::EvreninMotoru::Log::GetClientLogger()->trace(__VA_ARGS__)
#define EM_INFO(...)          ::EvreninMotoru::Log::GetClientLogger()->info(__VA_ARGS__)
#define EM_WARN(...)          ::EvreninMotoru::Log::GetClientLogger()->warn(__VA_ARGS__)
#define EM_ERROR(...)         ::EvreninMotoru::Log::GetClientLogger()->error(__VA_ARGS__)
#define EM_CRITICAL(...)      ::EvreninMotoru::Log::GetClientLogger()->critical(__VA_ARGS__)

