## Homework #3: Towers of Hanoi

### Overview
In this homework you will make use of **arrays** and control flow structures to solve the classic game, **Towers of Hanoi**. This is a mathematical game that consists of three stacks and a number of disks. The game starts with the disks placed in the leftmost stack. The disks are placed in ascending order, this is, the smallest disk at the top. The goal of this game is to move the entire leftmost stack to the rightmost stack.

</br>

![tower](https://github.com/xaviermerino/ECE1552/blob/master/Homework3/towers.png?raw=true)

</br>

**You must adhere to the following game rules:**
* Only one disk can be moved at a time.
* Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack. Only the uppermost disks can be moved.
* No disk may be placed on top of a smaller disk.

---

### Binary Representation
This problem can be solved in a number of ways. We are going to solve it through a simple binary representation. These are the rules for the model:
* There is **one bit** for each disk.
* The **most significant bit** represents the largest disk.
* The **least significant bit** represents the smallest disk.
* Start reading the bits from the right. The first bit to have a value of 1 is the **source disk** (or the disk to be moved).
* The second bit to have a value of 1 is the **destination disk**.
* If the number of zeroes in between the first and second bit is **even** (or zero) then move the source disk on top of the destination disk.
* If the number of zeroes in between the first and second bit is **odd** then move the source disk on top of the stack not containing the destination disk.
* If there is only one bit with the value of 1 move the disk to **any stack** you see fit.

In the end, all the disks from the leftmost stack must be placed in the rightmost stack. Let's assume we have only three disks (D3, D2, D1), then we would have something like this:

</br>

![tower](https://github.com/xaviermerino/ECE1552/blob/master/Homework3/exampleStart.png?raw=true)

</br>

| Step # | D3 | D2 | D1 | Meaning                    |
|--------|----|----|----|----------------------------|
| 0      | 0  | 0  | 0  | Starting point             |
| 1      | 0  | 0  | 1  | Move D1 to any empty stack |
| 2      | 0  | 1  | 0  | Move D2 to any empty stack |
| 3      | 0  | 1  | 1  | Move D1 on top of D2       |
| 4      | 1  | 0  | 0  | Move D3 to any empty stack |
| 5      | 1  | 0  | 1  | Move D1 not onto D3        |
| 6      | 1  | 1  | 0  | Move D2 on top of D3       |
| 7      | 1  | 1  | 1  | Move D1 on top of D2       |

</br> 
Using the table above we solve the problem as shown below. Read from left to right, top to bottom. 

</br>

![tower](https://github.com/xaviermerino/ECE1552/blob/master/Homework3/solution.png?raw=true)

</br>

### Functional Requirements
* Ask the user to input the number of disks he wishes to play with. The **number of disks** must be between 3 and 10. 

* **Populate** the initial array with the number of disks specified. Each disk is an array element. A **disk is represented by a number of ones**. For instance:
  * D1 in the previous example is represented by the integer `1`. 
  * D2 would be represented by `11`. 
  * D3 would be represented by `111`. 
  * Since the stacks can only hold up to 10 elements, the biggest disk, D10, would be `1111111111`.
  
* Each stack is represented by an **array**. There are three arrays in the program representing the leftmost stack, the middle stack, and the rightmost stack. Each array can hold 10 elements. Each element represents a disk. 
* As you move the disks, you must **move** the corresponding element from one array to another. 

* In the end, the array representing the rightmost stack should have all of the elements in the right order. The arrays representing the leftmost and middle stacks should be empty. 


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
1. **[Download](https://github.com/xaviermerino/ECE1552/blob/master/Homework1/hwk1b-Student.zip?raw=true)** the starter file set. It will contain the following files:
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
cout << "*";`
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
