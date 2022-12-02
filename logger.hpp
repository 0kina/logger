#include <iostream>

namespace okina_logger {

template <class T>
void print_container(std::string label, const T &container, std::string delimiter=", ") {
  std::cerr << label << std::endl;
  int s = container.size();
  auto itr = begin(container);
  for (int i = 0; i < s; ++i) {
    std::cout << *itr;
    ++itr;
    if (i < s - 1) {
      std::cout << delimiter;
    } else {
      std::cout << std::endl;
    }
  }
}

} // okina_logger