#ifndef ORBIS_GUI_HPP_
#define ORBIS_GUI_HPP_

#include <glm/glm.hpp>
#include <memory>
#include <string>
#include <unordered_map>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <memory>

#include "gl.hpp"

namespace gui {
struct Variable {
  enum VariableType { VAR_FLOAT, VAR_INT, VAR_VEC3, VAR_COLOR };
  VariableType type;
  void *val;
  void *callback;
};

struct Window {
  bool display_state;
  void (*render_callback)(const std::string &);
};
extern std::unordered_map<std::string,
                          std::unordered_map<std::string, Variable>>
    variables;
extern std::unordered_map<std::string, Window> windows;

inline void create_window(const std::string name,
                          void (*callback)(const std::string &)) {
  windows[name] = Window{true, callback};
}

bool init();
void terminate();
void frame();

void render_settings_window(const std::string &name);
void render_windows();

inline void addVar(const std::string &name, float *var,
                   void (*callback)(float *) = nullptr) {
  variables["Global"][name] =
      Variable{Variable::VAR_FLOAT, reinterpret_cast<void *>(var),
               reinterpret_cast<void *>(callback)};
}
inline void addVar(const std::string &name, int *var,
                   void (*callback)(int *) = nullptr) {
  variables["Global"][name] =
      Variable{Variable::VAR_INT, reinterpret_cast<void *>(var),
               reinterpret_cast<void *>(callback)};
}
inline void addVar(const std::string &name, glm::vec3 *var,
                   void (*callback)(glm::vec3 *) = nullptr) {
  variables["Global"][name] =
      Variable{Variable::VAR_VEC3, reinterpret_cast<void *>(var),
               reinterpret_cast<void *>(callback)};
}
inline void addVar(const std::string &name, glm::vec4 *var,
                   void (*callback)(glm::vec4 *) = nullptr) {
  variables["Global"][name] =
      Variable{Variable::VAR_COLOR, reinterpret_cast<void *>(var),
               reinterpret_cast<void *>(callback)};
}
inline void addVar(const std::string &group, const std::string &name,
                   float *var, void (*callback)(float *) = nullptr) {
  variables[group][name] =
      Variable{Variable::VAR_FLOAT, reinterpret_cast<void *>(var),
               reinterpret_cast<void *>(callback)};
}
inline void addVar(const std::string &group, const std::string &name, int *var,
                   void (*callback)(int *) = nullptr) {
  variables[group][name] =
      Variable{Variable::VAR_INT, reinterpret_cast<void *>(var),
               reinterpret_cast<void *>(callback)};
}
inline void addVar(const std::string &group, const std::string &name,
                   glm::vec3 *var, void (*callback)(glm::vec3 *) = nullptr) {
  variables[group][name] =
      Variable{Variable::VAR_VEC3, reinterpret_cast<void *>(var),
               reinterpret_cast<void *>(callback)};
}
inline void addVar(const std::string &group, const std::string &name,
                   glm::vec4 *var, void (*callback)(glm::vec4 *) = nullptr) {
  variables[group][name] =
      Variable{Variable::VAR_COLOR, reinterpret_cast<void *>(var),
               reinterpret_cast<void *>(callback)};
}

} // namespace gui

#endif // ORBIS_GUI_HPP_