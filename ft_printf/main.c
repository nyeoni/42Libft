#include <stdio.h>

int main(void) {
  int a;
  printf("%c\n", 'a');
  printf("%s\n", "abcd");
  printf("%p\n", &a);
  printf("%d\n", 123);
  printf("%i\n", 123);
  printf("%u\n", 123);
  printf("%u\n", -123);
  printf("%x\n", 'a');
  printf("%X\n", a);
  printf("%%\n");
  printf("\n");
}