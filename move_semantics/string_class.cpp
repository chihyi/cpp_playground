#include <stdio.h>
#include <string.h>

class String_Fangyi {
public:
  String_Fangyi() : m_data_(nullptr), m_size_(0) {}
  String_Fangyi(const char *string) {
    printf("Created!\n");
    m_size_ = strlen(string);
    m_data_ = new char[m_size_];
    memcpy(m_data_, string, m_size_);
  }

  String_Fangyi(const String_Fangyi &other) {
    printf("Copied!\n");
    m_size_ = other.m_size_;
    m_data_ = new char[m_size_];
    memcpy(m_data_, other.m_data_, m_size_);
  }

  String_Fangyi(String_Fangyi &&other) noexcept {
    printf("Moved!\n");
    m_size_ = other.m_size_;
    m_data_ = other.m_data_;

    other.m_size_ = 0;
    other.m_data_ = nullptr;
  }

  String_Fangyi &operator=(String_Fangyi &&other) noexcept {
    printf("Moved!\n");

    if (this != &other) {
      delete[] m_data_;

      m_size_ = other.m_size_;
      m_data_ = other.m_data_;

      other.m_size_ = 0;
      other.m_data_ = nullptr;
    }

    return *this;
  }

  void print() {
    for (int i = 0; i < m_size_; i++) {
      printf("%c", m_data_[i]);
    }
    printf("\n");
  }

  ~String_Fangyi() {
    printf("Destroyed!\n");
    delete m_data_;
  }

private:
  char *m_data_;
  unsigned int m_size_;
};
