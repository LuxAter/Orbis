#include "log.hpp"

#include "gl.hpp"

void glfw_error_callback(int error, const char *description) {
  LCERROR("GLFW", "[{}] {}", error, description);
}

int main(int argc, char const *argv[]) {
  orbis::logger::initalize_core_logger();
  orbis::logger::initalize_logger("GLFW");
  if (!glfwInit()) {
    LCERROR("GLFW", "GLFW initalization failed");
  } else {
    LCINFO("GLFW", "Initalized GLFW");
  }
  glfwSetErrorCallback(glfw_error_callback);
  glfwTerminate();
  return 0;
}
