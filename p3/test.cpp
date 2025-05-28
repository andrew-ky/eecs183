/**
 * test.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 *
 * <Aaron Williams, Andrew Ky>
 * <ajwills, andrewky>
 *
 * <Solves an Oh h1 board>
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_row_has_no_threes_of_color();
void test_col_has_no_threes_of_color();
void test_board_has_no_threes();
void test_rows_are_different();
void test_cols_are_different();
void test_solve_three_in_a_row();
void test_solve_three_in_a_column();
void test_solve_balance_row();
void test_solve_balance_column();
void test_board_is_solved();
void test_check_valid_input();
void test_check_valid_move();
// declare more test functions here

void startTests() {
   test_count_unknown_squares();
   test_row_has_no_threes_of_color();
   test_col_has_no_threes_of_color();
   test_board_has_no_threes();
   test_rows_are_different();
   test_cols_are_different();
    test_solve_three_in_a_row();
    test_solve_three_in_a_column();
    test_solve_balance_row();
    test_solve_balance_column();
    test_board_is_solved();
   test_check_valid_input();
    test_check_valid_move();

    // add your calls to test functions here
}


void test_count_unknown_squares() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"XOXO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << count_unknown_squares(board, size_1) << endl;

    // add more tests here
}
void test_row_has_no_threes_of_color(){
    // test case 1
    int board0[MAX_SIZE][MAX_SIZE];
    string test_board_0[] =
        {"XXOO",
        "XXOO",
        "OOXX",
        "OOXX"};
    int size_0 = 4;
    read_board_from_string(board0, test_board_0, size_0);
    cout << "Testing Board 0";
    cout << "Expected: 1 , Actual: " << row_has_no_threes_of_color(board0, size_0, 1, BLUE) << endl;
    cout << "Expected: 1 , Actual: " << row_has_no_threes_of_color(board0, size_0, 2, RED) << endl;
    cout << "Expected: 1 , Actual: " << row_has_no_threes_of_color(board0, size_0, 3, RED) << endl;
    

    int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] =
        {"XOXO",
        "-OOO",
        "-XXX",
        "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Testing Board 1";
    cout << "Expected: 0 , Actual: " << row_has_no_threes_of_color(board, size_1, 2, RED) << endl;
    cout << "Expected: 1 , Actual: " << row_has_no_threes_of_color(board, size_1, 2, BLUE) << endl;
    cout << "Expected: 1 , Actual: " << row_has_no_threes_of_color(board, size_1, 0, BLUE) << endl;
    cout << "Expected: 1 , Actual: " << row_has_no_threes_of_color(board, size_1, 3, RED) << endl;
    cout << "Expected: 0 , Actual: " << row_has_no_threes_of_color(board, size_1, 1, BLUE) << endl;
    
    int board2[MAX_SIZE][MAX_SIZE];
    string test_board_2[] ={
        "XOXO--",
        "-OOOXO",
        "-XXXOX",
        "--XXXX",
        "XXXOOO",
        "--XXX-"
    };
    
    int size_2 = 6;
    read_board_from_string(board2, test_board_2, size_2);
    cout << "Testing Board 2" << endl;
    cout << "Expected: 1 , Actual: " << row_has_no_threes_of_color(board2, size_2, 0, RED) << endl;
    cout << "Expected: 0 , Actual: " << row_has_no_threes_of_color(board2, size_2, 0, BLUE) << endl;
    cout << "Expected: 0 , Actual: " << row_has_no_threes_of_color(board2, size_2, 1, BLUE) << endl;
    cout << "Expected: 1 , Actual: " << row_has_no_threes_of_color(board2, size_2, 1, RED) << endl;
    cout << "Expected: 1 , Actual: " << row_has_no_threes_of_color(board2, size_2, 2, BLUE) << endl;
    cout << "Expected: 0 , Actual: " << row_has_no_threes_of_color(board2, size_2, 3, RED) << endl;
    cout << "Expected: 1 , Actual: " << row_has_no_threes_of_color(board2, size_2, 3, BLUE) << endl;
    cout << "Expected: 0 , Actual: " << row_has_no_threes_of_color(board2, size_2, 4, RED) << endl;
    cout << "Expected: 0 , Actual: " << row_has_no_threes_of_color(board2, size_2, 4, BLUE) << endl;
    cout << "Expected: 0 , Actual: " << row_has_no_threes_of_color(board2, size_2, 5, RED) << endl;

}


void test_col_has_no_threes_of_color(){
    int board3[MAX_SIZE][MAX_SIZE];
    string test_board_3[] ={
        "XO--X-",
        "XO-OO-",
        "XXXOOX",
        "OOOOOX",
        "-OX-XX",
        "-OX-X-"
    };
    
    int size_3 = 6;
    read_board_from_string(board3, test_board_3, size_3);
    cout << "Testing Board 3" << endl;
    cout << "Expected: 0 , Actual: " << col_has_no_threes_of_color(board3, size_3, 0, RED) << endl;
  cout << "Expected: 1 , Actual: " << col_has_no_threes_of_color(board3, size_3, 0, BLUE) << endl;
  cout << "Expected: 0 , Actual: " << col_has_no_threes_of_color(board3, size_3, 1, BLUE) << endl;
  cout << "Expected: 1 , Actual: " << col_has_no_threes_of_color(board3, size_3, 2, BLUE) << endl;
  cout << "Expected: 1 , Actual: " << col_has_no_threes_of_color(board3, size_3, 2, RED) << endl;
  cout << "Expected: 0 , Actual: " << col_has_no_threes_of_color(board3, size_3, 3, BLUE) << endl;
  cout << "Expected: 1 , Actual: " << col_has_no_threes_of_color(board3, size_3, 3, RED) << endl;
  cout << "Expected: 0 , Actual: " << col_has_no_threes_of_color(board3, size_3, 4, BLUE) << endl;
  cout << "Expected: 1 , Actual: " << col_has_no_threes_of_color(board3, size_3, 4, RED) << endl;
  cout << "Expected: 0 , Actual: " << col_has_no_threes_of_color(board3, size_3, 5, RED) << endl;
}
void test_board_has_no_threes(){
    int board3[MAX_SIZE][MAX_SIZE];
    string test_board_3[] ={
        "XO--X-",
        "XO-OO-",
        "XXXOOX",
        "OOOOOX",
        "-OX-XX",
        "-OX-X-"
    };
    
    int size_3 = 6;
    read_board_from_string(board3, test_board_3, size_3);
    cout << "Testing Board 3" << endl;
    cout << "Expected: 0 , Actual: " << board_has_no_threes(board3, size_3) << endl;
    
    int board4[MAX_SIZE][MAX_SIZE];
    string test_board_4[] ={
        "---X--",
        "-O--O-",
        "X---XX",
        "O-X-O-",
        "-OO-XX",
        "-OX-X-"
    };
    
    int size_4 = 6;
    read_board_from_string(board4, test_board_4, size_4);
    cout << "Expected: 1 , Actual: " << board_has_no_threes(board4, size_4) << endl;
    
    int board5[MAX_SIZE][MAX_SIZE];
    string test_board_5[] ={
        "-XXX--",
        "------",
        "------",
        "------",
        "------",
        "------"
    };
    
    int size_5 = 6;
    read_board_from_string(board5, test_board_5, size_5);
    cout << "Board 5: Expected: 0 , Actual: " << board_has_no_threes(board5, size_5) << endl;
    
    int board6[MAX_SIZE][MAX_SIZE];
    string test_board_6[] ={
        "-XOX--",
        "------",
        "------",
        "-OOO--",
        "------",
        "------"
    };
    
    int size_6 = 6;
    read_board_from_string(board6, test_board_6, size_6);
    cout << "Board 6: Expected: 0 , Actual: " << board_has_no_threes(board6, size_6) << endl;
    
    int board7[MAX_SIZE][MAX_SIZE];
    string test_board_7[] ={
        "-XOX--",
        "-X----",
        "-X----",
        "-OXO--",
        "------",
        "------"
    };
    
    int size_7 = 6;
    read_board_from_string(board7, test_board_7, size_7);
    cout << "Board 7: Expected: 0 , Actual: " << board_has_no_threes(board7, size_7) << endl;
    
    int board8[MAX_SIZE][MAX_SIZE];
    string test_board_8[] ={
        "-XOX--",
        "-O----",
        "-X----",
        "-OXO--",
        "---O--",
        "---O--"
    };
    
    int size_8 = 6;
    read_board_from_string(board8, test_board_8, size_8);
    cout << "Board 8: Expected: 0 , Actual: " << board_has_no_threes(board8, size_8) << endl;
}
void test_rows_are_different(){
    int board9[MAX_SIZE][MAX_SIZE];
    string test_board_9[] ={
        "XOXXOO",
        "XOXXOO",
        "XXXOOX",
        "OOOOOX",
        "-OX-XX",
        "-OX-X-"
    };
    
    int size_9 = 6;
    read_board_from_string(board9, test_board_9, size_9);
    cout << "Testing Board 9" << endl;
    cout << "Expected: 0 , Actual: " << rows_are_different(board9, size_9, 0, 1) << endl;
    
    int board10[MAX_SIZE][MAX_SIZE];
     string test_board_10[] ={
           "XO-XOO",
           "XOXXO-",
           "XXOXOO",
           "XXOXOO",
           "-OX-XX",
           "-OX-X-"
       };
     int size_10 = 6;
     read_board_from_string(board10, test_board_10, size_10);
     cout << "Testing Board 10" << endl;
     cout << "Expected: 0 , Actual: " << rows_are_different(board10, size_10, 2, 3) << endl;
     int board11[MAX_SIZE][MAX_SIZE];
     string test_board_11[] ={
           "XO-XOO",
           "XOXXO-",
           "XXOXOO",
           "XXOXXO",
           "-OX-XX",
           "-OX-X-"
       };
     int size_11 = 6;
     read_board_from_string(board11, test_board_11, size_11);
     cout << "Testing Board 11" << endl;
     cout << "Expected: 1 , Actual: " << rows_are_different(board11, size_11, 2, 3) << endl;
     
   int board12[MAX_SIZE][MAX_SIZE];
     string test_board_12[] ={
           "XO-XOO",
           "XOXXO-",
           "XXOX-O",
           "XXOXOO",
           "-OX-XX",
           "-OX-X-"
       };
     int size_12 = 6;
     read_board_from_string(board12, test_board_12, size_12);
     cout << "Testing Board 12" << endl;
     cout << "Expected: 1 , Actual: " << rows_are_different(board12, size_12, 2, 3) << endl;
     }

void test_cols_are_different(){
    int board13[MAX_SIZE][MAX_SIZE];
    string test_board_13[] ={
        "XOXXOO",
        "OOOOOO",
        "XXXXOX",
        "OOOOOX",
        "XOXXXX",
        "OOXOX-"
    };
    
    int size_13 = 6;
    read_board_from_string(board13, test_board_13, size_13);
    cout << "Testing Board 13" << endl;
    cout << "Expected: 0 , Actual: " << cols_are_different(board13, size_13, 0, 3) << endl;

int board14[MAX_SIZE][MAX_SIZE];
    string test_board_14[] ={
        "XOXXOO",
        "OOXOOO",
        "XXXXOX",
        "OOOOOX",
        "OOXOXX",
        "XOXXX-"
    };
    
    int size_14 = 6;
    read_board_from_string(board14, test_board_14, size_14);
    cout << "Testing Board 14" << endl;
    cout << "Expected: 1 , Actual: " << cols_are_different(board14, size_14, 0, 2) << endl;

int board15[MAX_SIZE][MAX_SIZE];
    string test_board_15[] ={
        "XOXXOO",
        "OOXOOO",
        "XXXXOX",
        "OOOOOX",
        "OOX-XX",
        "XOXXO-"
    };
    
    int size_15 = 6;
    read_board_from_string(board15, test_board_15, size_15);
    cout << "Testing Board 15" << endl;
    cout << "Expected: 1 , Actual: " << cols_are_different(board15, size_15, 0, 3) << endl;

int board16[MAX_SIZE][MAX_SIZE];
    string test_board_16[] ={
        "XOXXOX",
        "OOXOOO",
        "XXXXOX",
        "OOOOOO",
        "OOX-XO",
        "XOXXOX"
    };
    
    int size_16 = 6;
    read_board_from_string(board16, test_board_16, size_16);
    cout << "Testing Board 16" << endl;
    cout << "Expected: 0, Actual: " << cols_are_different(board16, size_16, 0, 5) << endl;

}

void test_board_has_no_duplicates(){
    int board17[MAX_SIZE][MAX_SIZE];
    string test_board_17[] ={
        "XOXXOO",
        "XOXOXO",
        "XXOOOX",
        "OOOOOX",
        "XOXOXO",
        "OOXOXX"
    };
    
    int size_17 = 6;
    read_board_from_string(board17, test_board_17, size_17);
    cout << "Testing Board 17" << endl;
    cout << "Expected: 0 , Actual: " << board_has_no_duplicates(board17, size_17) << endl;
    
    int board18[MAX_SIZE][MAX_SIZE];
    string test_board_18[] ={
        "XOXXOO",
        "XOXXXO",
        "XXOXOX",
        "OXOOXX",
        "OXOOOX",
        "OOXOXX"
    };
    
    int size_18 = 6;
    read_board_from_string(board18, test_board_18, size_18);
    cout << "Testing Board 18" << endl;
    cout << "Expected: 0 , Actual: " << board_has_no_duplicates(board18, size_18) << endl;
    
    int board19[MAX_SIZE][MAX_SIZE];
    string test_board_19[] ={
        "XOXXOO",
        "XOX-XO",
        "XXOOOX",
        "OXOOXX",
        "OXOXOX",
        "OOXOXX"
    };
    
    int size_19 = 6;
    read_board_from_string(board19, test_board_19, size_19);
    cout << "Testing Board 19" << endl;
    cout << "Expected: 1 , Actual: " << board_has_no_duplicates(board19, size_19) << endl;
    
    int board20[MAX_SIZE][MAX_SIZE];
    string test_board_20[] ={
        "XOXOXO",
        "OXOXOX",
        "XXOOXO",
        "OOXXOX",
        "OOOXXX",
        "XXXXOO"
    };
    
    int size_20 = 6;
    read_board_from_string(board20, test_board_20, size_20);
    cout << "Testing Board 20" << endl;
    cout << "Expected: 1 , Actual: " << board_has_no_duplicates(board20, size_20) << endl;
}

void test_solve_three_in_a_row(){
    int board21[MAX_SIZE][MAX_SIZE];
    string test_board_21[] ={
        "-XOXO-",
        "XX--OX",
        "OX--XX",
        "X-XX-O",
        "--OO--",
        "-OOXX-"
    };
    
    int size_21 = 6;
    read_board_from_string(board21, test_board_21, size_21);
    cout << "Testing Board 21" << endl;
    cout << "Expected: XXO-OX , Actual: ";
    solve_three_in_a_row(board21, size_21, 1, true);
    cout<< endl;
    cout << "Expected: OX-OXX , Actual: ";
    solve_three_in_a_row(board21, size_21, 2, true);
    cout<< endl;
    cout << "Expected: XOXXOO , Actual: ";
    solve_three_in_a_row(board21, size_21, 3, true);
    cout<< endl;
    cout << "Expected: -XOOX- , Actual: ";
    solve_three_in_a_row(board21, size_21, 4, true);
    cout<< endl;
    cout << "Expected: XOOXXO , Actual: ";
    solve_three_in_a_row(board21, size_21, 5, true);
    cout<< endl;
     
    int board200[MAX_SIZE][MAX_SIZE];
    string test_board_200[] ={
        "-O--X-",
        "OO--OX",
        "OXOX-O",
        "-----X",
        "X-O-X-",
        "-X--O-"
    };
    
    int size_200 = 6;
    read_board_from_string(board200, test_board_200, size_200);
    cout << "Testing Board 200" << endl;
    cout << "Expected: XXO-OX , Actual: ";
    solve_three_in_a_row(board200, size_200, 4, true);
    cout<< endl;
    int board201[MAX_SIZE][MAX_SIZE];
    string test_board_201[] ={
        "X--X--",
        "------",
        "X-X--X",
        "-----O",
        "-OXO-X",
        "--XX-O"
    };
    
    int size_201 = 6;
    read_board_from_string(board201, test_board_201, size_201);
    cout << "Testing Board 201" << endl;
    cout << "Expected: XXO-OX , Actual: ";
    solve_three_in_a_row(board201, size_201, 5, true);
    cout<< endl;
}

void test_solve_three_in_a_column(){
    int board22[MAX_SIZE][MAX_SIZE];
    string test_board_22[] ={
        "-XOXO-",
        "XX--OX",
        "X---XX",
        "O-OX-O",
        "-OOOX-",
        "-OXXX-"
    };
    
    int size_22 = 6;
    read_board_from_string(board22, test_board_22, size_22);
    cout << "Testing Board 22" << endl;
    cout << "Expected: (1, A) as O , Actual: ";
    solve_three_in_a_column(board22, size_22, 0, true);
    cout<< endl;
  
    cout << "Expected: (3, B) as O and (4, B) as X  , Actual: ";
    solve_three_in_a_column(board22, size_22, 1, true);
    cout<< endl;

    cout << "Expected: (3, C) as X , Actual: ";
    solve_three_in_a_column(board22, size_22, 2, true);
    cout<< endl;

    cout << "Expected: nothing , Actual: ";
    solve_three_in_a_column(board22, size_22, 3, true);
    cout<< endl;

    cout << "Expected: (4, E) as O, Actual: ";
    solve_three_in_a_column(board22, size_22, 4, true);
    cout<< endl;

    cout << "Expected: (1, F) as O, Actual: ";
    solve_three_in_a_column(board22, size_22, 5, true);
    cout<< endl;
}

void test_solve_balance_row(){
    int board23[MAX_SIZE][MAX_SIZE];
    string test_board_23[] ={
        "-X-OXX",
        "XX-X--",
        "XO--OO",
        "O-O--O",
        "-OOOX-",
        "-OXOXX"
    };
    
    int size_23 = 6;
    read_board_from_string(board23, test_board_23, size_23);
    cout << "Testing Board 23" << endl;
    cout << "Expected: OXOOXX, Actual: ";
    solve_balance_row(board23, size_23, 0, true);
    cout<< endl;
    cout << "Expected: XXOXOO, Actual: ";
    solve_balance_row(board23, size_23, 1, true);
    cout<< endl;
    cout << "Expected: XOXXOO, Actual: ";
    solve_balance_row(board23, size_23, 2, true);
    cout<< endl;
    cout << "Expected: OXOXXO, Actual: ";
    solve_balance_row(board23, size_23, 3, true);
    cout<< endl;
    cout << "Expected: XOOOXO, Actual: ";
    solve_balance_row(board23, size_23, 4, true);
    cout<< endl;
    cout << "Expected: OOXOXX, Actual: ";
    solve_balance_row(board23, size_23, 5, true);
    cout<< endl;
}
void test_solve_balance_column(){
    int board24[MAX_SIZE][MAX_SIZE];
    string test_board_24[] ={
        "-O-OOX",
        "XXOX-X",
        "XX-OXO",
        "O-O--X",
        "XXOOX-",
        "--X-X-"
    };
    
    int size_24 = 6;
    read_board_from_string(board24, test_board_24, size_24);
    cout << "Testing Board 24" << endl;
    cout << "Expected: (1,A) is O and (6,A) is O Actual: ";
    solve_balance_column(board24, size_24, 0, true);
    cout << endl;
    cout << "Expected: (4,B) is O and (6,B) is O Actual: ";
    solve_balance_column(board24, size_24, 1, true);
    cout << endl;
    cout << "Expected: (1,C) is X and (3, C) is X Actual: ";
    solve_balance_column(board24, size_24, 2, true);
    cout << endl;
    cout << "Expected: (4,D) is X and (6, D) is X Actual: ";
    solve_balance_column(board24, size_24, 3, true);
    cout << endl;
    cout << "Expected: (2,E) is O and (4, E) is O Actual: ";
    solve_balance_column(board24, size_24, 4, true);
    cout << endl;
    cout << "Expected: (5,F) is O and (6, F) is O Actual: ";
    solve_balance_column(board24, size_24, 5, true);
    cout << endl;
  }
void test_board_is_solved(){
    int board25[MAX_SIZE][MAX_SIZE];
    string test_board_25[] ={
        "OXOXOX",
        "OOXOXX",
        "XOXXOO",
        "OXOXXO",
        "XOXOOX",
        "XXOOXO"
    };
    
    int size_25 = 6;
    read_board_from_string(board25, test_board_25, size_25);
    cout << "Testing Board 25" << endl;
    cout << "Expected: 1, Actual: " << board_is_solved(board25, size_25);
    cout << endl;
    
    int board26[MAX_SIZE][MAX_SIZE];
    string test_board_26[] ={
        "OXOXOX",
        "OOXOXX",
        "XO-XOO",
        "OXOXXO",
        "XOXOOX",
        "XXOOXO"
    };
    
    int size_26 = 6;
    read_board_from_string(board26, test_board_26, size_26);
    cout << "Testing Board 26" << endl;
    cout << "Expected: 0, Actual: " << board_is_solved(board26, size_26);
    cout << endl;
    
    int board27[MAX_SIZE][MAX_SIZE];
    string test_board_27[] ={
        "OXOXOX",
        "OOXOXX",
        "OOOXOO",
        "OXOXXO",
        "XOXOOX",
        "XXOOXO"
    };
    
    int size_27 = 6;
    read_board_from_string(board27, test_board_27, size_27);
    cout << "Testing Board 27" << endl;
    cout << "Expected: 0, Actual: " << board_is_solved(board27, size_27);
    cout << endl;
}

void test_check_valid_input(){
    int board28[MAX_SIZE][MAX_SIZE];
    string test_board_28[] ={
        "OXOXOX",
        "OO-OXX",
        "XOX-OO",
        "OXOX-O",
        "-OXOOX",
        "X-OO-O"
    };
    
    int size_28 = 6;
    read_board_from_string(board28, test_board_28, size_28);
    int row;
    int col;
    cout << "Testing Board 28" << endl;
    cout << "Expected: 1, Actual: " << check_valid_input(6, 2, 'c','x',row, col);
    cout << endl;
    cout << "Expected: 0, Actual: " << check_valid_input(6, 2, 'p','x',row, col);
    cout << endl;
    cout << "Expected: 0, Actual: " << check_valid_input(6, 7, 'c','o',row, col);
    cout << endl;
    cout << "Expected: 1, Actual: " << check_valid_input(6, 2, 'c','-',row, col);
    cout << endl;
    cout << "Expected: 1, Actual: " << check_valid_input(6, 5, 'A','X',row, col);
    cout << endl;
}
void test_check_valid_move(){
    int board29[MAX_SIZE][MAX_SIZE];
    string test_board_29[] ={
        "OXOXOX",
        "OO-OXX",
        "XOX-OO",
        "OXOX-O",
        "-OXOOX",
        "X-OO-O"
    };
    int board30[MAX_SIZE][MAX_SIZE];
    string test_board_30[] ={
        "OXOXOX",
        "OOXOXX",
        "XOX-OO",
        "OXOX-O",
        "-OXOOX",
        "X-OO-O"
    };
    
    int size_29 = 6;
    int size_30 = 6;
    read_board_from_string(board29, test_board_29, size_29);
    read_board_from_string(board30, test_board_30, size_30);
    cout << "Testing Board 29/30" << endl;
    cout << "Expected: 1, Actual: " << check_valid_move(board29, board30, size_29,2,3,RED) << endl;
    cout << "Expected: 0, Actual: " << check_valid_move(board29, board30, size_29,0,0,RED) << endl;
    cout << "Expected: 0, Actual: " << check_valid_move(board29, board30, size_29,5,4,BLUE) << endl;

}
