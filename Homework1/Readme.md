## Homework #1: Control Structures

### Table of Contents
- [Overview](#overview)
- [Homework #1-A: Palindromes](#homework-1-a-palindromes)
  - [Getting Started](#getting-started)
  - [Submission](#submission)
- [Homework #1-B: More Palindromes](#homework-1-b-more-palindromes)
  - [Getting Started](#getting-started-1)
  - [Submission](#submission-1)
- [Homework #1-C: Pattern of Asterisks](#homework-1-c-pattern-of-asterisks)
  - [Getting Started](#getting-started-2)
  - [Submission](#submission-2)

### Overview
In this homework, you will apply the concepts of control structures – sequence, selection and repetition. You will practice the use of `if` statements to write programs that change its flow according to simple conditions. You will also make use of `for` and `while` loops to repeat code blocks while a condition holds. You will interact with the user via the console with the `cout` and `cin` statements.

**In the process you will**:
* Develop problem solving skills with C++
* Become comfortable with control Structures
* Use C++ fundamental data types
* Write simple decision-making statements.

---

### Homework #1-A: Palindromes
A palindrome is a number or a text phrase that reads the same backward as forward. For example, each of the following five-digit integers is a palindrome:
* 12321
* 55555
* 45554
* 11611

Write a program that reads in a five-digit integer and determines whether it’s a palindrome. The sample output is provided below. *Hint: Use the division and modulus operators to separate the number into its individual digits.*

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

#### Getting Started
1. **[Download](https://github.com/xaviermerino/ECE1552/blob/master/Homework1/hwk1a-student.zip?raw=true)** the starter file set. It will contain the following files:
    * `main.cpp`
    * `catch.hpp`
2. Use your favorite IDE or editor to modify your files. Include the given files in a project or compile them using your compiler of choice.
3. If you try running the program it will tell you that it has **failed all the tests**.
4. Your goal is to make the program **pass all the tests** by completing the assignment. Your code should be placed in between the `startRecording()` and `stopRecording()` calls.

We perform **unit testing** using the **Catch** framework. Catch is a **header-only** framework which means you just need to drop the header file containing the framework into your project. This is the reason behind the `catch.hpp` file.

Catch is at the heart of our **automated software grader**. For this reason, you are given a template where you can fill in your code. You will be able to see what your errors are and what the grader expected versus what your code generated. This will help you correct your code and submit it once it is ready. Ideally, every homework submission should be correct and pass all tests. This will give you a rough estimate of your grade every time you run your program. **Programs that pass all tests will receive full marks.**

An excerpt of the `main.cpp` file is presented below. You must not modify any other statements in the provided file for the grader to work as expected. You must only place your code in between the `startRecording()` and `stopRecording()` calls.

Additionally, the grader will provide **automatic input** to your `cin` calls. This is, your program will be tested against the sample input and it should generate the sample output provided above.

```c++
int main(int argc, const char * argv[]) {
    Catch::Session session;
    int returnCode = session.applyCommandLine( argc, argv );
    if( returnCode != 0 )
        return returnCode;

    istringstream userInput("12321\n12345\n123\n-1");
    injectInput(userInput);

    startRecording();

    /*
     *
     * Palindrome #1 problem goes here.
     *
     * All of your code should be between startRecording() and stopRecording();
     * Do not modify anything else or your program will not be graded correctly.
     * In order to get full credit for this assignment pass all the test cases.
     * The framework will tell you if the test failed and why it failed.
     *
     * Spacing and new lines are important!
     *
     */


    stopRecording();

    return session.run();
}
```

When compiling the program for the first time you should get the following message:

```
===============================================================================
test cases: 1 | 1 failed
assertions: 1 | 1 failed
```

Once you have completed the assignment your goal is to pass all the tests and obtain this output:

```
All tests passed (1 assertion in 1 test case)
```

This is provided for you to get feedback on your code. You can attempt to fix it and prepare it for submission once it passes all the tests. Once submitted, a set of similar tests will be run on your solution.

#### Submission
You are expected to submit your a zip file in Canvas by the specified deadline. The zip file name must match your Tracks ID. For instance, if your Tracks ID is *aLastname2016* then your zip file should be called **aLastname2016.zip**. The zip file should only contain the `main.cpp` file. Submit under Homework #1-A.

---

### Homework #1-B: More Palindromes
Repeat the previous problem, but instead of reading a five-digit integer, now you have to retrieve an input string of any size from the user. If you encounter white spaces, you need to ignore them, for example, the following are palindromes: “bob”, “a car a man a maraca”, “a nut for a jar of tuna”, etc. *Hint: Use `getline` for inputs that have spaces!*

```
Enter a string (or -1 to quit): bob
The word "bob" is a palindrome!

Enter a string (or -1 to quit): car
The word "car" is not a palindrome.

Enter a string (or -1 to quit): a car a man a maraca
The statement "acaramanamaraca" is a palindrome!

Enter a string (or -1 to quit): -1
Good bye!
```

#### Getting Started
1. **[Download](https://github.com/xaviermerino/ECE1552/blob/master/Homework1/hwk1b-student.zip?raw=true)** the starter file set. It will contain the following files:
    * `main.cpp`
    * `catch.hpp`
2. Use your favorite IDE or editor to modify your files. Include the given files in a project or compile them using your compiler of choice.
3. If you try running the program it will tell you that it has **failed all the tests**.
4. Your goal is to make the program **pass all the tests** by completing the assignment. Your code should be placed in between the `startRecording()` and `stopRecording()` calls.

When compiling the program for the first time you should get the following message:

```
===============================================================================
test cases: 1 | 1 failed
assertions: 1 | 1 failed
```

Once you have completed the assignment your goal is to pass all the tests and obtain this output:

```
All tests passed (1 assertion in 1 test case)
```

This is provided for you to get feedback on your code. You can attempt to fix it and prepare it for submission once it passes all the tests. Once submitted, a set of similar tests will be run on your solution.

#### Submission
You are expected to submit your a zip file in Canvas by the specified deadline. The zip file name must match your Tracks ID. For instance, if your Tracks ID is *aLastname2016* then your zip file should be called **aLastname2016.zip**. The zip file should only contain the `main.cpp` file. Submit under Homework #1-B.

---

### Homework #1-C: Pattern of Asterisks
Write a program that displays the following pattern.

```
*-*-*-*-*-*-*-*
 *-*-*-*-*-*-*-*
*-*-*-*-*-*-*-*
 *-*-*-*-*-*-*-*
*-*-*-*-*-*-*-*
 *-*-*-*-*-*-*-*
*-*-*-*-*-*-*-*
```

Your program must use only four output statements, one of each of the following forms:

```c++
cout << "* ";`
cout << ' ';
cout << "-";
cout << endl;

```

#### Getting Started
1. **[Download](https://github.com/xaviermerino/ECE1552/blob/master/Homework1/hwk1c-student.zip?raw=true)** the starter file set. It will contain the following files:
    * `main.cpp`
    * `catch.hpp`
2. Use your favorite IDE or editor to modify your files. Include the given files in a project or compile them using your compiler of choice.
3. If you try running the program it will tell you that it has **failed all the tests**.
4. Your goal is to make the program **pass all the tests** by completing the assignment. Your code should be placed in between the `startRecording()` and `stopRecording()` calls.

When compiling the program for the first time you should get the following message:

```
===============================================================================
test cases: 1 | 1 failed
assertions: 1 | 1 failed
```

Once you have completed the assignment your goal is to pass all the tests and obtain this output:

```
All tests passed (1 assertion in 1 test case)
```

This is provided for you to get feedback on your code. You can attempt to fix it and prepare it for submission once it passes all the tests. Once submitted, a set of similar tests will be run on your solution.

#### Submission
You are expected to submit your a zip file in Canvas by the specified deadline. The zip file name must match your Tracks ID. For instance, if your Tracks ID is *aLastname2016* then your zip file should be called **aLastname2016.zip**. The zip file should only contain the `main.cpp` file. Submit under Homework #1-C.
