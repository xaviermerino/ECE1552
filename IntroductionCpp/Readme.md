## Lab: Introduction to C++

### Overview
In this lab you will become familiar with C++. This is intended for those who have little to no programming background. Any programming experience will make your life easier for sure.

**In the process you will:**
  * Understand the basics of the C++ language.
  * Understand the compilation process.
  * Write the traditional "Hello World".
  * Obtain input from the command line.
  * Discuss some basic data types.

### C++ and the Compilation Process
A program is just a list of instructions that a processor can execute. A processor takes each instruction from the list and executes it. Processors execute instructions like "store 1 in memory location 0x1234". You can see below a list of instructions that go through a processor to be executed.

<br>
![processor](https://github.com/xaviermerino/ECE4551-Computer-Architecture/blob/master/Extra-Readings/Pipelining-1/pipe1.png?raw=true)

<br>
The instructions listed above are not written in C++. This is because the processor doesn't understand C++. In order for the processor to understand your C++ code we need to compile it.

A program needs to go from a text file to instructions that processors can use. The image below illustrates the C++ compilation process.

<br>
![compileProcess](https://github.com/xaviermerino/ECE1552/blob/master/IntroductionCpp/compile2.png?raw=true)

<br>
The **preprocessor** applies some modifications to the original source code and then feeds it to the compiler. The **compiler** is just a program that given source code will output an object file. An object file is an intermediate step in the generation of an executable. A collection of object files (and external libraries) are put together by the **linker** to produce an executable. Your OS will load your executable via its **loader** and your program will then reside in memory.

### "Hello World"
Let's start with the classical "Hello World" program. We will explain each line as we go through this lab. The source code is provided below. Try it out online [here.](cpp.sh/5dpu)

```c++
#include <iostream>

int main(){
  std::cout << "Hello World!\n";
  return 0;
}
```

The code above contains **keywords** such as `int`. You might have seen other keywords such as `double` and `while`. It also contains **identifiers**. Identifiers include variable names, function names (such as `main` in the snippet above), among others. You can also see some **literal** values such as `"Hello World"`. These are constants that are specified in the code. You can also notice the **punctuation** used in the snippet. We use `{ }` braces to delimit functions and code blocks. We also use `;` at the end of some statements. In case you were wondering, the `<<` is an **operator**. Other operators such as `+`, `-`, `%`, `&&`, and `||` are probably familiar to you.

We are now going to go over each line in the snippet above. The first line starts with a `#` symbol. These lines are **preprocessor directives**. The `#include` tells the preprocessor to get the contents of the `iostream` file. Including `iostream` allows us to use the console for input and output. We then have `int main() { ... }`. This is the entry point to our program. All C/C++ programs need a `main` function that signals where the program begins. The curly braces encompass the instructions that are part of this function. In other words, what goes inside the braces gets executed when the program starts running.

We now face `std::cout << "Hello World!\n"`. The sequence of characters in between the quotation marks is called a **string**. We print to the console using `cout << "Hello World!\n"`. Here we are using the `<<` operator. For now, think of it as if `"Hello World!\n"` is flowing into the console's output. The `\n` is an escape sequence that means new line. We haven't mentioned `std::` yet. The `::` is called the **scope resolution operator**. In the snippet above it is basically telling the compiler to look for **cout** in the **std** namespace. A **namespace** is a way of organizing code into groups. The `cout`, `cin`, among other symbols are within that namespace. You need to prepend the `std::` before any use of `cout` to let the compiler know where to find it.

Let's try a different version of out "Hello World" program. Try it out online [here.](cpp.sh/9voxm)

```c++
#include <iostream>

// With the following line there is no need to prepend std:: before every cout.
using namespace std;

int main(){
  cout << "Hello World!\n";
  return 0;
}
```

The only difference is that we now have this line `using namespace std;`. The program runs the same way but this time we don't need to prepend `std::` before any `cout` or `cin`. This tells the program to look in the `std` namespace for any identifier that is not defined in our code.

We finish the `main` function with a `return 0`. When a program finishes running successfully it returns a zero to tell the operating system that everything went alright. Returning other values than zero means that some error occurred. Don't worry about this yet, it will be covered when we reach functions. For now just remember that the last line in your `main` function should be `return 0`.

### Language Basics
If you think of a sentence as a building block in the English language, then you can probably relate to C++'s statements. **Statements** are the fundamentals of code blocks and along with **expressions** they allow you to create complex programs. Expressions differ from statements because they evaluate to something. For instance `2+2` is an expression because it evaluates to 4 but `using namespace std;` is not (it is an statement!).

