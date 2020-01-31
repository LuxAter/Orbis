set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ORBIS_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ORBIS_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ORBIS_BINARY_DIR})

# ##############################################################################
# SOURCE FILES
# ##############################################################################
file(GLOB FONT_FILES ${ORBIS_SOURCE_DIR}/resources/*.ttf)
add_custom_command(
  OUTPUT ${ORBIS_SOURCE_DIR}/tools/fonts.hpp
  COMMAND ${ORBIS_SOURCE_DIR}/resources/compile_resource.sh
          ${ORBIS_SOURCE_DIR}/tools/fonts.hpp ${ORBIS_SOURCE_DIR}/resources ttf
  DEPENDS ${FONT_FILES}
  COMMENT "Compiling fonts")
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
    ${ORBIS_SOURCE_DIR}/external/imgui/examples/imgui_impl_opengl3.cpp
    ${ORBIS_SOURCE_DIR}/external/ImGuiColorTextEdit/TextEditor.cpp
    ${ORBIS_SOURCE_DIR}/external/ImGuiFileDialog/ImGuiFileDialog.cpp
    ${ORBIS_SOURCE_DIR}/tools/fonts.hpp)

# ##############################################################################
# TARGET
# ##############################################################################
add_executable(orbis ${SOURCES})
target_include_directories(orbis PUBLIC ${ORBIS_SOURCE_DIR}/tools)
target_include_directories(orbis PUBLIC ${ORBIS_SOURCE_DIR}/external/imgui)
target_include_directories(orbis
                           PUBLIC ${ORBIS_SOURCE_DIR}/external/imgui/examples)
target_include_directories(
  orbis PUBLIC ${ORBIS_SOURCE_DIR}/external/ImGuiColorTextEdit)
target_include_directories(
  orbis PUBLIC ${ORBIS_SOURCE_DIR}/external/ImGuiFileDialog)
target_compile_definitions(orbis PUBLIC -DIMGUI_IMPL_OPENGL_LOADER_GLAD)
target_compile_definitions(orbis PUBLIC -DLINUX -DUNIX)

set_target_properties(
  orbis PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS OFF)
target_link_libraries(orbis orbis::orbis glfw)
install(TARGETS orbis RUNTIME DESTINATION bin)
