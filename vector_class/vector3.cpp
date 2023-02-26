#pragma once
#include <iostream>

struct vector3 {
  float x = 0.0f, y = 0.0f, z = 0.0f;
  int *m_memoryBlock = nullptr;

  vector3() {
    std::cout << "constructed" << std::endl;
    m_memoryBlock = new int[9];
  }

  vector3(float scaler) : x(scaler), y(scaler), z(scaler) {
    std::cout << "constructed" << std::endl;
    m_memoryBlock = new int[9];
  }

  vector3(float x, float y, float z) : x(x), y(y), z(z) {
    std::cout << "constructed" << std::endl;
    m_memoryBlock = new int[9];
  }

  vector3(const vector3 &other) = delete;

  vector3(vector3 &&other) : x(other.x), y(other.y), z(other.z) {
    std::cout << "moved" << std::endl;
    m_memoryBlock = other.m_memoryBlock;
    other.m_memoryBlock = nullptr;
  }

  // vector3 &operator=(const vector3 &other) {
  //   std::cout << "copied" << std::endl;

  //   x = other.x;
  //   y = other.y;
  //   z = other.z;
  //   return *this;
  // }

  vector3 &operator=(const vector3 &other) = delete;

  vector3 &operator=(vector3 &&other) {
    std::cout << "moved" << std::endl;

    x = other.x;
    y = other.y;
    z = other.z;
    m_memoryBlock = other.m_memoryBlock;
    other.m_memoryBlock = nullptr;
    return *this;
  }

  ~vector3() {
    std::cout << "destroyed" << std::endl;
    delete[] m_memoryBlock;
  }
};
