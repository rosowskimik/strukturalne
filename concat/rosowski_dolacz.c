#include "stdio.h"
#include "string.h"

// Copies contents of src to dest
// Dest needs to be able to hold both itself and src
void stradd(char* restrict dest, const char* restrict src) {
  strcpy(&dest[strlen(dest)], src);
}

int main() {
  char dest[20] = "Hell";
  const char* src = "o world!";

  stradd(dest, src);
  printf("%s\n", dest);
  return 0;
}