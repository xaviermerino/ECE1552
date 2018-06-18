## Lab: CRC-3

### Overview
In this lab you will implement an error-detecting code used in computer networks to detect unintendend changes in the data. We are going to be implementing a simple version of CRC-32, the algorithm used in Ethernet and other standards. Our version, CRC-3 is a simplified variant.

**In the process you will:**
  * Make use of **control** and **repetition** structures.
  * Make use of **bitwise operators** to handle the underlying bits.
  * **Implement** CRC-3 as described below. 

### Introduction to CRCs
CRCs (Cyclic Redundancy Check) add a fixed number of bits called the `check` value to a message to detect errors in communications. An n-bit CRC is able to detect error smaller than n-bits. CRCs need a message and a polynomial. The message is the `dividend` and the polynomial is the `divisor`. The result of this division becomes the new message and the division continues until the dividend is zero. 

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

The result becomes the new dividend and we keep on repeating the process.

![second](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/crc-step-2.png?raw=true)

![third](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/crc-step-3.png?raw=true)

![fourth](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/crc-step-4.png?raw=true)

Notice how the divisor's leftmost one is lined up with the dividend's leftmost one to perform the bitwise XOR.

![fifth](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/crc-step-5.png?raw=true)

We keep on repeating the process.

![sixth](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/crc-step-6.png?raw=true)

![seventh](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/crc-step-7.png?raw=true)

![eight](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/crc-step-8.png?raw=true)

The result is zero. We must stop. The CRC-3 check value is stored in the added bits. In this case, our check value is binary `100`.

![ninth](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/crc-step-9.png?raw=true)

For your convenience, the steps have been summarized [here.](https://github.com/xaviermerino/ECE1552/blob/master/CRC-3/crc-steps.png?raw=true)

#### Lab Task #1

You are a detective. You have received the latest intelligence data on the target. The messages might have changed unintentionally when traveling through the network. 
You must implement CRC-3 to discover if the data you've obtained is error-free. Your polynomial is `x^3 + x + 1`. Each message is at most 29 bits long. Good luck!

This is what you are given:

```c++
unsigned int polynomial = 11;
unsigned int data[3] = {2, 10, 3096};
unsigned int crc[3] = {6, 4, 0};
```

The variable `polynomial` is the decimal representation of `x^3 + x + 1`.
The array `data` contains information about latitude, longitude, and elevation of the target.
The array `crc` contains the original calculated CRC-3 for the data. 

Go through the `data` array and calculate the CRC-3 for each item in the array. 
Compare your calculation with the provided one in the `crc` array. Print `[OK]` or `[FAILED]` accordingly.
If the calculations do not match, print the calculated CRC and expected CRC.

Example output is shown below for reference.


```
Latitude: 2	[OK]

Longitude: 10	[FAILED]
	Calculated CRC: 3
	Expected CRC: 4

Elevation: 3096	[OK]
```

