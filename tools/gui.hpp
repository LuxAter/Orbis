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
enum DisplayMode { DM_INPUT, DM_DRAG, DM_SLIDER, DM_COLOR };
template <typename T, typename U = T> struct Variable {
  DisplayMode disp;
  T *val;
  U *v_min, *v_max;
  void (*callback)(T *);
};

struct Window {
  bool display_state;
  void (*render_callback)(const std::string &);
};
extern std::unordered_map<std::string, std::unordered_map<std::string, void *>>
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

template <typename T> void display(const std::string &name, Variable<T> *var) {}
template <> void display<int>(const std::string &name, Variable<int> *var) {
  switch (var->disp) {
  case DM_INPUT:
    if (ImGui::InputInt(name.c_str(), var->val) && var->callback != nullptr)
      var->callback(var->val);
    break;
  case DM_DRAG:
    if (ImGui::DragInt(name.c_str(), var->val) && var->callback != nullptr)
      var->callback(var->val);
    break;
  case DM_SLIDER:
    if (ImGui::SliderInt(name.c_str(), var->val, *(var->v_min),
                         *(var->v_max)) &&
        var->callback != nullptr)
      var->callback(var->val);
    break;
  case DM_COLOR:
  default:
    ImGui::Text("%s: %d", name.c_str(), *(var->val));
  }
}
template <> void display<float>(const std::string &name, Variable<float> *var) {
  switch (var->disp) {
  case DM_INPUT:
    if (ImGui::InputFloat(name.c_str(), var->val) && var->callback != nullptr)
      var->callback(var->val);
    break;
  case DM_DRAG:
    if (ImGui::DragFloat(name.c_str(), var->val) && var->callback != nullptr)
      var->callback(var->val);
    break;
  case DM_SLIDER:
    if (ImGui::SliderFloat(name.c_str(), var->val, *(var->v_min),
                           *(var->v_max)) &&
        var->callback != nullptr)
      var->callback(var->val);
    break;
  case DM_COLOR:
  default:
    ImGui::Text("%s: %f", name.c_str(), *(var->val));
  }
}

template <typename T, typename U>
void addVar(const std::string &name, const Variable<T, U> &var) {
  variables["Global"][name] = reinterpret_cast<void *>(&var);
}

} // namespace gui

#endif // ORBIS_GUI_HPP_