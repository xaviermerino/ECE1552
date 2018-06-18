## Lab: Tic-Tac-Toe

### Overview
In this section you will be expanding on your previous Tic-Tac-Toe game. We will be using the Qt Framework to provide a graphical user interface in C++.

![tictactoe](https://github.com/xaviermerino/ECE1552/blob/master/TicTacToe3/MainWindowInit.png?raw=true)

**In the process you will:**
  * Make use of **control** and **repetition** structures.
  * Make use of **bitwise operators** to handle the underlying bits in a variable.
  * Make use of `QWidgets` to display a **graphical user interface**.
  * Replicate the **gameplay** of the Tic-Tac-Toe game.


### Introduction to Tic-Tac-Toe
Tic-Tac-Toe is a kid's game consisting of a 3x3 grid and two players. The players, X and O, take turns marking a spot in the grid. The player who places three marks in a horizontal, vertical, or diagonal row wins the game. It is also possible for the game to end in a tie. See an example below.

</br>

![tictactoe](https://upload.wikimedia.org/wikipedia/commons/thumb/1/1b/Tic-tac-toe-game-1.svg/800px-Tic-tac-toe-game-1.svg.png)

</br>

If you wish to play the game click [this link](https://playtictactoe.org).

### Your Task
Your task in this session is to write a program that allows the user to play Tic-Tac-Toe against the computer.
You let the player decide whether he wants to start the match or let the computer start it. The player who starts the match is X. The other player is O. 

We do this by asking the user via a `dialog` as shown below.

![whostarts](https://github.com/xaviermerino/ECE1552/blob/master/TicTacToe3/WhoGoesFirst%3F.png?raw=true)

Let's assume we have the match below. From the top grid it is clear that player O won the match. The grid on the bottom is the match's binary representation. We are using a `1` to represent X's marks and a `0` to represent O's marks. We use the `?` symbol to represent values that have not been assigned. 

</br>

![game](https://github.com/xaviermerino/ECE1552/blob/master/TicTacToe3/match-binary-steps.png?raw=true)

</br>

We then assign a label to each row and column to make it easier to locate where the players' marks are.

</br>

![game](https://github.com/xaviermerino/ECE1552/blob/master/TicTacToe3/match-binary.png?raw=true)

</br>

We have:
* **Row 1:** The row containing the binary representation `101`.
* **Row 2:** The row containing the binary representation `011`.
* **Row 3:** The row containing the binary representation `000`.

</br>

You might have noticed that our Tic-Tac-Toe uses three bits per row to represent a match. This means that each row can be represented by an integer number between 0 and 7. The picture below shows all of these numbers and their binary representation.

</br>

![game](https://github.com/xaviermerino/ECE1552/blob/master/TicTacToe/numbers.png?raw=true)

</br>

Each of the rows above can be easily represented with a variable that holds an integer number. An appropriate data type for this task would be `unsigned short` or `unsigned int`. A variable of type `unsigned short` can hold up to 2 bytes of information. A variable of type `unsigned int` can hold up to 4 bytes of information. Because we only need three bits per row we can use three `unsigned short` variables.

#### Problem Solving Steps

1. **Who goes first?:** Your program must ask if the user wants to go first. If the user does not want to go first then the computer starts as X.

```
Tic-Tac-Toe

Would you like to go first? (Y/N): Y
```

2. **User's move:** Your program must ask the user to place his token on the board. The board spaces are numbered so that the user can tell you where to place it in the board. Remember to validate the user's input to enforce that the value chosen is in the board.

```
You start as X. I am O.

Tic-Tac-Toe Board:

     C1  C2  C3
   +---+---+---+
R1 | 1 | 2 | 3 |
   +---+---+---+
R2 | 4 | 5 | 6 |
   +---+---+---+
R3 | 7 | 8 | 9 |
   +---+---+---+

Select the square number you want to place an X on: 1
```

3. **Computer's move:** The computer randomly selects a position in the board to place its token and performs the move. (Hint: use the [`rand()`](http://www.cplusplus.com/reference/cstdlib/rand/) function to generate random numbers) It prints the new resulting board. It also prompts the user to keep playing if the game has not ended due to a tie or a win. 

```
Ok. I'll proceed. My turn.

Tic-Tac-Toe Board:

     C1  C2  C3
   +---+---+---+
R1 | X | 1 | 2 |
   +---+---+---+
R2 | 3 | 4 | 5 |
   +---+---+---+
R3 | 6 | 7 | O |
   +---+---+---+

Select the square number you want to place an X on: 
```

4. **Game ends:** If the game ends because a player wins, then the condition for winning will be displayed. Once the game ends, you need to ask the user if he wants to play again.

```
Ok. I'll proceed. My turn.
Third Column Same
Who won?:  O 

Tic-Tac-Toe Board:

     C1  C2  C3
   +---+---+---+
R1 | X | 1 | O |
   +---+---+---+
R2 | X | X | O |
   +---+---+---+
R3 | 2 | 3 | O |
   +---+---+---+

Would you like to play again? (Y/N): Y
```


#### Tic-Tac-Toe Example
Your output should match the example provided below.

[![asciicast](https://asciinema.org/a/0Zb7ijhQC6jj7uSRU0f64bIP3.png)](https://asciinema.org/a/0Zb7ijhQC6jj7uSRU0f64bIP3)
