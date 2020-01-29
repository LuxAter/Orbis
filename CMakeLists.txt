# ##############################################################################
# PROJECT
# ##############################################################################
cmake_minimum_required(VERSION 3.11.0 FATAL_ERROR)
project(Orbis VERSION 0.0.0)
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  set(ORBIS_MAIN_PROJECT TRUE)
endif()

# ##############################################################################
# OPTIONS
# ##############################################################################
option(BUILD_DOCS "Compiles Orbis documentation" ON)
option(STATIC_ANALYSIS "Use compile type static analysis" OFF)
set(ORBIS_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(ORBIS_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
  option(ORBIS_SHARED_LIB "Compile shared libraries" OFF)
else()
  option(ORBIS_SHARED_LIB "Compile shared libraries" ON)
endif()

# ##############################################################################
# BUILD SETTINGS
# ##############################################################################
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D__DEBUG__")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE
      "Debug"
      CACHE STRING "BUILD MODE" FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
  if(EXISTS ${ORBIS_SOURCE_DIR}/compile_commands.json)
    execute_process(
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
              ${ORBIS_BINARY_DIR}/compile_commands.json
              ${ORBIS_SOURCE_DIR}/compile_commands.json)
  endif()
endif()

# ##############################################################################
# STATIC ANALYSIS
# ##############################################################################
if(STATIC_ANALYSIS)
  find_program(CLANG_TIDY_EXE NAMES clang-tidy)
  find_program(CPPCHECK_EXE NAMES cppcheck)
  find_program(CPPLINT_EXE NAMES cpplint)
  if(CLANG_TIDY_EXE)
    set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY_EXE})
  endif()
  if(CPPCHECK_EXE)
    set(CMAKE_CXX_CPPCHECK ${CPPCHECK_EXE})
  endif()
  if(CPPLINT_EXE)
    set(CMAKE_CXX_CPPLINT ${CPPLINT_EXE})
  endif()
endif()

# ##############################################################################
# DEPENDENCIES
# ##############################################################################
include(WriteCompilerDetectionHeader)
add_subdirectory(external)
set(ORBIS_COMPILERS MSVC GNU Clang Intel AppleClang)
write_compiler_detection_header(
  FILE
  ${ORBIS_SOURCE_DIR}/include/orbis/compilers.hpp
  PREFIX
  ORBIS
  COMPILERS
  ${ORBIS_COMPILERS}
  FEATURES
  cxx_constexpr
  cxx_noexcept
  cxx_static_assert
  cxx_attribute_deprecated)

# ##############################################################################
# LIBRARY
# ##############################################################################
add_subdirectory(src)

# ##############################################################################
# EXECUTABLE
# ##############################################################################
add_subdirectory(tools)

# ##############################################################################
# DOCUMENTATION
# ##############################################################################
if(BUILD_DOCS)
  find_package(Doxygen)
  if(Doxygen_FOUND)
    add_subdirectory(docs)
  endif()
endif()

# ##############################################################################
# PACKAGING
# ##############################################################################
if(CMAKE_BUILD_TYPE STREQUAL "Release")
  set(CPACK_GENERATOR "TGZ;ZIP")
  set(CPACK_PACKAGE_VENDOR "LuxAter")
  set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
  set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
  set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
  set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
  set(CPACK_RESOURCE_FILE_README ${CMAKE_CURRENT_SOURCE_DIR}/README.md)
  set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE)
  set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}-${CMAKE_SYSTEM_NAME}")
  set(CPACK_MONOLITHIC_INSTALL TRUE)
  include(CPack)
endif()
