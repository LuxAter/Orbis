#ifndef ORBIS_LOG_HPP_
#define ORBIS_LOG_HPP_

#include <cstdlib>
#include <iostream>

#ifdef __DEBUG__
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#endif

#include <spdlog/spdlog.h>
#define ORBIS_LOGGER_CALL(logger, level, ...)                                  \
  (logger)->log(spdlog::source_loc{__FILE__, __LINE__, SPDLOG_FUNCTION},       \
                level, __VA_ARGS__)
#define ORBIS_LOGGER_CALL_SOURCE(logger, level, file, line, function, ...)     \
  (logger)->log(spdlog::source_loc(file, line, function), level, __VA_ARGS__)

#define ORBIS_LOGGER_TRACE(logger, ...)                                        \
  ORBIS_LOGGER_CALL(logger, spdlog::level::trace, __VA_ARGS__)
#define ORBIS_LOGGER_DEBUG(logger, ...)                                        \
  ORBIS_LOGGER_CALL(logger, spdlog::level::debug, __VA_ARGS__)
#define ORBIS_LOGGER_INFO(logger, ...)                                         \
  ORBIS_LOGGER_CALL(logger, spdlog::level::info, __VA_ARGS__)
#define ORBIS_LOGGER_WARN(logger, ...)                                         \
  ORBIS_LOGGER_CALL(logger, spdlog::level::warn, __VA_ARGS__)
#define ORBIS_LOGGER_ERROR(logger, ...)                                        \
  ORBIS_LOGGER_CALL(logger, spdlog::level::err, __VA_ARGS__)
#define ORBIS_LOGGER_CRITICAL(logger, ...)                                     \
  ORBIS_LOGGER_CALL(logger, spdlog::level::critical, __VA_ARGS__)
#define ORBIS_LOGGER_FATAL(logger, ...)                                        \
  ORBIS_LOGGER_CALL(logger, spdlog::level::critical, __VA_ARGS__)

#define ORBIS_LOGGER_SOURCE_TRACE(logger, file, line, function, ...)           \
  ORBIS_LOGGER_SOURCE_CALL(logger, spdlog::level::trace, __VA_ARGS__)
#define ORBIS_LOGGER_SOURCE_DEBUG(logger, file, line, function, ...)           \
  ORBIS_LOGGER_SOURCE_CALL(logger, spdlog::level::debug, __VA_ARGS__)
#define ORBIS_LOGGER_SOURCE_INFO(logger, file, line, function, ...)            \
  ORBIS_LOGGER_SOURCE_CALL(logger, spdlog::level::info, __VA_ARGS__)
#define ORBIS_LOGGER_SOURCE_WARN(logger, file, line, function, ...)            \
  ORBIS_LOGGER_SOURCE_CALL(logger, spdlog::level::warn, __VA_ARGS__)
#define ORBIS_LOGGER_SOURCE_ERROR(logger, file, line, function, ...)           \
  ORBIS_LOGGER_SOURCE_CALL(logger, spdlog::level::err, __VA_ARGS__)
#define ORBIS_LOGGER_SOURCE_CRITICAL(logger, file, line, function, ...)        \
  ORBIS_LOGGER_SOURCE_CALL(logger, spdlog::level::critical, __VA_ARGS__)
#define ORBIS_LOGGER_SOURCE_FATAL(logger, file, line, function, ...)           \
  ORBIS_LOGGER_SOURCE_CALL(logger, spdlog::level::critical, __VA_ARGS__)

#define ORBIS_CORE_TRACE(...)                                                  \
  ORBIS_LOGGER_TRACE(orbis::logger::get_logger(), __VA_ARGS__)
#define ORBIS_CORE_DEBUG(...)                                                  \
  ORBIS_LOGGER_DEBUG(orbis::logger::get_logger(), __VA_ARGS__)
#define ORBIS_CORE_INFO(...)                                                   \
  ORBIS_LOGGER_INFO(orbis::logger::get_logger(), __VA_ARGS__)
#define ORBIS_CORE_WARN(...)                                                   \
  ORBIS_LOGGER_WARN(orbis::logger::get_logger(), __VA_ARGS__)
#define ORBIS_CORE_ERROR(...)                                                  \
  ORBIS_LOGGER_ERROR(orbis::logger::get_logger(), __VA_ARGS__)
#define ORBIS_CORE_CRITICAL(...)                                               \
  ORBIS_LOGGER_CRITICAL(orbis::logger::get_logger(), __VA_ARGS__)
#define ORBIS_CORE_FATAL(...)                                                  \
  ORBIS_LOGGER_FATAL(orbis::logger::get_logger(), __VA_ARGS__)

#define ORBIS_CORE_SOURCE_TRACE(file, line, function, ...)                     \
  ORBIS_LOGGER_SOURCE_TRACE(orbis::logger::get_logger(), file, line, function, \
                            __VA_ARGS__)
#define ORBIS_CORE_SOURCE_DEBUG(file, line, function, ...)                     \
  ORBIS_LOGGER_SOURCE_DEBUG(orbis::logger::get_logger(), file, line, function, \
                            __VA_ARGS__)
#define ORBIS_CORE_SOURCE_INFO(file, line, function, ...)                      \
  ORBIS_LOGGER_SOURCE_INFO(orbis::logger::get_logger(), file, line, function,  \
                           __VA_ARGS__)
#define ORBIS_CORE_SOURCE_WARN(file, line, function, ...)                      \
  ORBIS_LOGGER_SOURCE_WARN(orbis::logger::get_logger(), file, line, function,  \
                           __VA_ARGS__)
#define ORBIS_CORE_SOURCE_ERROR(file, line, function, ...)                     \
  ORBIS_LOGGER_SOURCE_ERROR(orbis::logger::get_logger(), file, line, function, \
                            __VA_ARGS__)
