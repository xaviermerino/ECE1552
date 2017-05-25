## Lab: Tic-Tac-Toe

### Overview
In this lab you will become familiar with **bitwise operators** while rehearsing the skills obtained in the previous weeks. You will be recreating the Tic-Tac-Toe game in C++ using console input and output.

**In the process you will:**
  * Make use of **control** and **repetition** structures for input validation.
  * Make use of **bitwise operators** to handle the underlying bits in a variable.
  * Apply **formatting** rules to console output.
  * Replicate the **gameplay** of the Tic-Tac-Toe game.


### Introduction to Tic-Tac-Toe
Tic-Tac-Toe is a kid's game consisting of a 3x3 grid and two players. The players, X and O, take turns marking a spot in the grid. The player who places three marks in a horizontal, vertical, or diagonal row wins the game. It is also possible for the game to end in a tie. See an example below.

</br>

![tictactoe](https://upload.wikimedia.org/wikipedia/commons/thumb/1/1b/Tic-tac-toe-game-1.svg/800px-Tic-tac-toe-game-1.svg.png)

</br>

If you wish to play the game click [this link](https://playtictactoe.org).

### Lab Task
Your task in this session is to write a program that takes a Tic-Tac-Toe game and determines who won.
Let's assume we have the match below. From the left grid it is clear that player O won the match. The grid on the right is the match's binary representation. We are using a one to represent X's marks and a zero to represent O's marks.

</br>

![game](https://github.com/xaviermerino/ECE1552/blob/master/TicTacToe/Game1DecimalRepresentation.png?raw=true)

</br>

We then assign a label to each row and column to make it easier to locate where the players' marks are.

</br>

![game](https://github.com/xaviermerino/ECE1552/blob/master/TicTacToe/Game1Representationb.png?raw=true)

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

1. Your program must ask the user to **input the decimal representation** of each row. Remember to validate the user's input to enforce that the values are between 0 and 7. 

```
Input Row #1 (Values between 0-7): 5
Input Row #2 (Values between 0-7): 3
Input Row #3 (Values between 0-7): 0
```

2. Your program must then **display the match representation** of the given numbers. 

```
The following 3x3 Tic-Tac-Toe was given: 

     C1  C2  C3
   +---+---+---+
R1 | X | O | X |
   +---+---+---+
R2 | O | X | X |
   +---+---+---+
R3 | O | O | O |
   +---+---+---+
```

3. If the given match is not **possible** then you must ask the user to input valid values. 

```
Input Row #1 (Values between 0-7): 6
Input Row #2 (Values between 0-7): 6
Input Row #3 (Values between 0-7): 6

The following 3x3 Tic-Tac-Toe was given: 

     C1  C2  C3
   +---+---+---+
R1 | X | X | O |
   +---+---+---+
R2 | X | X | O |
   +---+---+---+
R3 | X | X | O |
   +---+---+---+

Not a valid Tic-Tac-Toe game!
Play again.

Input Row #1 (Values between 0-7):
...
...
```

4. If the given match is a valid Tic-Tac-Toe game then you must then **determine who won** and the mark combination that led the player to his victory. 

```
Input Row #1 (Values between 0-7): 5
Input Row #2 (Values between 0-7): 3
Input Row #3 (Values between 0-7): 0

The following 3x3 Tic-Tac-Toe was given: 

     C1  C2  C3
   +---+---+---+
R1 | X | O | X |
   +---+---+---+
R2 | O | X | X |
   +---+---+---+
R3 | O | O | O |
   +---+---+---+

Third Row Same
Who won?:  O 

Would you like to play again? (Y / N): 
``` 

5. In the end, you must ask the user if he wishes to **play again**. If he does then ask for his input again, otherwise end the program.

```
...
Third Row Same
Who won?:  O 

Would you like to play again? (Y / N): Y

Input Row #1 (Values between 0-7): 
...
...
```

