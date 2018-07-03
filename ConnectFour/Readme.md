## Connect Four

### Overview
**Connect Four** is a two-player connection game. The players choose a color and take turns dropping one colored disc from the top into a seven-column, six-row vertically suspended grid. The pieces fall straight down, occupying the next available space within the column. The game's objective is to be the first player to form a horizontal, vertical, or diagonal line of four of one's own discs. 

In this session, you will implement **Connect Four** by making use of **bitwise operators** and **arrays**. You will be recreating the game in C++ using console input and output.

**In the process you will:**
  * Make use of **control** and **repetition** structures for input validation.
  * Make use of **arrays** to store the grid's rows.
  * Make use of **bitwise operators** to handle the underlying bits in a row.
  * Apply **formatting** rules to console output.
  * Replicate the **gameplay** of the Connect Four game.


### Introduction to Connect Four
Connect Four is a kid's game consisting of a 6x7 grid and two players. The players, **Red** and **Yellow**, take turns dropping a disc into any slot in the top of the grid. The game continues until a player gets four of their color discs in a row (horizontally, vertically, or diagonally). The first player to put four discs in a row wins.

</br>

![connectfour](https://upload.wikimedia.org/wikipedia/commons/a/ad/Connect_Four.gif)

</br>

### Your Task
Your task is to write a program that recreates the gameplay of **ConnectFour** and determines who won. 

Let's assume we have the match below. From the rightmost grid it is clear that the red player won the match. We are using a **zero** to represent the red player's tokens and a **one** to represent the yellow player's tokens.

</br>

![game](https://github.com/xaviermerino/ECE1552/blob/master/ConnectFour/representation.png?raw=true)

</br>

We use an array to store all of the rows. Each of the rows above can be easily represented with a variable that holds an integer number. An appropriate data type for this task would be `unsigned short` or `unsigned int`. A variable of type `unsigned short` can hold up to 2 bytes of information. A variable of type `unsigned int` can hold up to 4 bytes of information. Because we only need seven bits per row we can employ an array that stores six `unsigned short` elements.

#### Problem Solving Steps

1. **Who goes first?:** Your program must ask the user if he wishes to go first. The player who goes first plays the red tokens. The other player uses the yellow tokens. Remember to validate the user's input.

```
Connect Four

Do you want to go first? (Y/N): Y

You start as the Red token.
The PC is the Yellow token.
```

2. **Display the board:** Your program must then display the game board.

```
Game:

  0   1   2   3   4   5   6

|   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |
-----------------------------
```

3. **User's move:** Ask the user to place a token in a column. The token drops to the bottom of the column. Validate the user's input to ensure that the column is within the bounds of the game. If a column is filled or outside the bounds of the game, ask the user to pick another column.

```
Pick a column (0 - 6): 1
```

```
Pick a column (0 - 6): 8
Can't pick that column! Try again.
```

4. **Computer's move:** After the user has played. The computer will play automatically. The computer chooses a random column to play. The computer must pick a valid column at all times. If there are no empty spots on a column and there is no winner, then the game is a tie.

```
Pick a column (0 - 6): 1

Game:

  0   1   2   3   4   5   6

|   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |
|   | R |   |   |   |   | Y |
-----------------------------
```

4. **Who won?:** In order to win a player must place four tokens in a row to form a horizontal, vertical, or diagonal line. 
Make sure you use bitwise operators to extract the values from each row so you can test for the winning conditions.

```
Game:

  0   1   2   3   4   5   6

|   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |
|   |   |   | Y | R |   |   |
|   |   | Y | R | R | Y | R |
|   |   | R | Y | Y | Y | R |
|   | R | R | Y | Y | R | Y |
-----------------------------

The red player won.
```

5. **Play Again?:** In the end, you must ask the user if he wishes to **play again**. If he does then ask for his input again, otherwise end the program.

```
Would you like to play again? (Y / N): Y
```

#### Grading Criteria 

 - Implement an array as the basis of the game’s board. 

 - Use bitwise operators to set, clear, and get the values located at a specific bit position in a row. The rows are elements in the array specified above. The elements must be of type unsigned short or any other smaller data type that you see fit.

 - Perform input validation for all required user input. 

 - Be able to identify, in code, the next available space in a column. **Hint:** Use the following function prototype as an example.

```c++
short getFreeIndexForColumn(unsigned short column);
```

 - No magic numbers. Make appropriate use of constants. **Hint:** Use the following enum to represent tokens. 
 
```c++
enum Token {Red, Yellow};
```

 - Replicate the gameplay as indicated in the Problem Solving Steps section above. Detect who won or if the game resulted in a tie.
