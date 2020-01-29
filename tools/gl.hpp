#ifndef ORBIS_GL_HPP_
#define ORBIS_GL_HPP_

#include "glad/glad.h"

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>

#include <orbis/image.hpp>

namespace gl {
extern GLFWwindow *window;
bool init();
void terminate();

bool shouldClose();
void setShouldClose(bool setting);

void frame();

bool getKey(const int &key);
void clearColor(const glm::vec3 &c);
void clearColor(const glm::vec4 &c);
void clear();
void clear(const glm::vec3 &c);
void drawPixels(const orbis::Image &img);
} // namespace gl

#endif // ORBIS_GL_HPP_