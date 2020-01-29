
#include "gl.hpp"

#include <orbis/image.hpp>
#include <orbis/log.hpp>

#include <glm/glm.hpp>
using namespace glm;

int main(int argc, char const *argv[]) {
  orbis::logger::initalize_core_logger();
  if (!gl::init())
    return -1;
  gl::clearColor({1.0, 0.0, 1.0});
  orbis::Image img(500, 500);
  for (auto y = 0; y < img.height; ++y) {
    for (auto x = 0; x < img.width; ++x) {
      img(y, x) = glm::vec3(x / (float)img.width, y / (float)img.height, 0.0f);
    }
  }
  while (!gl::shouldClose()) {
    gl::frame();
    gl::drawPixels(img);
    if (glfwGetKey(gl::window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      gl::setShouldClose(true);
    }
  }
  gl::terminate();
  return 0;
}
