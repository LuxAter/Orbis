#ifndef ORBIS_LOG_HPP_
#define ORBIS_LOG_HPP_

#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>

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
  ORBIS_LOGGER_TRACE(orbis::logger::get_core(), __VA_ARGS__)
#define ORBIS_CLIENT_TRACE(client, ...)                                        \
  ORBIS_LOGGER_TRACE(orbis::logger::get_client(client), __VA_ARGS__)
#define ORBIS_CORE_DEBUG(...)                                                  \
  ORBIS_LOGGER_DEBUG(orbis::logger::get_core(), __VA_ARGS__)
#define ORBIS_CLIENT_DEBUG(client, ...)                                        \
  ORBIS_LOGGER_DEBUG(orbis::logger::get_client(client), __VA_ARGS__)
#define ORBIS_CORE_INFO(...)                                                   \
  ORBIS_LOGGER_INFO(orbis::logger::get_core(), __VA_ARGS__)
#define ORBIS_CLIENT_INFO(client, ...)                                         \
  ORBIS_LOGGER_INFO(orbis::logger::get_client(client), __VA_ARGS__)
#define ORBIS_CORE_WARN(...)                                                   \
  ORBIS_LOGGER_WARN(orbis::logger::get_core(), __VA_ARGS__)
#define ORBIS_CLIENT_WARN(client, ...)                                         \
  ORBIS_LOGGER_WARN(orbis::logger::get_client(client), __VA_ARGS__)
#define ORBIS_CORE_ERROR(...)                                                  \
  ORBIS_LOGGER_ERROR(orbis::logger::get_core(), __VA_ARGS__)
#define ORBIS_CLIENT_ERROR(client, ...)                                        \
  ORBIS_LOGGER_ERROR(orbis::logger::get_client(client), __VA_ARGS__)
#define ORBIS_CORE_CRITICAL(...)                                               \
  ORBIS_LOGGER_CRITICAL(orbis::logger::get_core(), __VA_ARGS__)
#define ORBIS_CLIENT_CRITICAL(client, ...)                                     \
  ORBIS_LOGGER_CRITICAL(orbis::logger::get_client(client), __VA_ARGS__)
#define ORBIS_CORE_FATAL(...)                                                  \
  ORBIS_LOGGER_FATAL(orbis::logger::get_core(), __VA_ARGS__)
#define ORBIS_CLIENT_FATAL(client, ...)                                        \
  ORBIS_LOGGER_FATAL(orbis::logger::get_client(client), __VA_ARGS__)

#define ORBIS_CORE_SOURCE_TRACE(file, line, function, ...)                     \
  ORBIS_LOGGER_SOURCE_TRACE(orbis::logger::get_core(), file, line, function,   \
                            __VA_ARGS__)
#define ORBIS_CLIENT_SOURCE_TRACE(client, file, line, function, ...)           \
  ORBIS_LOGGER_SOURCE_TRACE(orbis::logger::get_client(client), file, line,     \
                            function, __VA_ARGS__)
#define ORBIS_CORE_SOURCE_DEBUG(file, line, function, ...)                     \
  ORBIS_LOGGER_SOURCE_DEBUG(orbis::logger::get_core(), file, line, function,   \
                            __VA_ARGS__)
#define ORBIS_CLIENT_SOURCE_DEBUG(client, file, line, function, ...)           \
  ORBIS_LOGGER_SOURCE_DEBUG(orbis::logger::get_client(client), file, line,     \
                            function, __VA_ARGS__)
#define ORBIS_CORE_SOURCE_INFO(file, line, function, ...)                      \
  ORBIS_LOGGER_SOURCE_INFO(orbis::logger::get_core(), file, line, function,    \
                           __VA_ARGS__)
#define ORBIS_CLIENT_SOURCE_INFO(client, file, line, function, ...)            \
  ORBIS_LOGGER_SOURCE_INFO(orbis::logger::get_client(client), file, line,      \
                           function, __VA_ARGS__)
#define ORBIS_CORE_SOURCE_WARN(file, line, function, ...)                      \
  ORBIS_LOGGER_SOURCE_WARN(orbis::logger::get_core(), file, line, function,    \
                           __VA_ARGS__)
#define ORBIS_CLIENT_SOURCE_WARN(client, file, line, function, ...)            \
  ORBIS_LOGGER_SOURCE_WARN(orbis::logger::get_client(client), file, line,      \
                           function, __VA_ARGS__)
#define ORBIS_CORE_SOURCE_ERROR(file, line, function, ...)                     \
  ORBIS_LOGGER_SOURCE_ERROR(orbis::logger::get_core(), file, line, function,   \
                            __VA_ARGS__)
#define ORBIS_CLIENT_SOURCE_ERROR(client, file, line, function, ...)           \
  ORBIS_LOGGER_SOURCE_ERROR(orbis::logger::get_client(client), file, line,     \
                            function, __VA_ARGS__)
#define ORBIS_CORE_SOURCE_CRITICAL(file, line, function, ...)                  \
  ORBIS_LOGGER_SOURCE_CRITICAL(orbis::logger::get_core(), file, line,          \
                               function, __VA_ARGS__)
#define ORBIS_CLIENT_SOURCE_CRITICAL(client, file, line, function, ...)        \
  ORBIS_LOGGER_SOURCE_CRITICAL(orbis::logger::get_client(client), file, line,  \
                               function, __VA_ARGS__)
#define ORBIS_CORE_SOURCE_FATAL(file, line, function, ...)                     \
  ORBIS_LOGGER_SOURCE_FATAL(orbis::logger::get_core(), file, line, function,   \
                            __VA_ARGS__)
