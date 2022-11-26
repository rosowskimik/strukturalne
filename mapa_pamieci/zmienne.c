#include <stdio.h>

#define strname(var) #var

void _desc(unsigned char* var, size_t size, const char* varname) {
  printf("Name: %s\nSize: %llu\nAddr: %p\n", varname, size, var);

  for (int i = 0; i < size; ++i)
    printf("%02x ", var[i]);

  printf("\n------\n");
}

#define describe(var) _desc((unsigned char*)&var, sizeof(var), strname(var))

int i_global = 3;
char c_global = 4;
float f_global = 2.5;
double d_global = 3.1;
short s_global = 1;
long l_global = 5;

int main() {
  int i_local = 4;
  char c_local = 1;
  float f_local = 3.5;
  double d_local = 2.1;
  short s_local = 5;
  long l_local = 3;

  static int i_static = 1;
  static char c_static = 5;
  static float f_static = 5.2;
  static double d_static = 1.3;
  static short s_static = 3;
  static long l_static = 4;

  describe(i_global);
  describe(c_global);
  describe(f_global);
  describe(d_global);
  describe(s_global);
  describe(l_global);
  describe(i_local);
  describe(c_local);
  describe(f_local);
  describe(d_local);
  describe(s_local);
  describe(l_local);
  describe(i_static);
  describe(c_static);
  describe(f_static);
  describe(d_static);
  describe(s_static);
  describe(l_static);

  return 0;
}