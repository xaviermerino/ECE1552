## Practice Questions
The following questions are not for credit. Use them as supplemental material to study for your quizzes and prepare for your future homework assignments.

* **Question #1:** Use a one-dimensional array to solve the following problem. Read in 20 numbers, each of which is between 10 and 100. As each number is read validate it and store it in the array. After reading all the values, display only the unique values that the user entered. Make sure you account for the worst case scenario in which all 20 numbers are different. Use the smallest possible array to solve this problem.

```
Input a number between 10 and 100: 10
Input a number between 10 and 100: 10
Input a number between 10 and 100: 10
Input a number between 10 and 100: 11
Input a number between 10 and 100: 11
Input a number between 10 and 100: 12
Input a number between 10 and 100: 13
Input a number between 10 and 100: 13
Input a number between 10 and 100: 13
Input a number between 10 and 100: 13
Input a number between 10 and 100: 13
Input a number between 10 and 100: 14
Input a number between 10 and 100: 14
Input a number between 10 and 100: 15
Input a number between 10 and 100: 16
Input a number between 10 and 100: 17
Input a number between 10 and 100: 18
Input a number between 10 and 100: 19
Input a number between 10 and 100: 20
Input a number between 10 and 100: 22

Printing unique numbers:
10
11
12
13
14
15
16
17
18
19
20
22
```

* **Question #2:** Populate a one-dimensional array with ten unique random numbers. Print the array to see what values were written in it. Repeatedly ask the user to type a number. If the number is in the array, remove it and shift each following element to the left. Add a zero at the end of the array.

```
Original Array:
	numbers[0] = 8
	numbers[1] = 50
	numbers[2] = 74
	numbers[3] = 59
	numbers[4] = 31
	numbers[5] = 73
	numbers[6] = 45
	numbers[7] = 79
	numbers[8] = 24
	numbers[9] = 10

Delete number (-1 to quit): 50

Delete number (-1 to quit): 31

Delete number (-1 to quit): -1

Modified Array:
	numbers[0] = 8
	numbers[1] = 74
	numbers[2] = 59
	numbers[3] = 73
	numbers[4] = 45
	numbers[5] = 79
	numbers[6] = 24
	numbers[7] = 10
	numbers[8] = 0
	numbers[9] = 0
```
