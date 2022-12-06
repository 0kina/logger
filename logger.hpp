#include <iostream>
#include <set>
#include <vector>

namespace okina_logger {

template <class T>
inline void print_var_inner(std::string label, T var) {
  std::cerr << label << ": " << var << std::endl;
}

inline void print_log(std::string label, int var) {
  print_var_inner(label, var);
}

inline void print_log(std::string label, std::string var) {
  print_var_inner(label, var);
}

template <class T>
inline void print_vars_single_container_inner(std::string label, T vars, std::string delimiter) {
  std::cerr << label << ": ";
  int i = 0;
  for (typename T::const_iterator itr = begin(vars); itr != end(vars); ++itr) {
    std::cerr << *itr;
    if (i++ < vars.size() - 1) {
      std::cerr << delimiter;
    } else {
      std::cerr << std::endl;
    }
  }
}

inline void print_log(std::string label, std::vector<int> vars, std::string delimiter=", ") {
  print_vars_single_container_inner(label, vars, delimiter);
}

inline void print_log(std::string label, std::vector<std::string> vars, std::string delimiter=", ") {
  print_vars_single_container_inner(label, vars, delimiter);
}

inline void print_log(std::string label, std::set<int> vars, std::string delimiter=", ") {
  print_vars_single_container_inner(label, vars, delimiter);
}

inline void print_log(std::string label, std::set<std::string> vars, std::string delimiter=", ") {
  print_vars_single_container_inner(label, vars, delimiter);
}

} // okina_logger