#include <assert.h>
#include <stdio.h>

unsigned int touint(const char* s) {
  unsigned int result = 0;

  for (; *s != 0; ++s) {
    assert(*s >= '0' && *s <= '9');
    result = result * 10 + ((unsigned int)(*s) - '0');
  }

  return result;
}

int main() {
  printf("%u\n", touint("12345"));

  return 0;
}