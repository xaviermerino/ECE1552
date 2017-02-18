## Assignment #1: Control Structures and Bitwise Operators

### Overview
In this homework, you will apply the concepts of control structures – sequence, selection and repetition. In addition, you will apply the concept of bitwise operators to create a bit-stream buffer capable of storing and retrieving 1-byte values.

**In the process you will**:
* Develop problem solving skills with C++
* Learn and apply bitwise Operators
* Become comfortable with control Structures
* Use C++ fundamental data types
* Write simple decision-making statements.

### Problem #1: Palindromes
A palindrome is a number or a text phrase that reads the same backward as forward. For example, each of the following five-digit integers is a palindrome: 12321, 55555, 45554 and 11611. Write a program that reads in a five-digit integer and determines whether it’s a palindrome. *Hint: Use the division and modulus operators to separate the number into its individual digits.*

```
Enter a five-digit integer (or -1 to quit): 12321
The number 12321 is a palindrome!

Enter a five-digit integer (or -1 to quit): 12345
The number 12345 is not a palindrome.

Enter a five-digit integer (or -1 to quit): 123
The number 123 is not a five-digit number.

Enter a five-digit integer (or -1 to quit): -1
Good bye!
```

### Problem #2: More Palindromes
Repeat problem #1, but instead of reading a five-digit integer, now you have to retrieve an input string of any size from the user. If you encounter white spaces, you need to ignore them, for example, the following are palindromes: “bob”, “a car a man a maraca”, “a nut for a jar of tuna”, etc.

```
Enter a string (or -1 to quit): bob
The word “bob” is a palindrome!

Enter a string (or -1 to quit): car
The word “car” is not a palindrome.

Enter a string (or -1 to quit): a car a man a maraca
The statement “acaramanamaraca” is a palindrome!

Enter a string (or -1 to quit): -1
Good bye!
```

### Problem #3: Checkerboard Pattern of Asterisks
Write a program that displays the following checkerboard pattern. Your program must use only three output statements, one of each of the following forms:

```c++
cout << "* ";`
cout << ' ';
cout << endl;
```

See the sample output below:

```
* * * * * * * *
 * * * * * * * *
* * * * * * * *
 * * * * * * * *
* * * * * * * *
 * * * * * * * *
* * * * * * * *
```
