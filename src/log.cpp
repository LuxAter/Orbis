#include "orbis/log.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

static std::shared_ptr<spdlog::sinks::basic_file_sink_mt> core_file_sink;
static std::shared_ptr<spdlog::logger> core_logger;
static std::unordered_map<std::string, std::shared_ptr<spdlog::logger>>
    client_logger;

bool orbis::logger::initalize_core_logger(const LogLevel &console_level,
                                          const LogLevel &file_level) {
  try {
    core_file_sink =
        std::make_shared<spdlog::sinks::basic_file_sink_mt>("orbis.log", true);
    core_file_sink->set_level(
        static_cast<spdlog::level::level_enum>(file_level));
    std::vector<spdlog::sink_ptr> sinks;
    sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    sinks.back()->set_level(
        static_cast<spdlog::level::level_enum>(console_level));
    sinks.push_back(core_file_sink);
    core_logger =
        std::make_shared<spdlog::logger>("orbis", begin(sinks), end(sinks));
    core_logger->set_level(static_cast<spdlog::level::level_enum>(
        std::min(static_cast<uint8_t>(console_level),
                 static_cast<uint8_t>(file_level))));

    return true;
  } catch (const spdlog::spdlog_ex &ex) {
    std::cerr << "Log initialization failed: " << ex.what() << std::endl;
    return false;
  }
}

bool orbis::logger::initalize_logger(const std::string &name,
                                     const LogLevel &console_level,
                                     const LogLevel &file_level) {
  try {
    std::vector<spdlog::sink_ptr> sinks;
    sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
    sinks.back()->set_level(
        static_cast<spdlog::level::level_enum>(console_level));
    sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(
        name + ".log", true));
    sinks.back()->set_level(static_cast<spdlog::level::level_enum>(file_level));
    sinks.push_back(core_file_sink);
    client_logger[name] =
        std::make_shared<spdlog::logger>(name, begin(sinks), end(sinks));
    client_logger[name]->set_level(static_cast<spdlog::level::level_enum>(
        std::min(static_cast<uint8_t>(console_level),
                 static_cast<uint8_t>(file_level))));
    spdlog::set_level(spdlog::level::trace);

    return true;
  } catch (const spdlog::spdlog_ex &ex) {
    std::cerr << "Log initialization failed: " << ex.what() << std::endl;
    return false;
  }
}

bool orbis::logger::terminate_logger(const std::string &name) {
  if (!client_logger.empty() &&
      client_logger.find(name) != client_logger.end()) {
    client_logger.erase(client_logger.find(name));
    return true;
  } else {
    std::cerr
        << "Failed to pop logger from stack, other loggers have been pushed";
    return false;
  }
}

std::shared_ptr<spdlog::logger> orbis::logger::get_core() {
  return core_logger;
}
std::shared_ptr<spdlog::logger>
orbis::logger::get_client(const std::string &name) {
  return client_logger[name];
}
