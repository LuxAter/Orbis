set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ORBIS_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ORBIS_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ORBIS_BINARY_DIR})

# ##############################################################################
# SOURCE FILES
# ##############################################################################
set(SOURCES
    main.cpp
    gl.cpp
    gui.cpp
    glad/glad.c
    ${ORBIS_SOURCE_DIR}/external/imgui/imgui_demo.cpp
    ${ORBIS_SOURCE_DIR}/external/imgui/imgui_widgets.cpp
    ${ORBIS_SOURCE_DIR}/external/imgui/imgui_draw.cpp
    ${ORBIS_SOURCE_DIR}/external/imgui/imgui.cpp
    ${ORBIS_SOURCE_DIR}/external/imgui/examples/imgui_impl_glfw.cpp
    ${ORBIS_SOURCE_DIR}/external/imgui/examples/imgui_impl_opengl3.cpp)

# ##############################################################################
# TARGET
# ##############################################################################
add_executable(orbis ${SOURCES})
target_include_directories(orbis PUBLIC ${ORBIS_SOURCE_DIR}/tools)
target_include_directories(orbis PUBLIC ${ORBIS_SOURCE_DIR}/external/imgui)
target_include_directories(orbis
                           PUBLIC ${ORBIS_SOURCE_DIR}/external/imgui/examples)
target_include_directories(orbis
                           PUBLIC ${ORBIS_SOURCE_DIR}/external/zep/include)
target_compile_definitions(orbis PUBLIC -DIMGUI_IMPL_OPENGL_LOADER_GLAD)

set_target_properties(
  orbis PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS OFF)
target_link_libraries(orbis orbis::orbis glfw)
install(TARGETS orbis RUNTIME DESTINATION bin)
