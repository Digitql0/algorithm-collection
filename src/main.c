#include <stdio.h>

#include "sudoku_solver.h"
#include "utilities.h"

void print_sudoku(int *board) {
  for (size_t i = 0; i < 9; i++) {
    for (size_t j = 0; j < 9; j++) {
      int index;
      coordinates_2d_to_1d(i, j, 9, &index);
      printf("[%d]", board[index]);
    }
    printf("\n");
  }
}

int main() {
  int board[81] = {5, 3, 4, 6, 7, 8, 9, 1, 2, 6, 7, 2, 1, 9, 5, 3, 4,
                   8, 1, 9, 8, 3, 4, 2, 5, 6, 7, 8, 5, 9, 7, 6, 1, 4,
                   2, 3, 4, 2, 6, 8, 5, 3, 7, 9, 1, 7, 1, 3, 9, 2, 4,
                   8, 5, 6, 9, 6, 1, 5, 3, 7, 2, 8, 4, 2, 8, 7, 4, 1,
                   9, 6, 3, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0};

  print_sudoku(board);
  solve_board_brute_force(board);
  printf("---\n");
  print_sudoku(board);
  return 0;
}
