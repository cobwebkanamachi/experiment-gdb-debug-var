#include <stdlib.h>

  void f(void)
  {
     int* x = malloc(10 * sizeof(int));
     x[8] = 0;        // problem 1: heap block overrun(valgrind watch, but safe in this case. write x[10] cause error)
  }

  int main(void)
  {
     f();
     return 0;
  }
