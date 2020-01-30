
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
  float v1;
  float v1min = -100, v1max = 100;
  gui::addVar("Float Input", gui::Variable<float>{gui::DM_INPUT, &v1});
  // gui::addFloatInput("Float input", &v1, [](float *v) { LINFO("V1: {}",
  // *v); }); gui::addFloatDrag("Float drag", &v1, [](float *v) { LINFO("V1:
  // {}", *v); }); gui::addFloatSlider("Float slide", &v1, &v1min, &v1max,
  //                     [](float *v) { LINFO("V1: {}", *v); });
  // gui::addFloatDrag("V1 min", &v1min);
  // gui::addVar("Test", &f, [](void *f) { LINFO("F: {}", *((float *)f));
  // }); gui::addVar("glClearColor", &clear_color,
  //             [](void *c) { gl::clearColor(*(vec3 *)(c)); });
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
