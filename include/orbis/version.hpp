#ifndef ORBIS_VERSION_HPP_
#define ORBIS_VERSION_HPP_

#define ORBIS_VERSION_MAJOR 0
#define ORBIS_VERSION_MINOR 0
#define ORBIS_VERSION_PATCH 0

namespace orbis {
inline void get_version(unsigned &major, unsigned &minor, unsigned &patch) {
  major = ORBIS_VERSION_MAJOR;
  minor = ORBIS_VERSION_MINOR;
  patch = ORBIS_VERSION_PATCH;
}
} // namespace orbis

#endif // ORBIS_VERSION_HPP_
