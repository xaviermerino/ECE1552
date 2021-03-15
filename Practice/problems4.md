## Lab: Arrays

Complete the following problems and show them to your TA for credit.

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

* **Question #2:** Populate a one-dimensional array with ten unique random numbers between 1 and 100. Print the array to see what values were written in it. Repeatedly ask the user to type a number (until the user enters a -1). If the number is in the array, remove it and shift each following element to the left. Add a zero at the end of the array. In the end, print the modified array.

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

* **Question #3:** Populate a one-dimensional array with ten unique random numbers between 1 and 100. Print the array to see what values were written in it. Then, using [bubble sort](https://www.youtube.com/watch?v=yIQuKSwPlro), sort the numbers in ascending order. 

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

Sorted Array:
	numbers[0] = 8
	numbers[1] = 10
	numbers[2] = 24
	numbers[3] = 31
	numbers[4] = 45
	numbers[5] = 50
	numbers[6] = 59
	numbers[7] = 73
	numbers[8] = 74
	numbers[9] = 79
```

* **Question #4:** An LED chaser/sequencer is a popular driving LED driving circuit. Given that LED chasers are composed of several LEDs and follow a lighting pattern, arrays are a suitable data structure to organize and control the lights. Populate a one-dimensional array with five Arduino pins. These pins will be used to control the status of the LEDs. Feel free to mix between PWM pins (for fade-in, fade-out effects) and normal digital pins. You must implement three distinct lighting patterns and toggle between them by pressing a push button. 
