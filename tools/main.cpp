
#include "gl.hpp"

#include <orbis/image.hpp>
#include <orbis/log.hpp>

#include <glm/glm.hpp>
using namespace glm;

#include "gui.hpp"

int main(int argc, char const *argv[]) {
  orbis::logger::initalize_core_logger();
  if (!gl::init())
    return -1;
  gl::clearColor({0.0, 0.0, 0.0});
  orbis::Image img(500, 500);
  for (auto y = 0; y < img.height; ++y) {
    for (auto x = 0; x < img.width; ++x) {
      img(y, x) = glm::vec3(x / (float)img.width, y / (float)img.height, 0.0f);
    }
  }
  gui::init();
  float v1 = 0.0f;
  int v2 = 0;
  glm::vec3 v3(0);
  glm::vec4 clear_color(0);
  gui::addVar("V1", &v1, [](float *v) { LINFO("V1: {}", *v); });
  gui::addVar("V2", &v2);
  gui::addVar("V3", &v3);
  gui::addVar("clearColor", &clear_color,
              [](glm::vec4 *color) { gl::clearColor(*color); });
  gui::addVar("Scene", "background", &clear_color);
  while (!gl::shouldClose()) {
    gl::frame();
    gui::frame();
    if (gl::getKey(GLFW_KEY_ESCAPE)) {
      gl::setShouldClose(true);
    }
  }
  gui::terminate();
  gl::terminate();
  return 0;
}
