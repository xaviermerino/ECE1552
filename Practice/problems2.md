## Practice Questions
The following questions are not for credit. Use them as supplemental material to study for your quizzes and prepare for your future homework assignments.

* **Question #1:** Write a program that prints an empty student roster template. The professor inputs the number of students that he has and the program generates an empty template for the professor to fill in. Make sure to include `iomanip` and `iostream` for this exercise. You might want to take a look at how to use `setw()` and `setfill()` with `cout`. Some special requirements need to be followed: <\br>
  * The `First Name` field width is 15 characters.
  * The `Last Name` field width is 15 characters.
  * The `Age` field width is 5 characters.
  * The program should only generate an output if the number of students is between 1 and 20. You should force the user to input a number in that range.

```
Empty Student Roster Maker

How many students do you have (1-20): 4

Making template roster for 4 student(s).

+---------------+---------------+-----+
| First Name    | Last Name     | Age |
+---------------+---------------+-----+
+               +               +     +
+---------------+---------------+-----+
+               +               +     +
+---------------+---------------+-----+
+               +               +     +
+---------------+---------------+-----+
+               +               +     +
+---------------+---------------+-----+
```

* **Question #2:** Write a program that simulates a 3x3 **Tic-Tac-Toe**. Use three variables to store numbers between 0 and 7. These variables will represent the rows.

See the number representation below.

<br>
![numbers](https://github.com/xaviermerino/ECE1552/blob/master/Practice/numbers.png?raw=true)

<br>
Your goal is to consider the binary representation of these numbers and output who the winner is.

Imagine that we use variables `row0`, `row1`, and `row2` to store the numbers `5`, `3`, and `0` respectively. This corresponds to the first case below.

<br>
![ttt](https://github.com/xaviermerino/ECE1552/blob/master/Practice/tictactoe.png?raw=true)

<br>
For that scenario your program should output:

```
The following 3x3 Tic-Tac-Toe was given:

1 0 1
0 1 1
0 0 0

Third Row Same
Who won?: 0
```
