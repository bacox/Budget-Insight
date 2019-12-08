//
// Created by bacox on 11-11-19.
//

#ifndef BUDGET_INSIGHT_LOG_H
#define BUDGET_INSIGHT_LOG_H

#include <memory>
#include "spdlog/logger.h"

namespace Util {
    class Log {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }

        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core log macros
#define EN_CORE_TRACE(...)    ::Util::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EN_CORE_INFO(...)     ::Util::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EN_CORE_WARN(...)     ::Util::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EN_CORE_ERROR(...)    ::Util::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EN_CORE_FATAL(...)    ::Util::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Server log macros
#define EN_TRACE(...)          ::Util::Log::GetClientLogger()->trace(__VA_ARGS__)
#define EN_INFO(...)          ::Util::Log::GetClientLogger()->info(__VA_ARGS__)
#define EN_WARN(...)          ::Util::Log::GetClientLogger()->warn(__VA_ARGS__)
#define EN_ERROR(...)          ::Util::Log::GetClientLogger()->error(__VA_ARGS__)
#define EN_FATAL(...)          ::Util::Log::GetClientLogger()->fatal(__VA_ARGS__)



#endif //BUDGET_INSIGHT_LOG_H
