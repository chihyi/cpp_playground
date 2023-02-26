/* #pragma once
 */
#include <iostream>

using namespace std;

void referencing() {
  int v[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (auto x : v) {
    ++x;
    std::cout << x << ", ";
  }
  std::cout << "\n";

  for (auto x : v) {
    std::cout << x << ", ";
  }
  std::cout << "\n";

  for (auto &x : v) {
    ++x;
    std::cout << x << ", ";
  }
  std::cout << "\n";

  for (auto x : v) {
    std::cout << x << ", ";
  }
  std::cout << "\n";
}
