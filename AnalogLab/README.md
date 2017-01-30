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
<td><img  src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/c2/AdditiveColor.svg/1024px-AdditiveColor.svg.png" alt="" height="350" width="350"/></td>
<td><img src="https://cdn.sparkfun.com/assets/learn_tutorials/3/6/0/RGBPinOUt.png" alt="" height="350" width="350"/></td>
</tr>
</tbody>
</table>

In this session we are using a common cathode RGB LED. This means that we have a lead for every color and a common pin connected to ground. We will be building a simple circuit that will cycle the LED through red, green, and blue. See the diagram below.

<img  src="https://github.com/xaviermerino/ECE1552/blob/master/AnalogLab/firstSketch.jpg?raw=true" height="400" width="500"/>

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

Expand the code above to display the following colors:

1. Red
2. Green
3. Blue
4. Yellow
5. Magenta
6. Cyan
7. White

Instead of automatically cycling through the colors every second, plug in a push button that when pressed changes the color. Don't forget to debounce the button signal. Once you are done with this task show it to your TA for credit. 

### Introduction to Photoresistors



