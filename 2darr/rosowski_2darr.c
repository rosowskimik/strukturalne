#include <stddef.h>
#include <stdio.h>

void print2d(size_t x, size_t y, int tbl[x][y]) {
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < y; ++j) {
      printf("%i, ", tbl[i][j]);
    }
    puts("");
  }
}

int main() {
  int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int b[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

  print2d(2, 3, a);

  puts("---------");
  print2d(4, 4, b);

  return 0;
}