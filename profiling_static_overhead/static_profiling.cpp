#include <algorithm>
#include <iostream>
#include <string>

struct C {
  static const std::string &magic_static() {
    // std::cout << "magic_static()\n";
    static const std::string s = "test";
    return s;
  }
  const std::string &s = magic_static();
  const std::string &magic_static_ref() {
    // std::cout << "magic_static_ref\n";
    return s;
  }
};
