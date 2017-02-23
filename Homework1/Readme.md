## Homework #1: Control Structures

### Overview
In this homework, you will apply the concepts of control structures – sequence, selection and repetition. You will practice the use of `if` statements to write programs that change its flow according to simple conditions. You will also make use of `for` and `while` loops to repeat code blocks while a condition holds. You will interact with the user via the console with the `cout` and `cin` statements.

**In the process you will**:
* Develop problem solving skills with C++
* Become comfortable with control Structures
* Use C++ fundamental data types
* Write simple decision-making statements.

### Problem #1: Palindromes
A palindrome is a number or a text phrase that reads the same backward as forward. For example, each of the following five-digit integers is a palindrome:
* 12321
* 55555
* 45554
* 11611.

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

The automated software grader requires us to follow some conventions to process your code. For this reason, you are given a template where you can fill in your code. You will be able to see what your errors are and what the grader expected versus what your code generated. This will help you correct your code and submit it once it is ready. Ideally, every homework submission should be correct and pass all tests. This will give you a rough estimate of your grade every time you run your program. Programs that pass all tests will receive the full marks.

Download the following template to start your code. Your code must be placed within the `startRecording()` and `stopRecording()` calls (see the provided main function below). You must not modify any other statements in the provided file for the grader to work as expected.

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


### Problem #2: More Palindromes
Repeat the previous problem, but instead of reading a five-digit integer, now you have to retrieve an input string of any size from the user. If you encounter white spaces, you need to ignore them, for example, the following are palindromes: “bob”, “a car a man a maraca”, “a nut for a jar of tuna”, etc.

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
Write a program that displays the following checkerboard pattern.

```
*-*-*-*-*-*-*-*
 *-*-*-*-*-*-*-*
*-*-*-*-*-*-*-*
 *-*-*-*-*-*-*-*
*-*-*-*-*-*-*-*
 *-*-*-*-*-*-*-*
*-*-*-*-*-*-*-*
```

Your program must use only three output statements, one of each of the following forms:

```c++
cout << "* ";`
cout << ' ';
cout << "-";
cout << endl;

```
