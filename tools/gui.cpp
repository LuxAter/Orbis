#include "gui.hpp"

#include <memory>
#include <string>
#include <unordered_map>

namespace gui {
std::unordered_map<std::string, std::unordered_map<std::string, Variable>>
    variables;
std::unordered_map<std::string, Window> windows;
} // namespace gui

static bool profiler_window = false;

bool gui::init() {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  ImGui_ImplGlfw_InitForOpenGL(gl::window, true);
  ImGui_ImplOpenGL3_Init("#version 410");

  windows["Variables"] = Window{true, render_settings_window};

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

  ImGuiViewport *viewport = ImGui::GetMainViewport();
  ImGui::SetNextWindowPos(viewport->Pos);
  ImGui::SetNextWindowSize(viewport->Size);
  ImGui::SetNextWindowViewport(viewport->ID);
  ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
  ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
  ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

  bool p_open;
  ImGui::Begin("Orbis", &p_open,
               ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking |
                   ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
                   ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                   ImGuiWindowFlags_NoBringToFrontOnFocus |
                   ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoBackground);
  ImGui::PopStyleVar(3);
  ImGuiID dockspace_id = ImGui::GetID("OrbisDockSpace");
  ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f),
                   ImGuiDockNodeFlags_PassthruCentralNode);

  if (ImGui::BeginMenuBar()) {
    ImGui::MenuItem("File", NULL, false, false);
    if (ImGui::BeginMenu("Windows")) {
      ImGui::MenuItem("Variables", NULL, &windows["Variables"].display_state);
      ImGui::MenuItem("Profiler", NULL, &profiler_window);
      ImGui::EndMenu();
    }
    ImGui::EndMenuBar();
  }
  ImGui::End();

  // ImGui::ShowDemoWindow(&demo_window);
  render_windows();

  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void gui::render_settings_window(const std::string &name) {
  for (auto &group : variables) {
    if (ImGui::CollapsingHeader(group.first.c_str())) {
      for (auto &var : group.second) {
        switch (var.second.type) {
        case Variable::VAR_FLOAT: {
          if (ImGui::DragFloat(var.first.c_str(),
                               reinterpret_cast<float *>(var.second.val)) &&
              var.second.callback != nullptr) {
            reinterpret_cast<void (*)(float *)>(var.second.callback)(
                reinterpret_cast<float *>(var.second.val));
          }
          break;
        }
        case Variable::VAR_INT: {
          if (ImGui::DragInt(var.first.c_str(),
                             reinterpret_cast<int *>(var.second.val)) &&
              var.second.callback != nullptr) {
            reinterpret_cast<void (*)(int *)>(var.second.callback)(
                reinterpret_cast<int *>(var.second.val));
          }
          break;
        }
        case Variable::VAR_VEC3: {
          if (ImGui::DragFloat3(var.first.c_str(),
                                reinterpret_cast<float *>(var.second.val)) &&
              var.second.callback != nullptr) {
            reinterpret_cast<void (*)(glm::vec3 *)>(var.second.callback)(
                reinterpret_cast<glm::vec3 *>(var.second.val));
          }
          break;
        }
        case Variable::VAR_COLOR: {
          if (ImGui::ColorEdit4(var.first.c_str(),
                                reinterpret_cast<float *>(var.second.val)) &&
              var.second.callback != nullptr) {
            reinterpret_cast<void (*)(glm::vec4 *)>(var.second.callback)(
                reinterpret_cast<glm::vec4 *>(var.second.val));
          }
          break;
        }
        }
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