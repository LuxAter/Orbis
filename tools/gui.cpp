#include "gui.hpp"

#include <memory>
#include <string>
#include <unordered_map>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <TextEditor.h>
#include <ImGuiFileDialog.h>

#include <orbis/log.hpp>

#include "fonts.hpp"
#include "gl.hpp"

namespace gui {
std::unordered_map<std::string, std::unordered_map<std::string, Variable>>
    variables;
std::unordered_map<std::string, Window> windows;
} // namespace gui

static auto lang = TextEditor::LanguageDefinition::CPlusPlus();
static std::unordered_map<std::string, TextEditor> editors;

void gui::open_editor(const std::string file) {
  windows[file] = Window{true, ImGuiWindowFlags_MenuBar, render_editor_window};
  TextEditor editor;
  editor.SetLanguageDefinition(lang);
  editor.SetText("");
  editors[file] = editor;
}

bool gui::init() {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

  void *font_data = std::malloc(FiraCode_Regular_ttf_size);
  memcpy(font_data, FiraCode_Regular_ttf, FiraCode_Regular_ttf_size);
  io.Fonts->AddFontFromMemoryTTF(font_data, FiraCode_Regular_ttf_size, 20.0f);

  ImGui_ImplGlfw_InitForOpenGL(gl::window, true);
  ImGui_ImplOpenGL3_Init("#version 410");

  windows["Variables"] = Window{true, 0, render_settings_window};
  // windows["test.cl"] =
  //     Window{true, ImGuiWindowFlags_MenuBar, render_editor_window};

  lang = TextEditor::LanguageDefinition::CPlusPlus();

  static const char *ppnames[] = {"__FILE__", "__LINE__",
                                  "__OPENCL_CPP_VERSION__", "__func__", "PI"};
  static const char *ppvalues[] = {
      "Current source file", "Integer line number", "Integer version number",
      "Current function name", "#define PI 3.14159265358979323846"};
  for (std::size_t i = 0; i < sizeof(ppnames) / sizeof(ppnames[0]); ++i) {
    TextEditor::Identifier id;
    id.mDeclaration = ppvalues[i];
    lang.mPreprocIdentifiers.insert(
        std::make_pair(std::string(ppnames[i]), id));
  }

  static const char *keywords[] = {
      "__kernel", "kernel",  "uchar",   "ushort", "uint",   "ulong",
      "bool2",    "bool3",   "bool4",   "char2",  "char3",  "char4",
      "uchar2",   "uchar3",  "uchar4",  "short2", "short3", "short4",
      "ushort2",  "ushort3", "ushort4", "int2",   "int3",   "int4",
      "uint2",    "uint3",   "uint4",   "long2",  "long3",  "long4",
      "ulong2",   "ulong3",  "ulong4",  "float2", "float3", "float4",
      "double2",  "double3", "double4"};
  for (auto &k : keywords) {
    lang.mKeywords.insert(k);
  }
  static const char *trig_functions[] = {
      "acos",  "acosh",  "acospi", "asin",    "asinh", "asinpi", "atan",
      "atan2", "atanh",  "atanpi", "atan2pi", "cos",   "cosh",   "cospi",
      "sin",   "sincos", "sinh",   "sinpi",   "tan",   "tanh",   "tanpi"};
  static const char *trig_docs[] = {"Arc cosine",
                                    "Inverse hyperbolic cosine",
                                    "Compute acos(x)/PI",
                                    "Arc sine",
                                    "Inverse hyperbolic sine",
                                    "Compute asin(x)/PI",
                                    "Arc tangent",
                                    "Arc tanget of y/x",
                                    "Hyperbolic arc tangent",
                                    "Compute atan(x)/PI",
                                    "Compute atan2(y, x)/PI",
                                    "Cosine, x is an angle",
                                    "Hyperbolic cosine",
                                    "Compute cos(PI x)",
                                    "Sine, x is an angle",
                                    "Sine and cosine value of x",
                                    "Hyperbolci sine",
                                    "sin(PI x)",
                                    "Tangent",
                                    "Hyperbolic tangent",
                                    "tan(PI x)"};
  for (std::size_t i = 0; i < sizeof(trig_functions) / sizeof(trig_docs[0]);
       ++i) {
    TextEditor::Identifier id;
    id.mDeclaration = std::string(trig_docs[i]);
    lang.mIdentifiers.insert(
        std::make_pair(std::string(trig_functions[i]), id));
  }
  static const char *power_functions[] = {"cbrt",  "pow",   "pown", "powr",
                                          "rootn", "rsqrt", "sqrt"};
  static const char *power_docs[] = {"Cube root",
                                     "Compute x to the power of y",
                                     "Compute x^y, where y is an integer",
                                     "Compute x^y, where x is >=0",
                                     "Compute x to the power of 1/y",
                                     "Inverse square root",
                                     "Square root"};
  for (std::size_t i = 0; i < sizeof(power_functions) / sizeof(power_docs[0]);
       ++i) {
    TextEditor::Identifier id;
    id.mDeclaration = std::string(power_docs[i]);
    lang.mIdentifiers.insert(
        std::make_pair(std::string(power_functions[i]), id));
  }

  lang.mName = "OpenCL C++";

  // editor.SetLanguageDefinition(lang);
  // editor.SetText("");

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
      if (ImGui::BeginMenu("Editor")) {
        if (ImGui::MenuItem("New File", "Ctrl-N")) {
          ImGuiFileDialog::Instance()->OpenDialog(
              "ChooseFileDlgKey", "Choose File", ".cl\0.gpu\0\0", ".");
        }
        if (ImGui::MenuItem("Open File", "Ctrl-O")) {
        }
        ImGui::Separator();
        for (auto &editor : editors) {
          ImGui::MenuItem(editor.first.c_str(), NULL,
                          &windows[editor.first].display_state);
        }
        ImGui::EndMenu();
      }
      ImGui::EndMenu();
    }
    ImGui::EndMenuBar();
  }
  ImGui::End();

  if (ImGuiFileDialog::Instance()->FileDialog("ChooseFileDlgKey")) {
    if (ImGuiFileDialog::Instance()->IsOk == true) {
      std::string filePathName = ImGuiFileDialog::Instance()->GetFilepathName();
      std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();
      LINFO("Opening FILE: {}/{}", filePathName, filePath);
      open_editor(filePathName);
    }
    ImGuiFileDialog::Instance()->CloseDialog("ChooseFileDlgKey");
  }

  // ImGui::ShowDemoWindow(&demo_window);
  render_windows();

  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void gui::render_editor_window(const std::string &name) {
  auto &editor = editors[name];
  if (ImGui::BeginMenuBar()) {
    if (ImGui::BeginMenu("File")) {
      if (ImGui::MenuItem("Save")) {
        // Save text here
      }
      if (ImGui::MenuItem("Quit", "Alt-F4")) {
      }
      ImGui::EndMenu();
    }
    if (ImGui::BeginMenu("Edit")) {
      bool ro = editor.IsReadOnly();
      if (ImGui::MenuItem("Read-only mode", nullptr, &ro)) {
        editor.SetReadOnly(ro);
      }
      ImGui::Separator();
      if (ImGui::MenuItem("Copy", "Ctrl-C", nullptr, editor.HasSelection()))
        editor.Copy();
      if (ImGui::MenuItem("Cut", "Ctrl-X", nullptr,
                          !ro && editor.HasSelection()))
        editor.Cut();
      if (ImGui::MenuItem("Delete", "Del", nullptr,
                          !ro && editor.HasSelection()))
        editor.Delete();
      if (ImGui::MenuItem("Paste", "Ctrl-V", nullptr,
                          !ro && ImGui::GetClipboardText() != nullptr))
        editor.Paste();
      ImGui::Separator();
      if (ImGui::MenuItem("Select all", nullptr, nullptr))
        editor.SetSelection(TextEditor::Coordinates(),
                            TextEditor::Coordinates(editor.GetTotalLines(), 0));
      ImGui::EndMenu();
    }
    if (ImGui::BeginMenu("View")) {
      if (ImGui::MenuItem("Dark palette"))
        editor.SetPalette(TextEditor::GetDarkPalette());
      if (ImGui::MenuItem("Light palette"))
        editor.SetPalette(TextEditor::GetLightPalette());
      if (ImGui::MenuItem("Retro blue palette"))
        editor.SetPalette(TextEditor::GetRetroBluePalette());
      ImGui::EndMenu();
    }
    ImGui::EndMenuBar();
  }
  auto cpos = editor.GetCursorPosition();
  ImGui::Text("%6d/%-6d %6d lines  | %s | %s | %s | %s", cpos.mLine + 1,
              cpos.mColumn + 1, editor.GetTotalLines(),
              editor.IsOverwrite() ? "Ovr" : "Ins",
              editor.CanUndo() ? "*" : " ",
              editor.GetLanguageDefinition().mName.c_str(), name.c_str());
  editor.Render("TextEditor");
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
        ImGui::Begin(window.first.c_str(), &window.second.display_state,
                     window.second.window_flags);
        window.second.render_callback(window.first);
        ImGui::End();
      }
    }
  }
}
