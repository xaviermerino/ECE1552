## Practice Questions
The following questions are not for credit. Use them as supplemental material to study for your quizzes and prepare for your future homework assignments.

* **Question #1:** Write a program that prints an empty student roster template. The professor inputs the number of students that he has and the program generates an empty template for the professor to fill in. Make sure to include `iomanip` and `iostream` for this exercise. You might want to take a look at how to use `setw()` and `setfill()` with `cout`.

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

Some special requirements need to be followed:
* The `First Name` field width is 15 characters.
* The `Last Name` field width is 15 characters.
* The `Age` field width is 5 characters.


* **Question #2:** Write a program that requests an integer input from the user and verifies if it is a prime number. The program should repeatedly asks for numbers unless a -1 is given as an input. The program should only take numbers between 1 and 1000.

```
Give me a number: 9
Not prime

Give me a number: 5
Prime

Give me a number: 1234
Number should only be between 1 - 1000.

Give me a number: 7
Prime

Give me a number: -1
Bye Bye
```

* **Question #3:** Write a program that tells you the largest factor of a number supplied by the user. See the sample output below.

```
Give me a number: 24
Largest factor is 12.
```

* **Question #4:** Write a program that prints an empty diamond of stars. The user provides the height.

```
Diamond's height: 7

      *
    *   *
  *       *
*           *
  *       *
    *   *
      *
```

* **Question #5:** Write a program that prints an X of stars. The user provides the height.

```
X's height: 7

*     *
 *   *
  * *
   *
  * *
 *   *     
*     *
```
