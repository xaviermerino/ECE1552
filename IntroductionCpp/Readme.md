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

A program needs to go from a text file to binary instructions that processors can use. The image below illustrates the C++ compilation process.

<br>
![compileProcess](https://github.com/xaviermerino/ECE1552/blob/master/IntroductionCpp/compile2.png?raw=true)

<br>
The preprocessor applies some modifications to the original source code and then feeds it to the compiler. The compiler is just a program that given source code will output an object file. An object file is an intermediate step in the generation of an executable. A collection of object files (and external libraries) are put together by the linker to produce an executable. Your OS will load your executable via its loader and your program will then reside in memory. 

### Hello World
Let's start with the classical "Hello World" program. We will explain each line as we go through this lab. The source code is provided below. Try it out online [here.](cpp.sh/5dpu)

```c++
#include <iostream>

int main(){
  std::cout << "Hello World!\n";
  return 0;
}
```

The code above contains **keywords** such as `int`. You might have seen other keywords such as `double` and `while`. It also contains **identifiers**. Identifiers include variable names, function names (such as `main` in the snippet above), among others. You can also see some **literal** values such as `"Hello World"`. These are constants that are specified in the code. You can also notice the **punctuation** used in the snippet. We use `{ }` braces to delimit functions. We also use `;` at the end of some statements. In case you were wondering, the `<<` is an **operator**. Other operators such as `+`, `-`, `%`, `&&`, and `||` are probably familiar to you.






