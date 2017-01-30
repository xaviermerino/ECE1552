## Lab: Analog Input and Calibration

### Overview
In this lab you will become familiar with analog inputs while rehearsing the skills obtained in the previous weeks. At the end of this session you will have constructed a simple circuit that uses the Arduino platform to obtain the ambient light intensity from a light-dependent resistor and display the desired color with the RGB LED.

**In the process you will:**
  * Construct the circuit that controls the **RGB** LED using hardware and software.
  * Review how to **interface** with push buttons.
  * Review how to **debounce** a push button.
  * Read data from **analog** sensors.
  * **Calibrate** the incoming data and constrain it to a certain range.

### Introduction to RGB LEDs
RGB stands for Red, Green, and Blue. RGB LEDs combine these three colors to produce different hues of light. Because the combination of RGB colors result in limited hues, you can only get the colors within the RGB gamut.

<table style="margin-left: auto; margin-right: auto;" border="0">
<tbody>
<tr>
<td><img width: "250" height: "250" src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/c2/AdditiveColor.svg/1024px-AdditiveColor.svg.png" alt="" /></td>
<td><img style="width: 250; height: 250px;" src="https://cdn.sparkfun.com/assets/learn_tutorials/3/6/0/RGBPinOUt.png" alt="" /></td>
</tr>
</tbody>
</table>

In this session we are using a common cathode RGB LED. This means that we have a lead for every color and a common pin connected to ground. We will be building a simple circuit that will cycle the LED through red, green, and blue. See the diagram below.

<img style="width: 400; height:300px;" src="https://github.com/xaviermerino/ECE1552/blob/master/AnalogLab/firstSketch.jpg?raw=true"/>

In other words:
* Connect the **red** anode to pin 9 in the Arduino. Don't forget the small resistor that connects it to ground.
* Connect the **green** anode to pin 10 in the Arduino. Don't forget the small resistor that connects it to ground.
* Connect the **blue** anode to pin 11 in the Arduino. Don't forget the small resistor that connects it to ground.
* Connect the **common cathode** to ground.

Let's first declare variables that will represent the pins mentioned above.

```c++
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
```

In the `setup()` portion of the sketch we must set these pins to **output** to allow them to drive the RGB LED.

```c++
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
```

You should already be familiar with `digitalWrite()` and how to use it to turn LEDs on and off.

The following code belongs in the `loop()` function and it cycles between red, green, and blue with a one second delay between each change.  

```c++
void loop() {
  // Displaying red with the RGB LED
  digitalWrite(redPin, HIGH);
  delay(1000);

  // Turning the RGB LED off
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);

  // Displaying green with the RGB LED
  digitalWrite(greenPin, HIGH);
  delay(1000);

  // Turning the RGB LED off
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);

  // Displaying blue with the RGB LED
  digitalWrite(bluePin, HIGH);
  delay(1000);

  // Turning the RGB LED off
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}
```

#### Lab Task #1

Once you have completed this portion expand the code to display the following colors:

1. Red
2. Green
3. Blue
4. Yellow
5. Magenta
6. Cyan
7. White

Instead of automatically cycling through the colors every second, plug in a push button that when pressed changes the color.



#### Getting Started

1. **[Download](https://github.com/xaviermerino/ECE2551-SoftHardDesign/blob/master/Lab-2/lab2.ino?raw=true)** the starter file. It will contain the following file:
  * `lab2.ino`

2. The provided file is a template file that you can use to fill in your code.
3. Fill in the function definitions for each of the classes' methods. You can implement your own, these are just there for reference.

#### Functional Requirements
You are required to build the circuit that makes this hardware token device possible.

**When turned on for the first time the device must:**
* Generate ten random numbers between `10000` and the limit given by `USHRT_MAX` defined in `<limits.h>`.
* These numbers must be saved to the **EEPROM** so they can be retrieved after a **power cycle**.

**After the numbers are loaded in the EEPROM the device must**:
* Keep a timer.
* The timer will help select an address to read from the EEPROM.
* A new address should be selected every ten seconds.
* The LCD should not display anything until the push button is pressed.
* Once the button is pressed the device will get an address based on the time.
* Once the button is pressed the LCD will display (the token will change accordingly):

```
Hardware Token
35469
```
* After three seconds the LCD must should go blank.
* The device follows this behavior until turned off.


#### Technical Requirements
This section will serve as a guideline of what is necessary for the program to behave correctly.
* The token you generate randomly should be of type `unsigned short` and hold values from `10000` to `USHRT_MAX`.
* The token is made up of **16 bits**.

<br>

![token](https://github.com/xaviermerino/ECE2551-SoftHardDesign/blob/master/Lab-2/token.png?raw=true)

<br>
* Each entry in the **EEPROM** can only hold 1 byte of data, therefore, you must break up the token into its first eight bits and its second eight bits. We will call the first eight bits the **high bits** and those will be bits 8-15. The **low bits** will be bits 0-7. You will save the high and low bits in the **EEPROM** and when a read is requested you must combine those two to obtain the original token.

![broken](https://github.com/xaviermerino/ECE2551-SoftHardDesign/blob/master/Lab-2/tokenbreak.png?raw=true)

<br>
* Internally, your device should keep track of time. Every ten seconds it should read a different entry from the **EEPROM**. This is, every ten seconds the token will be different. Since you are only implementing ten tokens. You must wrap around to keep on showing tokens on the screen. This is, after you have read all the tokens, start from the first token saved in the **EEPROM** again.

<br>

![timer](https://github.com/xaviermerino/ECE2551-SoftHardDesign/blob/master/Lab-2/pattern.png?raw=true)

<br>
* Once you press the button, the device must show the current token on the screen.

```
Hardware Token
33333
```

* After showing the token, the screen must go blank in three seconds.
* You are free to use any available pin to connect the push button. For more information check the Arduino [Example on Buttons](https://www.arduino.cc/en/Tutorial/Button).

Let's start explaining what each of the functions defined in given classes file must do.

**The following functions belong to the `Eeprom` class:**
* **Eeprom()**: Default constructor for the `Eeprom` class.
* **byte read(unsigned int uiAddress)**: This function returns a byte of data read from the **EEPROM** at the specified address `uiAddress`. It's implementation is similar to the code snippet below.

```c++
byte read(unsigned int uiAddress) {
  // Wait for completion of previous write
  while (EECR & (1 << EEPE));

  // Fill in with the appropriate code

  return 1; // Change to return byte
}

```

* **void write(unsigned int uiAddress, byte data)**: This function writes a byte of data read to the **EEPROM** at the specified address `uiAddress`. It's implementation is similar to the code snippet below.

```c++
void write(unsigned int uiAddress, byte data) {
  // Wait for completion of previous write
  while (EECR & (1 << EEPE));

  // Fill in with the appropriate code
}

```

**The following functions belong to the `Button` class:**
* **Button(unsigned short pin)**: Constructor for the `Button` class.
* **bool hasBeenPushed()**: This function returns `true` if the button has been pushed. It performs debouncing to avoid bogus readings.
