#include <iostream>
#include <string>

// lvalue reference
int &getValue() {
  static int value = 10;
  return value;
}

void setValue(int &value) {}

void printName(std::string &&name) {
  std::cout << "[rvalue]" << name << std::endl;
}

void printName(std::string &name) {
  std::cout << "[lvalue]" << name << std::endl;
}

int main() {
  int i = getValue();
  getValue() = 5;

  int j = 20;
  // Calling setValue with an lvalue
  setValue(j);
  // Calling setValue with an rvalue
  // You can't take an lvalue reference from an rvalue
  // int &a = 10;       // Error
  const int &a = 10; // Correct
  // setValue(10);      // Error with void setValue(int &value), Correct with
  // void
  // setValue(const int &value)

  std::string firstName = "Fangyi";  // lvalue = rvalue
  std::string lastName = "Streitel"; // lvalue = rvalue

  std::string fullName = firstName + lastName; // lvalue = rvalue

  printName(fullName);
  printName(firstName + lastName);

  return 0;
}
