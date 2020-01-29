set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ORBIS_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ORBIS_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ORBIS_BINARY_DIR})

# ##############################################################################
# SOURCE FILES
# ##############################################################################
set(SOURCES log.cpp)
configure_file("${ORBIS_SOURCE_DIR}/include/orbis/version.hpp.in"
               "${ORBIS_SOURCE_DIR}/include/orbis/version.hpp")

# ##############################################################################
# STATIC TARGET
# ##############################################################################
if(NOT ORBIS_SHARED_LIB)
  add_library(orbis_static STATIC ${SOURCES})
  add_library(orbis::static ALIAS orbis_static)
  target_include_directories(orbis_static PUBLIC ${ORBIS_SOURCE_DIR}/include)

  set_target_properties(
    orbis_static
    PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS OFF)
  target_link_libraries(orbis_static PUBLIC spdlog fmt::fmt glm::glm
                                            ${CMAKE_DL_LIBS})
  install(TARGETS orbis_static ARCHIVE DESTINATION lib)
endif()

# ##############################################################################
# SHARED TARGET
# ##############################################################################
if(ORBIS_SHARED_LIB)
  add_library(orbis_shared SHARED ${SOURCES})
  add_library(orbis::shared ALIAS orbis_shared)
  target_include_directories(orbis_shared PUBLIC ${ORBIS_SOURCE_DIR}/include)

  set_target_properties(
    orbis_shared
    PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS OFF)
  target_link_libraries(orbis_shared PUBLIC spdlog fmt::fmt glm::glm
                                            ${CMAKE_DL_LIBS})
  install(TARGETS orbis_shared LIBRARY DESTINATION lib)
endif()

# ##############################################################################
# ALIASING
# ##############################################################################
if(ORBIS_SHARED_LIB)
  add_library(orbis::orbis ALIAS orbis_shared)
elseif()
  add_library(orbis::orbis ALIAS orbis_static)
endif()
