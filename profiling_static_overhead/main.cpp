
#include "static_profiling.cpp"

int main() {
  size_t total_size = 0;

  C c;
  for (int i = 0; i < 100000000; i++) {
    // total_size += c.magic_static_ref().size() + i;
    total_size += C::magic_static().size() + i;
  }

  std::cout << "total_size: " << total_size << "\n";
  return total_size;
}
