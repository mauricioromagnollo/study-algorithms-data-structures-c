# Naval Battle

The goal is to develop a Naval Battle game. Each player will try find and destroy as many of your opponent's boats. There will be three attempts to each person being performed alternately. Who wins the most points wins.

---
## Rules:
---
1. The **game board** is represented by a **15x15 matrix**. The data type of the matrix will depend on the way you prefer to control the game by considering the boats and the shots.

2. You can use one matrix for each player or just one matrix for both.

3. There are **two types of vessels - submarine and aircraft carrier**. The **submarine occupies a position [ i, j ] in the matrix**. The **aircraft carrier will occupy two positions**. For simplicity, consider only the positions horizontal.

4. **Randomly generate vessels** and their positions. You must generate **between 50 and 100 vessels**. Establish some criteria for defining the positions and types of vessels. Comment this at the beginning of your code.

5. At the beginning of the game, **you must request the name of each player**.

6. **Each person** will play alternately for a **total of three rounds**.

7. Each round, before the move is made, you must print the current state of the board. In  the positions where the **vessels have been destroyed, display as "*"**. In positions where a **shot was performed, but there was no vessel, present as "~"**. Present a blank space instead of positions with vessels not yet found. [Table 1](#table-1) gives an example of printing part of the board.

8. **The player informs the position (row and column) they wish to shoot**.

9. The **submarine's destruction** is worth **100 points** and the **aircraft carrier's worth 200 points**. **If one of the two aircraft carrier positions is reached, the entire vessel is destroyed**.

10. You will earn the player who scores the most points.

11. At the end of the game, print the full board, showing also the undamaged boats, each player's score and indicate the winner.

12. **After the result, you must allow a new game to be played or the program to be closed**.

13. Use functions and procedures to perform the operations - initializing the tray, printing, checking winner, among others.

### Table 1

![Table-1](https://user-images.githubusercontent.com/38081852/71391116-a091cb00-25e1-11ea-8cc6-1f7a4c8a5da8.png)
