/**
 * ohhi.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1
 *
 * <Aaron Williams, Andrew Ky>
 * <ajwills, andrewky>
 *
 * This program will allow you to play 0hh1, a sudoku like puzzle game utilising colors to complete a board.
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"

/**
 * --------------------------------------------------------
 * ---------- UTILITY FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    int unknownSquares = 0;
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (board[row][col] == UNKNOWN) {
                unknownSquares += 1;
            }
        }
    }
  return unknownSquares;
}

/**
 * --------------------------------------------------------
 * --------- VALIDITY CHECKING FUNCTIONS ------------------
 * --------------------------------------------------------
 */

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color) {
    // numColor counts the amount of times 3 in a row appears
    int numColor = 0;
    bool noThreeColor = true;
    
    for (int col = 0; col < size - 2; col++) {
        if ((board[row][col] == color) && (board[row][col + 1] == color)
            && (board[row][col + 2] == color)) {
            numColor++;
        }
    }
    
    if (numColor >= 1) {
        noThreeColor = false;
    }
    
    return noThreeColor;
}

bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
    int numColor = 0;
    bool noThreeColor = true;
    
    for (int row = 0; row < size - 2; row++) {
        if ((board[row][col] == color) && (board[row + 1][col] == color)
            && (board[row + 2][col] == color)) {
            numColor++;
        }
    }
    
    if (numColor >= 1) {
        noThreeColor = false;
      }
    
    return noThreeColor;
}

bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    for (int row = 0; row < size; row++) {
        if ((row_has_no_threes_of_color(board, size, row, RED) == false)
            || (row_has_no_threes_of_color(board, size, row, BLUE) == false)) {
            return false;
        }
    }
    
    for (int col = 0; col < size; col++) {
        if ((col_has_no_threes_of_color(board, size, col, RED) == false)
            || (col_has_no_threes_of_color(board, size, col, BLUE) == false)) {
            return false;
        }
    }
          
    return true;
}

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2) {
    for (int col = 0; col < size; col++) {
        if ((board[row1][col] == UNKNOWN) || (board[row2][col] == UNKNOWN)) {
            return true;
      }
        else if ((board[row1][col] != board[row2][col])) {
            return true;
      }
    }
      return false;
  }

bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2) {
    for (int row = 0; row < size; row++) {
        if ((board[row][col1] == UNKNOWN) || (board[row][col2] == UNKNOWN)) {
            return true;
      }
        else if ((board[row][col1] != board[row][col2])) {
            return true;
        }
    }
      return false;
  }

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    for (int row1 = 0; row1 < size; row1++) {
        for (int row2 = 0; row2 < size; row2++) {
            if (row1 != row2) {
                if ((rows_are_different(board, size, row1, row2) == false)) {
                    return false;
                }
                    }
            }
    }
    for (int col1 = 0; col1 < size; col1++) {
        for (int col2 = 0; col2 < size; col2++) {
            if (col1 != col2) {
                if ((cols_are_different(board, size, col1, col2) == false)) {
                    return false;
                }
                    }
            }
    }
    return true;
}


