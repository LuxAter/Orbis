#ifndef ORBIS_GUI_HPP_
#define ORBIS_GUI_HPP_

#include <glm/glm.hpp>
#include <string>
#include <unordered_map>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "gl.hpp"

namespace gui {
struct Variable {
  std::string type;
  void *data;
};
extern std::unordered_map<std::string,
                          std::unordered_map<std::string, Variable>>
    variables;

// template <typename T> void addVar(const std::string &name, T *ptr) {
//   variables["Global"][name] = Variable{"string", reinterpret_cast<void
//   *>(ptr)};
// }
// template <> void addVar(const std::string &name, std::string *ptr) {
//   variables["Global"][name] = Variable{"string", reinterpret_cast<void
//   *>(ptr)};
// }
// template <> void addVar(const std::string &name, glm::vec3 *ptr) {
//   variables["Global"][name] = Variable{"vec3", reinterpret_cast<void
//   *>(ptr)};
// }
// template <> void addVar(const std::string &name, glm::vec4 *ptr) {
//   variables["Global"][name] = Variable{"vec4", reinterpret_cast<void
//   *>(ptr)};
// }
bool init();
void terminate();
void frame();
} // namespace gui

#endif // ORBIS_GUI_HPP_