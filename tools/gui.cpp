#include "gui.hpp"

#include <memory>
#include <string>
#include <unordered_map>

namespace gui {
std::unordered_map<std::string, std::unordered_map<std::string, void *>>
    variables;
std::unordered_map<std::string, Window> windows;
} // namespace gui

static bool demo_window = true;

bool gui::init() {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  ImGui_ImplGlfw_InitForOpenGL(gl::window, true);
  ImGui_ImplOpenGL3_Init("#version 410");

  windows["Settings"] = Window{true, render_settings_window};

  return true;
}
void gui::terminate() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}
void gui::frame() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  ImGui::ShowDemoWindow(&demo_window);
  render_windows();

  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void gui::render_settings_window(const std::string &name) {
  for (auto &group : variables) {
    if (ImGui::CollapsingHeader(group.first.c_str())) {
      for (auto &var : group.second) {
        display(var.first, reinterpret_cast<Variable *>(var.second));
        // reinterpret_cast<Variable *>(var.second)->display(var.first);
      }
    }
  }
}

void gui::render_windows() {
  for (auto &window : windows) {
    if (window.second.render_callback != nullptr) {
      if (window.second.display_state) {
        ImGui::Begin(window.first.c_str(), &window.second.display_state);
        window.second.render_callback(window.first);
        ImGui::End();
      }
    }
  }
}