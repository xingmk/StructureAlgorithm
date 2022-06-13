#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);
int main(int argc, char *argv[]) {
  int n;
  printf("enter the item :");
  scanf("%d", &n);

  printf("%d\n", fibonacci(n));

  system("pause");
  return 0;
}

int fibonacci(int n) {

  if (n <= 2) {
    return 1;
  } else {

    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}
