#include <stdio.h>
int main() {
  int a, b, *p;
  a = 10;
  b = 20;
  p = &a;
  printf("a=%d b=%d *p=%d \n", a, b, *p);
  *p = *p + 1;
  printf("a=%d b=%d *p=%d \n", a, b, *p);
  a = a + 1;
  printf("a=%d b=%d *p=%d \n", a, b, *p);
  p = &b;
  printf("a=%d b=%d *p=%d \n", a, b, *p);
  *p = *p + 1;
  printf("a=%d b=%d *p=%d \n", a, b, *p);
  *p = a;
  printf("a=%d b=%d *p=%d \n", a, b, *p);
  *p = b + 10;
  printf("a=%d b=%d *p=%d \n", a, b, *p);
  return (0);
}
