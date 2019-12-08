//
// Created by bacox on 11-11-19.
//

#include "spdlog/sinks/stdout_color_sinks.h"
#include <spdlog/spdlog.h>
#include "../include/Log.h"
namespace Util {
    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Init() {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_CoreLogger = spdlog::stdout_color_mt("Core");
        s_CoreLogger->set_level(spdlog::level::trace);

        s_ClientLogger = spdlog::stdout_color_mt("Server");
        s_ClientLogger->set_level(spdlog::level::trace);
    }
}