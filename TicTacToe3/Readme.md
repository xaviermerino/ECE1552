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
* **Row 1:** The row containing the binary representation `1??`.
* **Row 2:** The row containing the binary representation `?11`.
* **Row 3:** The row containing the binary representation `000`.

</br>

You might have noticed that our Tic-Tac-Toe uses three bits per row to represent a match. This means that each row can be represented by an integer number between 0 and 7. The picture below shows all of these numbers and their binary representation.

</br>

![game](https://github.com/xaviermerino/ECE1552/blob/master/TicTacToe3/decimal-representation.png?raw=true)

</br>

Each of the rows above can be easily represented with a variable that holds an integer number. An appropriate data type for this task would be `unsigned short` or `unsigned int`. A variable of type `unsigned short` can hold up to 2 bytes of information. A variable of type `unsigned int` can hold up to 4 bytes of information. Because we only need three bits per row we can use three `unsigned short` variables.

#### Problem Solving Steps

1. **Who goes first?:** Your program must ask if the user wants to go first. If the user does not want to go first then the computer starts as X.

![whostarts](https://github.com/xaviermerino/ECE1552/blob/master/TicTacToe3/WhoGoesFirst%3F.png?raw=true)

2. **User's move:** Your program must wait until the user clicks on an available spot to place their token. 

![usermove](https://github.com/xaviermerino/ECE1552/blob/master/TicTacToe3/UserMove.png?raw=true)

3. **Computer's move:** The computer randomly selects a position in the board to place its token and performs the move. (Hint: use the [`rand()`](http://www.cplusplus.com/reference/cstdlib/rand/) function to generate random numbers) 

![pcmove](https://github.com/xaviermerino/ECE1552/blob/master/TicTacToe3/PCMove.png?raw=true)

4. **Game goes on:** Game keeps repeating until there is a tie or a win.

![game](https://github.com/xaviermerino/ECE1552/blob/master/TicTacToe3/RemainingMoves.png?raw=true)

4. **Game ends:** If the game ends, then a dialog will appear showing who won and asking the user if he wants to play again. 

![whostarts](https://github.com/xaviermerino/ECE1552/blob/master/TicTacToe3/Wins.png?raw=true)

#### Tic-Tac-Toe Example
Your output should match the example provided below.

[![asciicast](https://asciinema.org/a/0Zb7ijhQC6jj7uSRU0f64bIP3.png)](https://asciinema.org/a/0Zb7ijhQC6jj7uSRU0f64bIP3)
