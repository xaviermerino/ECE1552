## Homework #2: Bit Streams

### Table of Contents
- [Overview](#overview)
- [Bit Streams](#homework-1-a-palindromes)
  - [Getting Started](#getting-started)
  - [Submission](#submission)

### Overview
In this homework, you will design a program that creates an 8-byte buffer capable of storing a 64-bit stream. You will be using bit manipulation techniques to achieve this.

**In the process you will**:
* Develop problem solving skills with C++
* Become comfortable with manipulating bits.
* Become comfortable with control structures.
* Use C++ fundamental data types
* Write simple decision-making statements.

---

### Bit Streams
You program shall allow the user to **store** and **retrieve** 8-bit values in each of the 8 location of the buffer. Since users can only enter and retrieve 1-byte values, **input shall be restricted** to numbers ranging between 0-255.

Also, since the buffer can only support 8 locations, the program shall allow users to enter a location index ranging from 0-7. Any **input outside of the ranges specified above shall be deemed invalid**, causing the program to display an error message to the user.

The **program shall execute in a loop**, until the user selects an option to exit the program.

The main menu of the program shall support the following options:
* **Display** to the console the 64-bit stream
* **Enter data** to the buffer by indicating a position in the buffer and data (1-byte) value
* Enter a position to **retrieve** a data value by entering an index position
* **Exit** program


```
Menu:_
1)_View_Buffer_Content
2)_Enter_Data_(0-255)
3)_Retrieve_Data
4)_Exit_program

Enter_option:_
```

Your code should create an alias named buffer for the type `unsigned long long` The buffer will be of type `buffer` (i.e., an alias).

**You can only use the assignment operator and bitwise operators to enter and retrieve data into/out of the buffer.**

[![asciicast](https://asciinema.org/a/01mvrozde7j3ymcxpwthz9re1.png)](https://asciinema.org/a/01mvrozde7j3ymcxpwthz9re1)
