#pragma once
#include "vector3.cpp"
#include <memory>

template <typename T> class Vector {
public:
  Vector() { reAlloc(2); }

  ~Vector() {
    clear();
    ::operator delete(m_data_, m_capacity_ * sizeof(T));
  }

  size_t size() const { return m_size_; }
  size_t capacity() const { return m_capacity_; }

  T &operator[](int i) { return m_data_[i]; }

  const T &operator[](int i) const { return m_data_[i]; }

  void pushBack(T &&elem) {
    if (m_size_ >= m_capacity_) {
      reAlloc(m_capacity_ + m_capacity_ / 2);
    }

    m_data_[m_size_++] = std::move(elem);
  }

  void popBack() {
    if (m_size_ > 0) {
      m_size_--;
      m_data_[m_size_].~T();
    }
  }

  void clear() {
    for (size_t i = 0; i < m_size_; i++) {
      m_data_[i].~T();
    }
    m_size_ = 0;
  }

  template <typename... Args> void emplaceBack(Args &&... args) {
    if (m_size_ >= m_capacity_) {
      reAlloc(m_capacity_ + m_capacity_ / 2);
    }

    m_data_[m_size_++] = T(args...);

    // m_data_[m_size_++] = T(std::forward<Args>(args)...);
    // new (&m_data_[m_size_]) T(std::forward<Args>(args)...);
  }

private:
  T *m_data_ = nullptr;
  size_t m_size_ = 0;
  size_t m_capacity_ = 0;

  void reAlloc(size_t new_capacity) {
    if (m_size_ >= new_capacity) {
      m_size_ = new_capacity;
    }

    T *new_block = (T *)::operator new(new_capacity * sizeof(T));
    for (int i = 0; i < m_size_; i++) {
      new_block[i] = std::move(m_data_[i]);
      // new (&new_block[i]) T(std::move(m_data_[i]));
    }

    for (int i = 0; i < m_size_; i++) {
      m_data_[i].~T();
    }

    ::operator delete(m_data_, m_capacity_ * sizeof(T));
    m_data_ = new_block;
    m_capacity_ = new_capacity;
  }
};

void printVector(const Vector<vector3> &vector) {
  for (int i = 0; i < vector.size(); i++) {
    std::cout << vector[i].x << vector[i].y << vector[i].z << std::endl;
  }

  std::cout << "------------------------" << std::endl;
}

template <typename T> void printVector(const Vector<T> &vector) {
  for (int i = 0; i < vector.size(); i++) {
    std::cout << vector[i] << std::endl;
  }

  std::cout << "------------------------" << std::endl;
}
