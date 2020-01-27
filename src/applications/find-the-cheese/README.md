# Find the Cheese

Help a mouse find a piece of cheese in a maze like the one in the drawing
below:

![img](https://user-images.githubusercontent.com/38081852/70178115-6d32df00-16ba-11ea-9a4b-41ccd4712a25.png)

A general method to solve this problem is to dial the number **k (k = 1, 2, ... )** all free houses that are exactly **k - 1** steps away from the cheese, as short as possible.

Suppose that at each step the mouse can move only one square vertically or on the horizontal. Then, initially label the cheese position with 1 and for each **k > 2** examine all the free houses in the maze, marking with k those not yet marked and adjacent to any house marked with **k - 1**.

Dialing continues until a value of k (28 in the example below) is reached such that no house can be marked. At the end of the appointment we will have following matrix, assuming the cheese at (5,10):

![example](https://user-images.githubusercontent.com/38081852/70178547-40cb9280-16bb-11ea-9066-4f68372bab98.png)

The shortest path to the cheese can then be determined from the position mouse and passing each step to an adjacent square whose numbering is smaller than the than the current one.

For example, starting from [0,0] the mouse will need to scroll at least 26 squares to reach the cheese: [0,0], [1,0], [2,0], [3,0], [4,0], [4,1], [4,2], .... , [4.10], [5.10].

Given the maze (matrix L with elements 0 and  -1) and the positions of the mouse and cheese, determine the shortest way the mouse should go to find the cheese, if so way exists.

Tip: Write a function / procedure that dials receiving as matrix L, its dimensions and the position of the cheese) and another, which prints the path (taking as parameters the already marked L matrix, its dimensions and the starting position of the mouse).

### NOTE:
1. The size of the tray and the positions of the cheese and mouse shall be defined by the user.

2. The matrix representing the board shall be dynamically allocated using if a procedure.

3. Similarly, all dynamically allocated memory must be deallocated, after use using a procedure.