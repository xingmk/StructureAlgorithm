#include <stdio.h>
#include <stdlib.h>

int searchItem(int arr[], int len, int value) {
  int low = 0, high = len - 1, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (value > arr[mid]) {
      low = mid + 1;
    } else if (value < arr[mid]) {
      high = mid - 1;
    } else {
      return mid;
    }
  }
  return -1;
}
// ------------------

int insertItemLoc(int arr[], int len, int value) {

  int low = 0, high = len - 1, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (value < arr[mid]) {
      low = mid + 1;
    } else if (value < arr[mid]) {
      high = mid - 1;
    } else {
      return mid + 1;
    }
  }
  return low;
}

int main(int argc, const char *argv[]) {

  int a[10] = {1, 2, 31, 35, 34, 55, 66, 77, 87, 98};

  int l = searchItem(a, 10, 86);
  printf("loc = %d\n", l);
  return 0;
}
