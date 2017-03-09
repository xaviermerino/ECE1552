## Final Project: Simon

### Overview
For this final project your goal is to create an imitation of the famous memory game **Simon**. The game consists of four colored LEDs and four push buttons. A round in the game consists of the device lighting up the LEDs in a random order. The player must reproduce that order by pressing the buttons associated with the LEDs. As the game progresses, the number of buttons to be pressed increases.  

If you haven't played the game before, check [this site](http://www.freesimon.org). (Flash player required)

**In the process you will:**
  * Review how to **interface** with push buttons.
  * Review how to **debounce** a push button.
  * Discover how to **play sounds** using a piezo buzzer.
  * Make use of **arrays** to store game data.
  * Make use of **control** and **repetition** structures for gameplay.
  * Implement your own **LED chaser**.
  * Create and make use of **functions**.

In the end, your system should look like the one presented below.

</br>
<img src="https://github.com/xaviermerino/ECE1552/blob/master/FinalProject/simonSays_bb.png?raw=true" alt="Simon" height="80%" width="80%">


### Functional Requirements
* This imitation of Simon **does not run forever**. You are only required to generate ten rounds.
* During a round the system must **illuminate a number of LEDs**. For instance, in round one the system illuminates one LED. In round two, the system illuminates two LEDs. Make sure to leave a second in between the light up of your LEDs.
* After illuminating all LEDs for that round, the system must wait for the appropriate **amount of button presses**. For instance, round one should only accept one button press and round two should accept two button presses. If at any point the player pushed a wrong button the game is over. If the player pushed all the buttons in correct order then it's a win.
* When the player wins (this is by pressing all the buttons correctly), the LEDs must **exhibit a chaser or sequencer behavior**. This should give the appearance of running lights and should be repeated indefinitely. If you are unsure what sequence to implement, you can check [this link](https://www.youtube.com/embed/kLGUHvCSHC4) for some ideas.
* Use the buzzer to **make a sound** when the player pressed an incorrect button. Turn off all the lights and wait indefinitely.
* Whether it's a win or a lose the game will only be restarted by pressing the **reset button** on the Arduino.
* Make sure that on every game you get a **different set of rounds**.

### Getting Started
1. Download the starter file set. It will contain the following:
  * `SimonStarter.ino`
2. Use your favorite IDE or editor to modify your files. Make use of the provided variables to complete your program. Add more if you feel you need to store additional data.
3. Make sure to use functions to avoid repetition of source code.
4. Add comments!
5. Compile your program and play.

### Technical Requirements
* You are required to avoid *copy-paste* repetition of code at all costs. You must use functions, control, and repetition structures to achieve this.
* You are required to use arrays to store game data.
* You are required to use constants to avoid magic numbers. You should write code that can easily be extended to accommodate more LEDs.

### Submission
* Once you are done show your game to your TA. You might be asked to reduce the number of rounds to ease testing. If your game behaves properly you will receive credit.
* Zip your `.ino` file for submission. The .zip file must be named after your Tracks ID. This is for plagiarism detection purposes. 
