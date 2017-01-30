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
<td><img  src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/c2/AdditiveColor.svg/1024px-AdditiveColor.svg.png" alt="" height="300" width="300"/></td>
<td><img src="https://cdn.sparkfun.com/assets/learn_tutorials/3/6/0/RGBPinOUt.png" alt="" height="300" width="300"/></td>
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

Let's first declare variables that will represent the pins mentioned above. A **variable** is a named entity that we can use in our program to store data. Variables can be of different data types such as integers or characters, etc. For now we will stick with integers or whole numbers (called `int` in your sketch). We will use the variables to store the pin numbers we are using to connect our RGB LED. We are doing this so that we can refer to the pins by a name rather than by its number. Variables are case sensitive!

```c++
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
```

The variables above are *global variables* because they were declared outside the `setup()` and `loop()` functions. This means they are accessible from all portions of the code. In the `setup()` portion of the sketch we must set these pins to **output** to allow them to drive the RGB LED. Notice how we are using the variables instead of the pin numbers.

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

Photoresistors, or light-dependent resistors, are components whose resistance is controlled by the incident light intensity. Their resistance decreases when light shines upon them. You might have seen them in photocells on the streets as they are responsible for ensuring that the light is only on during darkness.

In this lab we will be using the Arduino to read the input of the photoresistor. See the diagram below.

<img  src="https://github.com/xaviermerino/ECE1552/blob/master/AnalogLab/secondSketch.jpg?raw=true" height="400" width="500"/>

In other words:
* Connect the RGB LED as shown in the previous section.
* Connect one lead of the photoresistor to 5V.
* Connect the remaining lead of the photoresistor to pin A0 in the Arduino.
* Connect the same lead to ground via a small resistor.
* Connect another LED's anode to pin 13.
* Connect the other LED's cathode to ground via a small resistor.

Let's add to the variable declaration from the previous section.

```c++
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int calibrationPin = 13;
const int photoresistorPin = A0;

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(calibrationPin, OUTPUT);
  pinMode(photoresistorPin, INPUT);
}
```

We declared `calibrationPin` to refer to pin 13. This pin will turn on the LED attached to it while the photoresistor is being tuned. We will explain this shortly. We also created the variable `photoresistorPin` to refer to pin A0 (analog pin 0).

In the `setup()` function we set the pins associated with the RGB LED and the calibration pin as output. The `photoresistorPin` was set up as an input pin since we are going to be reading values from the sensor attached to it.

The Arduino has a 10-bit resolution **analog-to-digital converter (ADC)**. An ADC converts analog signals such as sound or light into a digital signal. In this case we are converting light intensity into a digital signal that can be interpreted by the Arduino. The resolution of an Analog-to-Digital Converter indicates the number of voltage levels it can produce. The Arduino's 10-bit ADC allows representing 5 volts in 1024 (2^10) levels. This means that 0V at an analog pin will be interpreted as 0 and 5V will be interpreted as 1023. Therefore, readings at any analog pin will range from 0 to 1023. If you want the full range of readings you will need a sensor that varies from 0 to 5V and a full range of inputs that would trigger those responses.

Let's continue adding to the `setup()` function. With the newest additions, the code is able to tune in our sensor. We know that an analog pin input can range from 0 to 5V which get mapped to integers 0 - 1023.

```c++
int sensorValue = 0;
int sensorMin = 1023;
int sensorMax = 0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(calibrationPin, OUTPUT);
  pinMode(photoresistorPin, INPUT);

  digitalWrite(calibrationPin, HIGH);

  while(millis() < 5000){
    sensorValue = analogRead(photoresistorPin);

    if (sensorValue > sensorMax){
      sensorMax = sensorValue;
    }

    if (sensorValue < sensorMin){
      sensorMin = sensorValue;
    }
  }

  digitalWrite(calibrationPin, LOW);
}
```
