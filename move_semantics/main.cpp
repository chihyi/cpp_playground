// std::move(a) is to call the move constructor of the a class.

#include "string_class.cpp"
#include <iostream>

class Entity {
public:
  Entity(const String_Fangyi &name) : m_name_(name){};

  Entity(String_Fangyi &&name) : m_name_(std::move(name)){};

  void print_name() { m_name_.print(); }

private:
  String_Fangyi m_name_;
};

int main() {
  // Entity entity("Fangyi");
  // entity.print_name();

  String_Fangyi string = "Hello";
  String_Fangyi dest;

  std::cout << "string: ";
  string.print();
  std::cout << "dest: ";
  dest.print();

  // std::move(T) will trigger a copy if there is no move constructor or
  // assignment available for type T
  dest = std::move(string);

  std::cout << "string: ";
  string.print();
  std::cout << "dest: ";
  dest.print();

  return 0;
}
