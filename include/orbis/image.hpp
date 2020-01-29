#ifndef ORBIS_IMAGE_HPP_
#define ORBIS_IMAGE_HPP_

#include <glm/glm.hpp>

namespace orbis {
struct Image {
  Image(const std::size_t w, const std::size_t h)
      : width(w), height(h),
        pixels((glm::vec3 *)malloc(sizeof(glm::vec3) * width * height)) {}
  std::size_t width, height;
  glm::vec3 *pixels;
  inline glm::vec3 &operator[](const std::size_t &i) { return pixels[i]; }
  inline glm::vec3 &operator()(const std::size_t &x, const std::size_t &y) {
    return pixels[x * width + y];
  }
  inline float *get_float_ptr() const {
    return reinterpret_cast<float *>(pixels);
  }
};
} // namespace orbis

#endif // ORBIS_IMAGE_HPP_