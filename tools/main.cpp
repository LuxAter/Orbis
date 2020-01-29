#include "log.hpp"

#include "gl.hpp"

#include <glm/glm.hpp>
using namespace glm;

int main(int argc, char const *argv[]) {
  orbis::logger::initalize_core_logger();
  orbis::logger::initalize_logger("GL");
  orbis::logger::initalize_logger("GLFW");
  if (!gl::init())
    return -1;
  gl::clearColor({1.0, 0.0, 1.0});
  while (!gl::shouldClose()) {
    gl::frame();
    if (glfwGetKey(gl::window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      gl::setShouldClose(true);
    }
  }
  gl::terminate();
  return 0;
}
