#include "gl.hpp"

#include "log.hpp"

void glfwErrorCallback(int error, const char *description) {
  LCERROR("GLFW", "[{}] {}", error, description);
}

namespace gl {
GLFWwindow *window = nullptr;
}

bool gl::init() {
  if (!glfwInit()) {
    LCERROR("GLFW", "GLFW initalization failed");
    return false;
  } else {
    LCINFO("GLFW", "Initalized GLFW");
  }
  glfwSetErrorCallback(glfwErrorCallback);
  window = glfwCreateWindow(500, 500, "Orbis", NULL, NULL);
  if (!window) {
    LCERROR("GLFW", "Failed to construct GLFW window");
    glfwTerminate();
  }
  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    LCERROR("GL", "Failed to initalize OpenGL context");
    glfwDestroyWindow(window);
    glfwTerminate();
    return false;
  }
  //   gladLoadGL(glfwGetProcAddress);
  glfwSwapInterval(1);
  return true;
}

bool gl::shouldClose() { return glfwWindowShouldClose(window); }
void gl::setShouldClose(bool setting) {
  glfwSetWindowShouldClose(window, setting ? GLFW_TRUE : GLFW_FALSE);
}
void gl::frame() {
  glfwSwapBuffers(window);
  glfwPollEvents();
  clear();
}

void gl::terminate() {
  if (window) {
    glfwDestroyWindow(window);
  }
  glfwTerminate();
}

bool gl::getKey(const int &key) {
  return glfwGetKey(gl::window, key) == GLFW_PRESS;
}
void gl::clearColor(const glm::vec3 &c) { glClearColor(c.r, c.g, c.b, 0.0f); }
void gl::clearColor(const glm::vec4 &c) { glClearColor(c.r, c.g, c.b, c.a); }
void gl::clear() { glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); }
void gl::clear(const glm::vec3 &c) {
  glClearColor(c.r, c.g, c.b, 0.0f);
  clear();
}