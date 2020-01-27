#include <stdio.h>
#include <stdlib.h>

#include "./libs/headers/find_cheese.h"
#include "./libs/headers/system.h"

int main(int argc, char *argv[]) {
  
  cheese_t cheese;
  board_size_t boardSize;
  board_t **board = NULL;  

  setUTF8();
  clearScreen();

  printTitle();
  getUserInput(&boardSize, &cheese);

  board = newBoard(boardSize);
  setMarkingsOnTheBoard(board, boardSize, cheese);

  // ...
  
  deleteBoard(board, boardSize);

  return 0;
}
