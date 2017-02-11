## Lab: Control Structures

### Overview
In this lab you will become familiar with more complex control flow and structures. You will review your knowledge of conditionals and operators.

**In the process you will:**
  * Review the `if-else` statement.
  * Understand the `switch` statement.
  * Understand how a `for` loop works.
  * Understand how a `while` loop works.
  * Understand how a `do-while` loop works.

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

A `switch` statement is another way of using conditional to control the program flow. It's syntax differs greatly from the `if` statement's. We are going to rewrite the program above using a `switch` statement. Try it out [here](http://cpp.sh/5stgk).

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

The `switch` statement evaluates the expression given to it. In this case the expression given to it was the integer variable `item`. If `item` matches any of the cases within the `switch` statement then it executes that section. Each `case` needs a `break` statement at the end.


If you forget to put a `break` statement in the end then it will run through until it finds a `break`.
