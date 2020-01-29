#include "log.hpp"

int main(int argc, char const *argv[]) {
  orbis::logger::initalize_logger();
  LINFO("Hello WORLD!");
  /* code */
  return 0;
}
