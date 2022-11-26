#include <iostream>

// Values copied into function scope -> swap visible only inside this function;
// original stay the same
template <typename T>
void swap_by_value(T a, T b) {
  T tmp = a;
  a = b;
  b = tmp;
}

// Values passed by reference -> original variables aliased in function scope;
// changes visible outside
template <typename T>
void swap_by_reference(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}

// Values passed by pointer -> function gets passed memory addresses of
// original values, dereferencing them allows direct access;
// changes visible outside
template <typename T>
void swap_by_pointer(T* a, T* b) {
  T tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  float x = 2.5f, y = 4.3f;

  std::cout << "Before swap\nx = " << x << ", y = " << y << '\n';
  //   swap_by_value(x, y);
  //   swap_by_reference(x, y);
  swap_by_pointer(&x, &y);
  std::cout << "After swap\nx = " << x << ", y = " << y << std::endl;

  return 0;
}