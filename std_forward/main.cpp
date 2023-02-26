#include <iostream>

struct S {};

void f(S &s) { std::cout << "f(S&)\n"; }
void f(S &&s) { std::cout << "f(S&&)\n"; }

template <typename T> void wrap(T &&t) { f(std::forward<T>(t)); }

int main() {
  S s;
  wrap(S());
  wrap(s);
}
