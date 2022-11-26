#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Allocates new int** & copies over the array contents.
// Both the outer & inner arrays are null-terminated.
//
// # Notes
//
// Both `x` and `y` must be greater than 0.
//
// # Return value
//
// On success, returns the pointer to the outer array.
// To avoid a memory leak, the returned pointer must be deallocated with
// `free_intpp()`.
//
// On failure, returns a null pointer.
int** to_intpp(size_t x, size_t y, int arr[x][y]) {
  assert(x > 0);
  assert(y > 0);

  int** outer = calloc(x + 1, sizeof(int*));
  if (outer == NULL) {
    return NULL;
  }

  size_t i;
  bool fail = false;
  for (i = 0; i < x; ++i) {
    outer[i] = calloc(y + 1, sizeof(int));
    if (outer[i] == NULL) {
      fail = true;
      break;
    }

    memcpy(outer[i], &arr[i], y * sizeof(int));
  }

  if (fail) {
    for (x += 1; x > 0; --x) {
      free(outer[x - 1]);
    }
    free(outer);

    return NULL;
  }

  return outer;
}

void print_intpp(int** arr) {
  for (; *arr != 0; ++arr) {
    for (int* val = *arr; *val != 0; ++val) {
      printf("%i\t", *val);
    }
    printf("\n");
  }
}

void free_intpp(int** arr) {
  int** begin = arr;
  for (; *arr != 0; ++arr) {
    free(*arr);
  }
  free(begin);
}

int main() {
  int test1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int test2[4][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};

  int** cpy1 = to_intpp(3, 3, test1);
  print_intpp(cpy1);
  free_intpp(cpy1);

  printf("--------------------\n");

  int** cpy2 = to_intpp(4, 2, test2);
  print_intpp(cpy2);
  free_intpp(cpy2);

  return 0;
}