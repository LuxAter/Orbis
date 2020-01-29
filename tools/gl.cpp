#include "gl.hpp"

#include <chrono>

#include <orbis/image.hpp>
#include <orbis/log.hpp>

void glfwErrorCallback(int error, const char *description) {
  LCERROR("OpenGL", "[{}] {}", error, description);
}

static std::chrono::high_resolution_clock::time_point fps_start;
static std::size_t fps_counter = 0;
#ifdef __DEBUG__
static std::size_t fps_report_interval = 10;
#else
static std::size_t fps_report_interval = 60;
#endif

namespace gl {
GLFWwindow *window = nullptr;
}

bool gl::init() {
  orbis::logger::initalize_logger("OpenGL");
  if (!glfwInit()) {
    LCERROR("OpenGL", "GLFW initalization failed");
    return false;
  } else {
    LCINFO("OpenGL", "Initalized GLFW");
  }
  glfwSetErrorCallback(glfwErrorCallback);
  window = glfwCreateWindow(500, 500, "Orbis", NULL, NULL);
  if (!window) {
    LCERROR("OpenGL", "Failed to construct GLFW window");
    glfwTerminate();
  }
  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    LCERROR("OpenGL", "Failed to initalize OpenGL context");
    glfwDestroyWindow(window);
    glfwTerminate();
    return false;
  }
  glfwSwapInterval(1);
  fps_start = std::chrono::high_resolution_clock::now();
  fps_counter = 0;
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
  fps_counter++;
  if (fps_counter % 10 == 0) {
    std::chrono::high_resolution_clock::time_point now =
        std::chrono::high_resolution_clock::now();
    std::size_t duration =
        std::chrono::duration_cast<std::chrono::seconds>(now - fps_start)
            .count();
    if (duration >= fps_report_interval) {
      LCINFO("OpenGL", "FPS: {:6.2}",
             fps_counter / static_cast<float>(duration));
      fps_counter = 0;
      fps_start = now;
    }
  }
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

void gl::drawPixels(const orbis::Image &img) {
  glDrawPixels(img.width, img.height, GL_RGB, GL_FLOAT, img.get_float_ptr());
}