# ##############################################################################
# Fetch Macro
# ##############################################################################
find_package(Git REQUIRED)
macro(load_submodule REPO_NAME)
  string(TOUPPER ${REPO_NAME} MODULE_NAME)
  if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${REPO_NAME}/.git)
    execute_process(
      COMMAND
        git submodule update --init --recursive --
        ${CMAKE_CURRENT_SOURCE_DIR}/${REPO_NAME})
  elseif(NOT GIT_FOUND)
    message(FATAL_ERROR "Git is required for submodules ${MODULE_NAME}")
  else()
    set(${MODULE_NAME}_FOUND TRUE)
  endif()
  if(${MODULE_NAME}_FOUND)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${REPO_NAME} EXCLUDE_FROM_ALL)
  endif()
endmacro()

# ##############################################################################
# DEPENDENCIES
# ##############################################################################
set(BUILD_STATIC_LIBS (NOT ${ORBIS_SHARED_LIB}))
set(BUILD_SHARED_LIBS ${ORBIS_SHARED_LIB})
option(SPDLOG_BUILD_SHARED "" ${ORBIS_SHARED_LIB})
option(GLFW_BUILD_EXAMPLES "" OFF)
option(GLFW_BUILD_TESTS "" OFF)
option(GLFW_BUILD_DOCS "" OFF)
option(GLFW_INSTALL "" OFF)
load_submodule(spdlog)
load_submodule(fmt)
load_submodule(glfw)
load_submodule(glm)