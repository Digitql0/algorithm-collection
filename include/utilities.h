#ifndef UTILITIES_H
#define UTILITIES_H

void coordinates_1d_to_2d(int index, int width, int* x, int* y);
void coordinates_2d_to_1d(int x, int y, int width, int* index);
int increment_array(int* arr, int size, int min, int max);
int increment_pointer_array(int** arr, int size, int min, int max);

#endif
