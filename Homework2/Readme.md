## Homework: Bit Streams

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

**See the video below for more information:**
</br>

[![asciicast](https://asciinema.org/a/01mvrozde7j3ymcxpwthz9re1.png)](https://asciinema.org/a/01mvrozde7j3ymcxpwthz9re1)

#### Getting Started
1. **[Download](https://github.com/xaviermerino/ECE1552/blob/master/Homework2/hwk2-student.zip?raw=true)** the starter file set. It will contain the following files:
    * `main.cpp`
    * `catch.hpp`
2. Use your favorite IDE or editor to modify your files. Include the given files in a project or compile them using your compiler of choice.
3. If you try running the program it will tell you that it has **failed all the tests**.
4. Your goal is to make the program **pass all the tests** by completing the assignment. Your code should be placed inside the `studentCode()` function, in between the `startRecording()` and `stopRecording()` calls.

```c++
void studentCode(){
    injectInput(userInput);
    startRecording();

    // Student code goes here.

    stopRecording();
}
```
When compiling the program for the first time you should get the following message:

```
===============================================================================
test cases: 6 | 6 failed
assertions: 6 | 6 failed
```

Once you have completed the assignment your goal is to pass all the tests and obtain this output:

```
All tests passed (6 assertions in 6 test cases)
```

This is provided for you to get feedback on your code. You can attempt to fix it and prepare it for submission once it passes all the tests. Once submitted, a set of similar tests will be run on your solution.

#### Submission
You are expected to submit your a zip file in Canvas by the specified deadline. The zip file name must match your Tracks ID. For instance, if your Tracks ID is *aLastname2016* then your zip file should be called **aLastname2016.zip**. The zip file should only contain the `main.cpp` file. Submit under Homework #4.