/**
 * --------------------------------------------------------
 * ---------- SOLVING FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    // Impossible to have 3 in a row (or column) if its not at least 4x4
    if (size < 3) {
        return;
    }
    for (int col = 0; col < size; col++) {
        if (board[row][col] == UNKNOWN) {
            //When unknown is in the first position (-XXOOXXO), checks two after
            // 0 is used for the position
            if (col == 0) {
                if ((board[row][col + 1] == board[row][col + 2])
                    && (board[row][col + 1] != UNKNOWN)) {
                    mark_square_as(board, size, row, col,
                                   opposite_color(board[row][col + 1]),
                                   announce);
                }
            }
            //Unknown is in the last position (OXXOOXX-), checks two before
            else if (col == size - 1) {
                if ((board[row][col - 1] == board[row][col - 2])
                    && (board[row][col - 1] != UNKNOWN)) {
                    mark_square_as(board, size, row, col,
                                   opposite_color(board[row][col - 1]),
                                   announce);
                  }
            }
            // Unknown is in the second position (O-XOOXXO), checks position before and after
            // and checks two after
            else if (col == 1) {
                if ((board[row][col - 1]) == (board[row][col + 1])
                    && (board[row][col - 1] != UNKNOWN)) {
                    mark_square_as(board, size, row, col,
                                   opposite_color(board[row][col - 1]),
                                   announce);
              }
                else if ((board[row][col + 1]) == (board[row][col + 2])
                         && (board[row][col + 1] != UNKNOWN)) {
                    mark_square_as(board, size, row, col,
                                   opposite_color(board[row][col + 1]),
                                   announce);
              }
              
            }
            // Unknown is in the second to last position (OXXOOX-O), checks before and after
            // and checks two before
          else if (col == size - 2) {
              if ((board[row][col - 1]) == (board[row][col + 1])
                  && (board[row][col - 1] != UNKNOWN)) {
                  mark_square_as(board, size, row, col,
                                 opposite_color(board[row][col - 1]),
                                 announce);
              }
              else if ((board[row][col - 1]) == (board[row][col - 2])
                       && (board[row][col - 1] != UNKNOWN)) {
                  mark_square_as(board, size, row, col,
                                 opposite_color(board[row][col - 1]),
                                 announce);
              }
              
            }
            //Unknown is in the middle position somewhere (OX--OXXO)
          else {
              if ((board[row][col - 1]) == (board[row][col + 1])
                  && (board[row][col - 1] != UNKNOWN)) {
                  mark_square_as(board, size, row, col,
                                 opposite_color(board[row][col - 1]),
                                 announce);
              }
              else if ((board[row][col + 1]) == (board[row][col + 2])
                       && (board[row][col + 1] != UNKNOWN)) {
                  mark_square_as(board, size, row, col,
                                 opposite_color(board[row][col + 1]),
                                 announce);
            }
              else if ((board[row][col - 1]) == (board[row][col - 2])
                       && (board[row][col - 1] != UNKNOWN)) {
                  mark_square_as(board, size, row, col,
                                 opposite_color(board[row][col - 1]),
                                 announce);
              }
          }
        }
    }
}

void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
    if (size < 3) {
        return;
    }
    for (int row = 0; row < size; row++) {
        if (board[row][col] == UNKNOWN) {
            // 0 is used for the position
            if (row == 0) {
                if ((board[row + 1][col] == board[row + 2][col])
                    && (board[row + 1][col] != UNKNOWN)) {
                    mark_square_as(board, size, row, col,
                                   opposite_color(board[row + 1][col]),
                                   announce);
                }
            }
            else if (row == size - 1) {
              if ((board[row - 1][col] == board[row - 2][col])
                  && (board[row - 1][col] != UNKNOWN)) {
                  mark_square_as(board, size, row, col,
                                 opposite_color(board[row - 1][col]),
                                 announce);
                  }
            }
            else if (row == 1) {
              if ((board[row - 1][col]) == (board[row + 1][col])
                  && board[row - 1][col] != UNKNOWN) {
                  mark_square_as(board, size, row, col,
                                 opposite_color(board[row - 1][col]),
                                 announce);
              }
              else if ((board[row + 1][col]) == (board[row + 2][col])
                       && board[row + 1][col] != UNKNOWN) {
                  mark_square_as(board, size, row, col,
                                 opposite_color(board[row + 1][col]),
                                 announce);
              }
              
            }
          else if (row == size - 2) {
              if ((board[row - 1][col]) == (board[row + 1][col])
                  && board[row - 1][col] != UNKNOWN) {
                  mark_square_as(board, size, row, col,
                                 opposite_color(board[row - 1][col]),
                                 announce);
              }
              else if ((board[row - 1][col]) == (board[row - 2][col])
                       && board[row - 1][col] != UNKNOWN) {
                  mark_square_as(board, size, row, col,
                                 opposite_color(board[row - 1][col]),
                                 announce);
              }
              
            }
          else {
            if ((board[row - 1][col]) == (board[row + 1][col])
                && board[row - 1][col] != UNKNOWN) {
                mark_square_as(board, size, row, col,
                               opposite_color(board[row - 1][col]),
                               announce);
              }
            else if ((board[row + 1][col]) == (board[row + 2][col])
                     && board[row + 1][col] != UNKNOWN) {
                mark_square_as(board, size, row, col,
                               opposite_color(board[row + 1][col]),
                               announce);
            }
            else if ((board[row - 1][col]) == (board[row - 2][col])
                     && board[row - 1][col] != UNKNOWN) {
                mark_square_as(board, size, row, col,
                               opposite_color(board[row - 1][col]),
                               announce);
              }
            
          }
        }
    }
}

void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce) {
    // Counters for both colors are intialized and used to
    //determine which color, if any, takes up half the board
    int color;
    int colorCounter = 0;
    int oppColorCounter = 0;
    int cols = 0;
    //The first color (that's not unknown) in that specific row is color
    while (board[row][cols] == UNKNOWN) {
        cols++;
    }
    color = board[row][cols];
    
    for (int col = 0; col < size; col++) {
        if (board[row][col] == color) {
            colorCounter++;
        }
        else if (board[row][col] == opposite_color(board[row][cols])) {
            oppColorCounter++;
        }
    }
    if (colorCounter == size / 2) {
        for (int col = 0; col < size; col++) {
            if (board[row][col] == UNKNOWN) {
                mark_square_as(board, size, row, col,
                               opposite_color(board[row][cols]),
                               announce);
            }
        }
    }
    else if (oppColorCounter == size / 2) {
        for (int col = 0; col < size; col++) {
            if (board[row][col] == UNKNOWN) {
                mark_square_as(board, size, row, col, board[row][cols], announce);
            }
        }
    }
    return;
}

void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int col,
                          bool announce) {
    int color;
    int colorCounter = 0;
    int oppColorCounter = 0;
    int rows = 0;
    while (board[rows][col] == UNKNOWN) {
        rows++;
    }
    
    color = board[rows][col];
    for (int row = 0; row < size; row++) {
        if (board[row][col] == color) {
            colorCounter++;
        }
        else if (board[row][col] == opposite_color(board[rows][col])) {
            oppColorCounter++;
        }
    }
    if (colorCounter == size / 2) {
        for (int row = 0; row < size; row++) {
            if (board[row][col] == UNKNOWN) {
                mark_square_as(board, size, row, col,
                               opposite_color(board[rows][col]),
                               announce);
            }
        }
    }
    else if (oppColorCounter == size / 2) {
        for (int row = 0; row < size; row++) {
            if (board[row][col] == UNKNOWN) {
                mark_square_as(board, size, row, col, board[rows][col], announce);
            }
        }
    }
    return;
}

/**
 * --------------------------------------------------------
 * ---------- GAMEPLAY FUNCTIONS --------------------------
 * --------------------------------------------------------
 */

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    // 0 is used if there are no unknown squares in the board
    if ((count_unknown_squares(board, size) == 0) && (board_is_valid(board, size) == true)) {
        return true;
    }
    else {
        return false;
    }
}

bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col) {
    if ((row_input >= 1) && (row_input <= size)
        && (toupper(col_input) >= 'A') && (toupper(col_input) <= ('A' + size - 1))
        && (toupper(color_char) == RED_LETTER || toupper(color_char) == BLUE_LETTER
        || toupper(color_char) == UNKNOWN_LETTER)) {
        row = row_input - 1;
        col = toupper(col_input) - 'A';
        return true;
    }
    else {
        cout << "Sorry, that's not a valid input.";
        return false;
    }
}

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
    int new_board[MAX_SIZE][MAX_SIZE];
    copy_board(current_board, new_board,size);
    if (original_board[row][col] == UNKNOWN) {
        new_board[row][col] = color;
        if (board_is_valid(new_board,size)) {
            return true;
        }
        else{
            cout << "Sorry, that move violates a rule." << endl;
            return false;
        }
    }
    else{
        cout << "Sorry, original squares cannot be changed." << endl;
        return false;
    }
}