#define ORBIS_CORE_SOURCE_CRITICAL(file, line, function, ...)                  \
  ORBIS_LOGGER_SOURCE_CRITICAL(orbis::logger::get_logger(), file, line,        \
                               function, __VA_ARGS__)
#define ORBIS_CORE_SOURCE_FATAL(file, line, function, ...)                     \
  ORBIS_LOGGER_SOURCE_FATAL(orbis::logger::get_logger(), file, line, function, \
                            __VA_ARGS__)

#define LTRACE(...) ORBIS_CORE_TRACE(__VA_ARGS__)
#define LDEBUG(...) ORBIS_CORE_DEBUG(__VA_ARGS__)
#define LINFO(...) ORBIS_CORE_INFO(__VA_ARGS__)
#define LWARN(...) ORBIS_CORE_WARN(__VA_ARGS__)
#define LERROR(...) ORBIS_CORE_ERROR(__VA_ARGS__)
#define LCRITICAL(...) ORBIS_CORE_CRITICAL(__VA_ARGS__)
#define LFATAL(...) ORBIS_CORE_FATAL(__VA_ARGS__)

#define LCTRACE(...) ORBIS_CLIENT_TRACE(__VA_ARGS__)
#define LCDEBUG(...) ORBIS_CLIENT_DEBUG(__VA_ARGS__)
#define LCINFO(...) ORBIS_CLIENT_INFO(__VA_ARGS__)
#define LCWARN(...) ORBIS_CLIENT_WARN(__VA_ARGS__)
#define LCERROR(...) ORBIS_CLIENT_ERROR(__VA_ARGS__)
#define LCCRITICAL(...) ORBIS_CLIENT_CRITICAL(__VA_ARGS__)
#define LCFATAL(...) ORBIS_CLIENT_FATAL(__VA_ARGS__)

#define LSTRACE(file, line, function, ...)                                     \
  ORBIS_CORE_SOURCE_TRACE(file, line, function, __VA_ARGS__)
#define LSDEBUG(file, line, function, ...)                                     \
  ORBIS_CORE_SOURCE_DEBUG(file, line, function, __VA_ARGS__)
#define LSINFO(file, line, function, ...)                                      \
  ORBIS_CORE_SOURCE_INFO(file, line, function, __VA_ARGS__)
#define LSWARN(file, line, function, ...)                                      \
  ORBIS_CORE_SOURCE_WARN(file, line, function, __VA_ARGS__)
#define LSERROR(file, line, function, ...)                                     \
  ORBIS_CORE_SOURCE_ERROR(file, line, function, __VA_ARGS__)
#define LSCRITICAL(file, line, function, ...)                                  \
  ORBIS_CORE_SOURCE_CRITICAL(file, line, function, __VA_ARGS__)
#define LSFATAL(file, line, function, ...)                                     \
  ORBIS_CORE_SOURCE_FATAL(file, line, function, __VA_ARGS__)

#define LCSTRACE(file, line, function, ...)                                    \
  ORBIS_CLIENT_SOURCE_TRACE(file, line, function, __VA_ARGS__)
#define LCSDEBUG(file, line, function, ...)                                    \
  ORBIS_CLIENT_SOURCE_DEBUG(file, line, function, __VA_ARGS__)
#define LCSINFO(file, line, function, ...)                                     \
  ORBIS_CLIENT_SOURCE_INFO(file, line, function, __VA_ARGS__)
#define LCSWARN(file, line, function, ...)                                     \
  ORBIS_CLIENT_SOURCE_WARN(file, line, function, __VA_ARGS__)
#define LCSERROR(file, line, function, ...)                                    \
  ORBIS_CLIENT_SOURCE_ERROR(file, line, function, __VA_ARGS__)
#define LCSCRITICAL(file, line, function, ...)                                 \
  ORBIS_CLIENT_SOURCE_CRITICAL(file, line, function, __VA_ARGS__)
#define LCSFATAL(file, line, function, ...)                                    \
  ORBIS_CLIENT_SOURCE_FATAL(file, line, function, __VA_ARGS__)

namespace orbis {
namespace logger {
enum LogLevel {
  TRACE = spdlog::level::trace,
  DEBUG = spdlog::level::debug,
  INFO = spdlog::level::info,
  WARN = spdlog::level::warn,
  ERR = spdlog::level::warn,
  CRITICAL = spdlog::level::critical,
  OFF = spdlog::level::off,
};

#ifdef __DEBUG__
bool initalize_logger(const LogLevel &console_level = DEBUG,
                      const LogLevel &file_level = TRACE);
#else
bool initalize_logger(const LogLevel &console_level = OFF,
                      const LogLevel &file_lavel = INFO);
#endif

std::shared_ptr<spdlog::logger> get_logger();

template <typename... _ARGS>
inline void trace(std::string fmt, const _ARGS &... args) {
  get_logger()->trace(fmt, args...);
}
template <typename... _ARGS>
inline void debug(std::string fmt, const _ARGS &... args) {
  get_logger()->debug(fmt, args...);
}
template <typename... _ARGS>
inline void info(std::string fmt, const _ARGS &... args) {
  get_logger()->info(fmt, args...);
}
template <typename... _ARGS>
inline void warn(std::string fmt, const _ARGS &... args) {
  get_logger()->warn(fmt, args...);
}
template <typename... _ARGS>
inline void error(std::string fmt, const _ARGS &... args) {
  get_logger()->error(fmt, args...);
}
template <typename... _ARGS>
inline void critical(std::string fmt, const _ARGS &... args) {
  get_logger()->info(fmt, args...);
}
} // namespace logger

} // namespace orbis

#endif // ORBIS_LOG_HPP_
