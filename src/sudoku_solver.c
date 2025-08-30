#include "sudoku_solver.h"

#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "utilities.h"

void solve_board_brute_force(sudoku_board board) {
  int** board_places = malloc(sizeof(int*) * 81);
  int size = 0;
  for (size_t i = 0; i < 81; i++) {
    if (board[i] == 0) board_places[size++] = &board[i];
  }

  for (int i = 0; i < size; i++) *board_places[i] = 1;

  while (1 == 1) {
    int i = increment_pointer_array(board_places, size, 1, 9);
    if (i == 1) break;
    if (sudoku_board_is_valid(board)) break;
  }

  free(board_places);
}

int sudoku_board_is_valid(sudoku_board board) {
  // CHECK HORIZONTAL AND VERTICAL LINES
  for (size_t i = 0; i < 9; i++) {
    int row[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int column[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (size_t j = 0; j < 9; j++) {
      int column_index, row_index;
      coordinates_2d_to_1d(i, j, 9, &row_index);
      coordinates_2d_to_1d(j, i, 9, &column_index);
      row[j] = board[row_index];
      column[j] = board[column_index];
      for (size_t a = 0; a < j; a++) {
        if (row[a] == 0 || column[a] == 0) return 0;
        if (row[a] == row[j] || column[a] == column[j]) return 0;
      }

      // CHECK 3x3 BOXES
      if (i % 3 == 0 && j % 3 == 0) {
        int box[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (size_t a = 0; a < 3; a++) {
          for (size_t b = 0; b < 3; b++) {
            int x = a + i;
            int y = b + j;
            int box_index = a * 3 + b;
            int index;
            coordinates_2d_to_1d(x, y, 9, &index);
            box[box_index] = board[index];

            for (size_t c = 0; c < box_index; c++) {
              if (box[c] == 0) return 0;
              if (box[c] == box[box_index]) return 0;
            }
          }
        }
      }
    }
  }

  return 1;
}
