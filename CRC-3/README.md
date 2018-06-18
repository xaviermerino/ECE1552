## Lab: CRC-3

### Overview
In this lab you will implement an error-detecting code used in computer networks to detect unintendend changes in the data. We are going to be implementing a simple version of CRC-32, the algorithm used in Ethernet and other standards. Our version, CRC-3 is a simplified variant.

**In the process you will:**
  * Make use of **control** and **repetition** structures.
  * Make use of **bitwise operators** to handle the underlying bits.
  * **Implement** CRC-3 as described below. 

### Introduction to CRCs
CRCs (Cyclic Redundancy Check) add a fixed number of bits c alled the `check` value to a message to detect errors in communications. An n-bit CRC is able to detect error smaller than n-bits. CRCs need a message and a polynomial. The message is the `dividend` and the polynomial is the `divisor`. The result of this division becomes the new message and the division continues until the dividend is zero. 

In essence, CRC calculates a n-bit `check` value for each block of data based on a polynomial. If this check value matches a previously calculated check value, then we say that the data is error-free (this might not be entirely true!). Otherwise, we assume that the data got altered in transit. 

CRCs provide reasonable integrity when faced with common types of errors in communication channels. They are unable to provide protection against carefully crafted data alterations that attackers might employ.

### CRC-3
Our CRC variant, CRC-3, adds three bits to the message given to store the calculated `check` value. The polynomial that we will be using for our variant is `x^3 + x + 1`. This leaves us with the following: `1x^3 + 0x^2 + 1x + 1`. That means our coefficients are `1`, `0`, `1`, and `1`. 

Let's start with a simple message (dividend): `11010011101100` 

![message](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/message.png?raw=true)

And the bit representation of our `x^3 + x + 1` polynomial (divisor). 

![divisor](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/divisor.png?raw=true)

We must pad this message with three zeroes in order to compute a 3-bit CRC. 

![append3bits](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/message%2Bcrc.png?raw=true)

We then place the divisor's leftmost one under the dividend's leftmost one and perform a bitwise XOR. The alignment is shown by the yellow highlight.

![first](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/crc-step-1.png?raw=true)

We keep on repeating the process.

![second](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/crc-step-2.png?raw=true)

![third](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/crc-step-3.png?raw=true)

![fourth](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/crc-step-4.png?raw=true)

Notice how the divisor's leftmost one is lined up with the dividend's leftmost one to perform the bitwise XOR.

![fifth](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/crc-step-5.png?raw=true)

We keep on repeating the process.

![sixth](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/crc-step-6.png?raw=true)

![seventh](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/crc-step-7.png?raw=true)

![eight](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/crc-step-8.png?raw=true)

The dividend is now zero. We must stop. The CRC-3 check value is stored in the added bits. In this case, our result is binary `100`.

![ninth](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/crc-step-9.png?raw=true)

For your convenience, the steps have been summarized [here.](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/crc-steps.png?raw=true)

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

<br>
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
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int calibrationPin = 13;
const int photoresistorPin = A0;

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

The variable `sensorValue` is used to store the reading that comes from the photoresitor. The variables `sensorMin` and `sensorMax` are meant to store the lowest and the greatest reading from the sensor during the calibration period. After the pins have been set for input or output respectively, we turn on the LED connected to `calibrationPin` to mark the beginning of the calibration process. The calibration process lasts five seconds as you can see from `millis() < 5000`. The `while` loop repeats the statements that it encloses until five seconds have elapsed. It is going to repeatedly obtain a value from the photoresistor and save it in `sensorValue`. If `sensorValue` is greater than `sensorMax`, then `sensorMax` is updated to store that greater value. If `sensorValue` is lower than `sensorMin` then `sensorMin` is updated to store that lower value. At the end of the calibration period `sensorMin` will have the lowest value read and `sensorMax` will have the greatest value. We mark the end of the calibration period by turning off the LED attached to `calibrationPin`.

Let's now explain why we need calibration. We mentioned before that the analog inputs vary from 0 to 1023 depending on the voltage sensed at the pin. It might just happen that your sensor is not able to vary from 0 to 5V or that the input that is being fed results in a lower range. This means we get a lot of unused range as shown by the picture below.

<img  src="https://github.com/xaviermerino/ECE1552/blob/master/AnalogLab/adcLevels.png?raw=true"/>

In the picture above we are only using making use of 300 - 900 in the ADC levels. Calibration makes sure our code is independent of those always fluctuating levels. It maps the lowest and greatest readings to a scale of our choosing.

<img  src="https://github.com/xaviermerino/ECE1552/blob/master/AnalogLab/Calibration.png?raw=true"/>

In this case we have chosen our scale to be from 0 to 255 (there is a reason why we chose this scale, this will be explained next lab). We have constrained all values to be between 0 and 255 and we have also set some simple rules to decide the color of our LED:

* **Red:** 0 < x < 85
* **Green:** 85 < x < 170
* **Blue:** 170 < x < 255

Let's focus on the `loop()` function that will make what we talked above possible.

```c++
void loop() {
  // INSTRUCTIONS:
  //
  // 1) Read the value from the photoresistor.
  // sensorValue = ... to be filled by you;

  // 2) Map the sensor value to our scale from 0 to 255. Simple math!
  // 3) Constrain the values to 0 to 255. If a value is less than 0 make it 0. If a value is greater than 255 make it 255.

  // sensorValue is now in between 0 and 255.

  if (sensorValue > 0 && sensorValue < 85){
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  } else if (sensorValue > 85 && sensorValue < 170){
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  } else {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  }

  delay(100);
}
```

Take a look at the `setup()` function to see how we read the photoresistor value and do the same in the `loop()` function to complete the instructions. You then need to map the values to our 0 - 255 scale and constrain the values to this range. The code that decides the color of the LED based on the new value is given to you.

Now that this is done you should upload your program to the Arduino. During the calibration period make sure to expose the sensor to light (maybe use your phone's flashlight) and also cover it from light. After calibration is done play with it by shining light or covering the photoresistor and see how the LED changes color.

#### Lab Task #2

Make the calibration indicator LED blink at a rate of 250ms during the calibration period. Remember to use `millis()` as `delay()` blocks the execution! Allow more colors to be displayed in the LED by combining the different RGB hues. Make sure you are able to display the following colors:

1. Red
2. Green
3. Blue
4. Yellow
5. Magenta
6. Cyan
7. White

In order to ease the accommodation of the extra colors make sure to modify your mapping scale. The scale should go from 0 to 700. Modify your `if` statements to reflect the changes. The following rules apply:

* **Red:** 0 < x < 100
* **Green:** 100 < x < 200
* **Blue:** 200 < x < 300
* **Yellow:** 300 < x < 400
* **Magenta:** 400 < x < 500
* **Cyan:** 500 < x < 600
* **White:** 600 < x < 700

Once you are done with this task show it to your TA for credit.
