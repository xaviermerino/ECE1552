## Lab: Flow Control Structures

### Overview
In this lab you will become familiar with more complex control flow and structures. You will review your knowledge of conditionals and operators and learn how to use `switch` statements, `for` loops, and `while` loops.

**In the process you will:**
  * Review the `if-else` statement.
  * Understand the `switch` statement.
  * Understand how a `for` loop works.
  * Understand how a `while` loop works.

### Statements: *if* and *if-else*
We previously said that programs are executed in order. We might wish to change the program flow based on the result of other operations and we do this with control statements such as the `if` family of statements. In the previous lab we introduced the `if-else` statement with the following flowchart.

<br>

![flowchart](https://github.com/xaviermerino/ECE1552/blob/master/IntroductionCpp/flowchart2.png?raw=true)

<br>
The example above resulted in the code below. Try it out online [here](http://cpp.sh/4twob).

```c++
#include <iostream>
using namespace std;

int main(){
    int number;
    cin >> number;

    // Condition goes inside the if-statement.
    if (number > 5 && number < 10){
        // This executes if true.
        cout << "A";
    } else {
        // This executes if false.
        cout << "B";    
    }
}
```

We agreed that the structure of a simple `if` statement is:

```c++
if ( condition ) {
  // Code here is executed if condition evaluates to true
}
```

And that the structure of an `if-else` statement is:

```c++
if ( condition ) {
  // Code here is executed if condition evaluates to true
} else {
  // Code here is executed if condition evaluates to false
}
```

### Statements: *switch*, *case*, and *break*
Suppose that you own a store that sells apples, pears, and bananas. In your store you have a system that requests the user to input an item ID and in response it will output the item's description if it exists. Otherwise it will let the customer know that the item does not exist.

Each item is assigned an ID as follows:

| Item ID 	| Description 	|
|---------	|-------------	|
| 0       	| Apple       	|
| 1       	| Pear        	|
| 2       	| Banana      	|

<br>

The following flowchart depicts the operation of this system.

<br>

![flowchart](https://github.com/xaviermerino/ECE1552/blob/master/ControlStructures/switchFlowchart.png?raw=true)

<br>

Based on your knowledge of `if-else` statements you could have written the code already. You might have written something similar to the code presented below. Try it out [here](http://cpp.sh/844li). There are several ways of writing this, check out [this](http://cpp.sh/74vs) version.

```c++
#include <iostream>
using namespace std;

int main()
{
    int item;
    cout << "Enter an item ID: ";
    cin >> item;

    if (item == 0)
    {
        cout << "Item: Apple" << endl;   
    }
    else
    {
        if (item == 1)
        {
            cout << "Item: Pear" << endl;
        }
        else
        {
            if (item == 2)
            {
                cout << "Item: Banana" << endl;
            }
            else
            {
                cout << "Item doesn't exist" << endl;    
            }
        }
    }   
}

```

A `switch` statement is another way of using conditionals to control the program flow. It's syntax differs greatly from the `if` statement's. We are going to rewrite the program above using a `switch` statement. Try it out [here](http://cpp.sh/5stgk).

```c++
#include <iostream>
using namespace std;

int main()
{
    int item;
    cout << "Enter an item ID: ";
    cin >> item;

    switch(item)
    {
        case 0:
            cout << "Item: Apple" << endl;
            break;
        case 1:
            cout << "Item: Pear" << endl;
            break;
        case 2:
            cout << "Item: Banana" << endl;
            break;
        default:
            cout << "Item doesn't exist" << endl;
            break;
    }
}

```

The `switch` statement evaluates the expression given to it. In this case the expression given to it was the integer variable `item`. If `item` matches any of the cases within the `switch` statement then it executes that section. Each `case` needs a `break` statement at the end. We will explain why shortly. If the expression did not evaluate to any of the cases then the default case will be executed.

The general structure of a `switch` statement is presented below.

```c++
switch( expression )
{
    case constant:
        // Code here is executed if the expression evaluates to constant.
        statements;
        break;

    case constant1:
        // Code here is executed if the expression evaluates to constant1.
        statements;
        break;

    default:
        // Code here is executed if the expression does not match any case.
        statements;
        break;
}

```

Let's get back to the `break` statement. When using the `switch` statement you must end each `case` with a `break` otherwise it will run through the cases until it finds a `break`. Consider the same code we wrote for the store's items. In this version of the code we forgot to include a `break` statement at the end of `case 0`. Try it out [here](http://cpp.sh/7djx).

```c++
#include <iostream>
using namespace std;

int main()
{
    int item;
    cout << "Enter an item ID: ";
    cin >> item;

    switch(item)
    {
        case 0:
            cout << "Item: Apple" << endl;

        case 1:
            cout << "Item: Pear" << endl;
            break;
        case 2:
            cout << "Item: Banana" << endl;
            break;
        default:
            cout << "Item doesn't exist" << endl;
            break;
    }
}

```

When executing this code and using `0` as an input your output will be:

```
Enter an item ID: 0
Item: Apple
Item: Pear
```

Because a `break` was missing at the end of `case 0` the program ran through `case 1` and executed that segment until it found a `break`.

### Statements: *while* and *for*
Conditional statements allow you to execute statements based on conditions. Loop structures allow you to repeat the execution of instructions while certain condition remains true. In this section we will cover `while` and `for` loops.

#### The *while* loop
Let's first cover the `while` loop:

```c++
while( condition )
{
    statements;
}
```

The `while` loops repeats its code block for as long as the condition remains true. We will be building the program in the flowchart below.

<br>

![whileFlowchart](https://github.com/xaviermerino/ECE1552/blob/master/ControlStructures/whileFlowchart.png?raw=true)

<br>

In the example below, `number` is declared as an `int` variable and initialized to 1. The while loop prints the value of `number` and then increments the value by one. It repeats those instructions until `number` becomes six (or while `number` is less or equal to five). When the condition no longer holds, the program continues with its normal execution. At this point, `number` is six. Try it out [here](http://cpp.sh/4lghj).

```c++
#include <iostream>
using namespace std;

int main()
{
  int number = 1;

  while(number <= 5)
  {
      cout << "Number is: " << number << endl;
      number++;
  }

  // number is now 6 which is why the while loop stopped!
  cout << "Outside loop!" << endl;
  cout << "Number is: " << number << endl;
  return 0;
}
```

A variation of the `while` loop is the `do-while` loop. Read more about it [here](https://www.tutorialspoint.com/cplusplus/cpp_do_while_loop.htm).

#### The *for* loop
The `for` loop allows you to execute a code block for a specific number of times. It works by using a counter variable that keeps track of how many iterations have elapsed. The structure of a `for` loop is:

```c++
for (initialization; condition; increment)
{
    statements;
}
```  

* The **initialization** step initializes a counter variable. This is only executed once.
* The **condition** is evaluated. If the condition holds then the code block inside the loop gets executed otherwise the statements after the loop get executed.
* The **increment** statement gets executed after every iteration of the code block. It allows you to increment or decrement the counter variable.

In the snippet below, `i` is initialized to zero. The code inside the for loop will repeat while `i < 5`. At the end of each iteration, the counter variable will be updated by `i++`.

```c++
#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "i: " << i << endl;
    }
    return 0;
}

```

It results in the following output. Try it out [here](http://cpp.sh/4w2t).

```c++
i: 0
i: 1
i: 2
i: 3
i: 4
```

Now let's transform our previous `while` loop example into a `for` loop. The output is the same but the syntax is different. Try it out [here](http://cpp.sh/24pb).

```c++
#include <iostream>
using namespace std;

int main()
{
    int number;

    for (number = 1; number <= 5; number++){
        cout << "Number is: " << number << endl;    
    }

    // number is now 6 which is why the for loop stopped!
    cout << "Outside loop!" << endl;
    cout << "Number is: " << number << endl;
    return 0;
}

```

### Lab Task
We have three tasks to accomplish in this lab session.

* Write a program to print all even numbers between 1 and 100 using a while loop. See the example output below.

```c++
Number: 2
Number: 4
Number: 6
Number: 8
Number: 10
...
...
Number: 96
Number: 98
Number: 100
```

* Write a program to print all odd numbers from 100 to 1 using a for loop. See the example output below.

```c++
Number: 99
Number: 97
Number: 95
Number: 93
...
...
Number: 5
Number: 3
Number: 1
```

* Let the user input a number (in this range 2 - 100). Your program should print the multiplication table (from 1 to 9) of that number. See the example below.

```c++
Input a number from 2 to 100: 67
Multiplication table for number 67:
67 x 1 = 67
67 x 2 = 134
67 x 3 = 201
67 x 4 = 268
67 x 5 = 335
67 x 6 = 402
67 x 7 = 469
67 x 8 = 536
67 x 9 = 603
```
