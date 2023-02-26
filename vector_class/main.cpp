#include "vector.cpp"
#include "vector3.cpp"
#include <iostream>

int main() {
  Vector<vector3> vector;

  //   vector.pushBack(vector3());
  //   vector.pushBack(vector3(1));
  //   vector.pushBack(vector3(1, 2, 3));
  //   printVector(vector);

  //   vector.pushBack(vector3());
  //   vector.pushBack(vector3(4));
  //   vector.pushBack(vector3(5, 6, 7));
  //   printVector(vector);

  // vector.emplaceBack();
  // vector.emplaceBack(1);
  // vector.emplaceBack(2, 3, 4);

  // vector.emplaceBack();
  // vector.emplaceBack(4);
  // vector.emplaceBack(5, 6, 7);
  // printVector(vector);

  // vector.popBack();
  // vector.popBack();
  // printVector(vector);

  // vector.emplaceBack(7);
  // vector.emplaceBack(7, 8, 9);
  // printVector(vector);

  // vector.clear();
  // printVector(vector);

  // vector.emplaceBack(7);
  // vector.emplaceBack(7, 8, 9);
  // printVector(vector);

  // Vector<int> intVector;
  // intVector.pushBack(5);
  // intVector.emplaceBack(2);
  // intVector.emplaceBack(2);
  // intVector.emplaceBack(2);
  // printVector(intVector);
  // intVector.emplaceBack(2);
  // intVector.emplaceBack(2);
  // intVector.emplaceBack(2);
  // intVector.popBack();
  // printVector(intVector);
  // intVector.clear();
  // printVector(intVector);

  vector3 v1 = vector3(1, 2, 3);
  std::cout << v1.m_memoryBlock << std::endl;
  vector3 v2(std::move(v1));
  std::cout << v1.m_memoryBlock << std::endl;
  std::cout << v2.m_memoryBlock << std::endl;

  return 0;
}
