#include <stdio.h>
#include <stdlib.h>

int digitsum(int n) {
  if (n == 0) {
    return 0;
  }
  return n % 10 + digitsum(n / 10);
}

int main(int argc, char *argv[]) {

  int x;
  printf("enter a num:");
  scanf("%d", &x);

  printf("%d\n", digitsum(x));
  system("pause");
  return 0;
}
