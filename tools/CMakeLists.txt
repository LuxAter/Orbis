set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ORBIS_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ORBIS_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ORBIS_BINARY_DIR})

# ##############################################################################
# SOURCE FILES
# ##############################################################################
set(SOURCES main.cpp)

# ##############################################################################
# TARGET
# ##############################################################################
add_executable(orbis ${SOURCES})
target_include_directories(orbis PUBLIC ${ORBIS_SOURCE_DIR}/tools)

set_target_properties(orbis PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED
                                                         YES CXX_EXTENSIONS OFF)
target_link_libraries(orbis orbis::orbis)
install(TARGETS orbis RUNTIME DESTINATION bin)
