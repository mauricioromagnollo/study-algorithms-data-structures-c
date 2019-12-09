#include <stdio.h>
#include "../headers/find_cheese.h"

void printTitle() {
  printf("\n\t*******************************");
  printf("\n\t     ## FIND THE CHEESE ##");
  printf("\n\t*******************************");
}

void getUserInput(board_size_t *board, cheese_t *cheese) {
  printf("\n=================================\n");
  printf("[*] USER INPUT INFORMATIONS:");
  printf("\n=================================\n");

  while (true) {
    printf("[*] Board Lines: ");
    scanf("%hi", &board->lines);

    if (board->lines < 0) {
      printf("\n[!] You cannot insert in this Line as it does not exist! Try again...\n");
    } else {
      break;
    }
  }

  while (true) {
    printf("[*] Board Columns: ");
    scanf("%hi", &board->columns);

    if (board->columns < 0) {
      printf("\n[!] You cannot insert in this Column as it does not exist! Try again...\n");
    } else {
      break;
    }
  }
 
  while (true) {
    
    printf("[*] Cheese Line Position: ");
    scanf("%hi", &cheese->posLine);
    
    if (cheese->posLine > board->lines || cheese->posLine < 0) {
      printf("\n[!] You cannot insert in this Line as it does not exist! Try again...\n");
      printf("[~] Enter a line greater or equal than 0 and less than %hi.\n", board->lines);
    } else {
      break;
    }
  }
  
  while (true) {
    printf("[*] Cheese Column Position: ");
    scanf("%hi", &cheese->posColumn);
    
    if (cheese->posColumn > board->columns || cheese->posColumn < 0) {
      printf("\n[!] You cannot insert in this Line as it does not exist! Try again...\n");
      printf("[~] Enter a line greater or equal than 0 and less than %hi.\n", board->columns);
    } else {
      break;
    }
  }

  cheese->id = CHEESE_ID;
}

board_t ** newBoard(board_size_t boardSize) {
  board_t **board = (dimension_t **) malloc(boardSize.lines * sizeof(dimension_t));
  for (dimension_t line = 0; line < boardSize.lines; line++) {
    board[line] = (dimension_t *) malloc(boardSize.columns * sizeof(dimension_t));
  }
  return (board);
}

void deleteBoard(board_t **board, board_size_t boardSize) {
  if (board == NULL) {
    printf("\n[*] The board has already been removed!\n");
  } else {
    for (dimension_t line = 0; line < boardSize.lines; line++) {
      free(board[line]);
    }
  }
}

void setMarkingsOnTheBoard(board_t **board, board_size_t boardSize, cheese_t cheese) {
  printf("\n");
}

void printBoard(board_t **board, board_size_t boardSize) {
  printf("\n");
}
