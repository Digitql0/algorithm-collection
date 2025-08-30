#ifndef SUDOKU_SOLVER_h
#define SUDOKU_SOLVER_h

typedef int sudoku_board[81];

void solve_board_brute_force(sudoku_board board);
int sudoku_board_is_valid(sudoku_board board);

#endif  // SUDOKU_SOLVER_H
