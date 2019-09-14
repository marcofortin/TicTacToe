#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

// print(board) prints the state of the board
void print(char board[]) {
  printf("| %c | %c | %c |\n"
         "| %c | %c | %c |\n"
         "| %c | %c | %c |\n", 
         board[0], board[1], board[2], board[3], 
         board[4], board[5], board[6], board[7], board[8]);
}

// win_check(square, board) returns true if there is a winner and false otherwise
bool win_check(int square, char board[]) {
  if (square == 0) {
             // horizontal line
    return (((board[0] == board[1]) && (board[0] == board[2]) && 
             (board[1] == board[2])) ||
            // vertical line
            ((board[0] == board[3]) && (board[0] == board[6]) && 
             (board[3] == board[6])) ||
            // diagonal line
            ((board[0] == board[4]) && (board[0] == board[8]) && 
             (board[4] == board[8])));
  }
  else if (square == 1) {
            // horizontal line
    return (((board[0] == board[1]) && (board[0] == board[2]) && 
             (board[1] == board[2])) ||
            // vertical line
            ((board[1] == board[4]) && (board[1] == board[7]) && 
             (board[4] == board[7])));
  }
  else if (square == 2) {
            // horizontal line
    return (((board[0] == board[1]) && (board[0] == board[2]) && 
             (board[1] == board[2])) ||
            // vertical line
            ((board[2] == board[5]) && (board[2] == board[8]) && 
             (board[5] == board[8])) ||
            // diagonal line
            ((board[2] == board[4]) && (board[2] == board[6]) && 
             (board[4] == board[6])));
  }
  else if (square == 3) {
            // horizontal line
    return (((board[3] == board[4]) && (board[3] == board[5]) && 
             (board[4] == board[5])) ||
            // vertical line
            ((board[0] == board[3]) && (board[0] == board[6]) && 
             (board[3] == board[6])));
  }
  else if (square == 4) {
            // horizontal line
    return (((board[3] == board[4]) && (board[3] == board[5]) && 
             (board[4] == board[5])) ||
            // vertical line
            ((board[1] == board[4]) && (board[1] == board[7]) && 
             (board[4] == board[7])) ||
            // diagonal line
            ((board[0] == board[4]) && (board[0] == board[8]) && 
             (board[4] == board[8])));
  }
  else if (square == 5) {
            // horizontal line
    return (((board[3] == board[4]) && (board[3] == board[5]) && 
             (board[4] == board[5])) ||
            // vertical line
            ((board[0] == board[3]) && (board[0] == board[6]) && 
             (board[3] == board[6])) ||
            // diagonal line
            ((board[2] == board[5]) && (board[2] == board[8]) && 
             (board[5] == board[8])));
  }
  else if (square == 6) {
            // horizontal line
    return (((board[6] == board[7]) && (board[6] == board[8]) && 
             (board[7] == board[8])) ||
            // vertical line
            ((board[0] == board[3]) && (board[0] == board[6]) && 
             (board[3] == board[6])) ||
            // diagonal line
            ((board[2] == board[4]) && (board[2] == board[6]) && 
             (board[4] == board[6])));
  }
  else if (square == 7) {
            // horizontal line
    return (((board[6] == board[7]) && (board[6] == board[8]) && 
             (board[7] == board[8])) ||
            // vertical line
            ((board[1] == board[4]) && (board[1] == board[7]) && 
             (board[4] == board[7])));
  }
  else {
            // horizontal line
    return (((board[6] == board[7]) && (board[6] == board[8]) && 
             (board[7] == board[8])) ||
            // vertical line
            ((board[2] == board[5]) && (board[2] == board[8]) && 
             (board[5] == board[8])) ||
            // diagonal line
            ((board[0] == board[4]) && (board[0] == board[8]) && 
             (board[4] == board[8])));
  }
}

// move(player, square, board) marks the given square for the given player
int move (int player, int square, char board[]) {
  // Sets the marker matching the player
  // Player 1: O, Player 2: X
  char marker;
  if (player == 1) {
    marker = 'O';
  }
  else if (player == 2) {
    marker = 'X';
  }
  // invalid move (case as already been marked)
  if (board[square - 1] != ' ') {
    printf("Sorry, invalid mode, try again.\n");
    return -1;
  }
  else {
      // mark the square
    board[square - 1] = marker;

    // checks for a winning move
    int is_winner = win_check(square - 1, board);

    if (is_winner) {
      // Winner found
      printf("Congratulation, player %d wins!\n", player);
      return 1;
    }
    // checks for a tie move (i.e all squares are  marked)
    else if ((board[0] != ' ') && (board[1] != ' ') && (board[2] != ' ')
          && (board[3] != ' ') && (board[4] != ' ') && (board[5] != ' ')
          && (board[6] != ' ') && (board[7] != ' ') && (board[8] != ' ' )) {
      printf("Tie game!\n");
      return 0;
    }
    // valid move and nothing happens
    else {
      return 2;
    }
  }
}


int main(void) {
  // Instructions
  printf("Hello, welcome to Tic Tac Toe.\n");
  printf("The rules are very simple:\n");
  printf("To make a move, type M, your player number, " 
         "and the square you wish to mark, for 1 to 9.\n");
  printf("An example of some input would be: M %d %d.\n", 1, 3);

  // Initialises the game
  char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

  // Warnings
  bool is_warned = false;

  // Commands
  char command;

  do {
    scanf(" %c", &command);
    if (('M' == command) || ('m' == command)) {
      int player = 0;
      int square = 0;
      scanf("%d", &player);
      scanf("%d", &square);
      if ((player == 1 || player == 2) && (square > 0 && square < 10)) {
        int result = move(player, square, board);
        if (result == 0 || result == 1) {
          // We have a winner or Tie game
          command = EOF;
        }
        else if (result == -1) {
          is_warned = true;
        }
        print(board);
      }
      else {
        printf("Sorry, invalid format of command, please try again.\n");
        is_warned = true; // only 1 warning
      }
    }
    else if (!is_warned) {
      printf("Sorry, invalid format of command, please try again.\n");
      is_warned = true; // only 1 warning
    }
    else {
      command = EOF; // second mistake, game ends
    }
  } while (command != EOF);

  printf("Thank you for playing.\n");
  printf("Exiting now...\n");

}
