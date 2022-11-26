#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Allocated new string holding both contents of s1 and s2
// Returns pointer to new string that needs to be cleaned up with free
char* stradd_a(const char* s1, const char* s2) {
  size_t s1_len = strlen(s1);
  char* out = malloc(s1_len + strlen(s2) + 1);

  strcpy(out, s1);
  strcpy(&out[s1_len], s2);
  return out;
}

int main() {
  char* new_str = stradd_a("Test ", "One, Two, Three");
  printf("%s\n", new_str);
  free(new_str);

  return 0;
}