#define ORBIS_CLIENT_SOURCE_FATAL(client, file, line, function, ...)           \
  ORBIS_LOGGER_SOURCE_FATAL(orbis::logger::get_client(client), file, line,     \
                            function, __VA_ARGS__)

#define LTRACE(...) ORBIS_CORE_TRACE(__VA_ARGS__)
#define LDEBUG(...) ORBIS_CORE_DEBUG(__VA_ARGS__)
#define LINFO(...) ORBIS_CORE_INFO(__VA_ARGS__)
#define LWARN(...) ORBIS_CORE_WARN(__VA_ARGS__)
#define LERROR(...) ORBIS_CORE_ERROR(__VA_ARGS__)
#define LCRITICAL(...) ORBIS_CORE_CRITICAL(__VA_ARGS__)
#define LFATAL(...) ORBIS_CORE_FATAL(__VA_ARGS__)

#define LCTRACE(client, ...) ORBIS_CLIENT_TRACE(client, __VA_ARGS__)
#define LCDEBUG(client, ...) ORBIS_CLIENT_DEBUG(client, __VA_ARGS__)
#define LCINFO(client, ...) ORBIS_CLIENT_INFO(client, __VA_ARGS__)
#define LCWARN(client, ...) ORBIS_CLIENT_WARN(client, __VA_ARGS__)
#define LCERROR(client, ...) ORBIS_CLIENT_ERROR(client, __VA_ARGS__)
#define LCCRITICAL(client, ...) ORBIS_CLIENT_CRITICAL(client, __VA_ARGS__)
#define LCFATAL(client, ...) ORBIS_CLIENT_FATAL(client, __VA_ARGS__)

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

#define LCSTRACE(client, file, line, function, ...)                            \
  ORBIS_CLIENT_SOURCE_TRACE(client, file, line, function, __VA_ARGS__)
#define LCSDEBUG(client, file, line, function, ...)                            \
  ORBIS_CLIENT_SOURCE_DEBUG(client, file, line, function, __VA_ARGS__)
#define LCSINFO(client, file, line, function, ...)                             \
  ORBIS_CLIENT_SOURCE_INFO(client, file, line, function, __VA_ARGS__)
#define LCSWARN(client, file, line, function, ...)                             \
  ORBIS_CLIENT_SOURCE_WARN(client, file, line, function, __VA_ARGS__)
#define LCSERROR(client, file, line, function, ...)                            \
  ORBIS_CLIENT_SOURCE_ERROR(client, file, line, function, __VA_ARGS__)
#define LCSCRITICAL(client, file, line, function, ...)                         \
  ORBIS_CLIENT_SOURCE_CRITICAL(client, file, line, function, __VA_ARGS__)
#define LCSFATAL(client, file, line, function, ...)                            \
  ORBIS_CLIENT_SOURCE_FATAL(client, file, line, function, __VA_ARGS__)

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
bool initalize_core_logger(const LogLevel &console_level = DEBUG,
                           const LogLevel &file_level = TRACE);
bool initalize_logger(const std::string &name,
                      const LogLevel &console_level = DEBUG,
                      const LogLevel &file_level = TRACE);
#else
bool initalize_core_logger(const LogLevel &console_level = OFF,
                           const LogLevel &file_lavel = INFO);
bool initalize_logger(const std::string &name,
                      const LogLevel &console_level = OFF,
                      const LogLevel &file_lavel = INFO);
#endif
bool terminate_logger(const std::string &name);

std::shared_ptr<spdlog::logger> get_core();
std::shared_ptr<spdlog::logger> get_client(const std::string &name);

namespace core {
template <typename... _ARGS>
inline void trace(std::string fmt, const _ARGS &... args) {
  get_core()->trace(fmt, args...);
}
template <typename... _ARGS>
inline void debug(std::string fmt, const _ARGS &... args) {
  get_core()->debug(fmt, args...);
}
template <typename... _ARGS>
inline void info(std::string fmt, const _ARGS &... args) {
  get_core()->info(fmt, args...);
}
template <typename... _ARGS>
inline void warn(std::string fmt, const _ARGS &... args) {
  get_core()->warn(fmt, args...);
}
template <typename... _ARGS>
inline void error(std::string fmt, const _ARGS &... args) {
  get_core()->error(fmt, args...);
}
template <typename... _ARGS>
inline void critical(std::string fmt, const _ARGS &... args) {
  get_core()->info(fmt, args...);
}
} // namespace core
namespace client {
template <typename... _ARGS>
inline void trace(const std::string &logger, std::string fmt,
                  const _ARGS &... args) {
  get_client(logger)->trace(fmt, args...);
}
template <typename... _ARGS>
inline void debug(const std::string &logger, std::string fmt,
                  const _ARGS &... args) {
  get_client(logger)->debug(fmt, args...);
}
template <typename... _ARGS>
inline void info(const std::string &logger, std::string fmt,
                 const _ARGS &... args) {
  get_client(logger)->info(fmt, args...);
}
template <typename... _ARGS>
inline void warn(const std::string &logger, std::string fmt,
                 const _ARGS &... args) {
  get_client(logger)->warn(fmt, args...);
}
template <typename... _ARGS>
inline void error(const std::string &logger, std::string fmt,
                  const _ARGS &... args) {
  get_client(logger)->error(fmt, args...);
}
template <typename... _ARGS>
inline void critical(const std::string &logger, std::string fmt,
                     const _ARGS &... args) {
  get_client(logger)->info(fmt, args...);
}
} // namespace client
} // namespace logger
} // namespace orbis

#endif // ORBIS_LOG_HPP_
