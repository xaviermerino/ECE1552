## Lab: Functions and Analog Output

### Overview
In this lab you will become familiar with analog outputs while learning code reusability through C++ functions. At the end of this session you will have constructed a simple circuit that uses the Arduino platform to fade an LED in and out once a button is pressed.

**In the process you will:**
  * Construct the circuit that controls the LED using hardware and software.
  * Review how to **interface** with push buttons.
  * Review how to **debounce** a push button.

### Introduction to Functions
A **function** is a named code block that performs an specific task. A function can be called from some point of the program. Every C/C++ program has at least one function, the `main()` function. A program always starts by automatically calling the `main()` function.

```c++
type name ( parameter1 , parameter2, ... ){
  // code
}
```

* The **type** is the type of the value that is returned by the function. A `void` function does not return a value.
* The **name** is the identifier of the function.
* The **parameters** are made up of a type and an identifier. Each parameter is separated by a comma.  

For instance, the function `add()` below adds two numbers and returns an `int` value.

```c++
#include <iostream>
using namespace std;

// Function prototype
int add(int, int);

int main(){
    cout << "The sum is: " << add(1,2) << endl;
}

// Function definition
int add(int a, int b){
  int sum = a + b;
  return sum;
}
```

The program above has an `add()` and `main()` function. The `add()` is called from within `main()`. When the `add()` is being called the first parameter, `int a`, gets the value `1` and the second parameter, `int b`, gets the value `2`. The `return` statement in the end returns control back to the point where the function was called. It also returns a value of type `int` since the `add()` function was given a return type. A function can be called several times.

To read more about functions visit [this site](http://www.cplusplus.com/doc/tutorial/functions/).

### Introduction to Analog Output
The Arduino has a 10-bit resolution **analog-to-digital converter (ADC)**. The output however is restricted to an 8-bit resolution. The output can only have 256 levels. This is why if we are relying on sensor input to produce an output we need to map the 10-bit resolution to an 8-bit scale.

The Arduino function that allows to write an analog value to a pin is called `analogWrite()`. We can use analog output, for instance, to vary the intensity of an LED or control a motor at different speeds.

The `analogWrite()` function takes two arguments. The first argument `pin` refers to the analog pin you want to write to. Pins that support this function are marked with a `~` sign. The second argument `value` refers to the duty cycle you want on the pin. **Duty cycle** refers to the value between 0 (always off) and 255 (always on).

For more information on PWM visit [this site](https://www.arduino.cc/en/Tutorial/PWM).

### Lab Task
Refer to the push button lab to connect a push button to the Arduino. Connect an LED to an analog output pin (marked with `~`). Your task is to take input from the push button. Once the push button is pressed (make sure to debounce your input) the LED must start fading in and out repeatedly until the push button is pressed again. 

Once you are done with this task show it to your TA for credit. 
