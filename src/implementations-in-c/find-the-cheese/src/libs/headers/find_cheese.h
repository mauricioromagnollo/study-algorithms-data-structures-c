#ifndef FIND_CHEESE_H_INCLUDED
#define FIND_CHEESE_H_INCLUDED

#define CHEESE_ID 1
#define LABYRINTH_WALL_ID -1
#define BLOCKED_PATH_ID 0

typedef enum { false, true } bool;
typedef unsigned int dimension_t, board_t, value_t;

typedef struct {
  value_t posLine;
  value_t posColumn;
  value_t id;
} cheese_t;

typedef struct {
  dimension_t columns;
  dimension_t lines;
} board_size_t;

/**
 * Print title FIND THE CHEESE!
 */ 
void printTitle();
/**
 * Receive user input:
 *  - Number of Lines and Columns for Board;
 *  - Position to insert Cheese in the Board;
 */ 
void getUserInput(board_size_t *, cheese_t *);
/**
 * Return a new Board:
 */ 
board_t ** newBoard(board_size_t);
/**
 * Free all board from memory;
 */ 
void deleteBoard(board_t **, board_size_t);
/**
 * Inserts the markings on the board, including the position of the cheese.
 */ 
void setMarkingsOnTheBoard(board_t **, board_size_t, cheese_t);
/**
 * Prints the board and markings.
 */
void printBoard(board_t **, board_size_t);

#endif // FIND_CHEESE_H_INCLUDED
