#include "utilities.h"

void coordinates_1d_to_2d(int index, int width, int* x, int* y) {
  *x = index % width;
  *y = index / width;
}

void coordinates_2d_to_1d(int x, int y, int width, int* index) {
  *index = y * width + x;
}

int increment_array(int* arr, int size, int min, int max) {
  for (int i = size - 1; i >= 0; i--) {
    if (arr[i] < max) {
      arr[i] += 1;
      return 0;
    }
    arr[i] = min;
  }
  return 1;  // wrap around
}

int increment_pointer_array(int** arr, int size, int min, int max) {
  for (int i = size - 1; i >= 0; i--) {
    if (*arr[i] < max) {
      *arr[i] += 1;
      return 0;
    }
    *arr[i] = min;
  }
  return 1;  // wrap around}
}
