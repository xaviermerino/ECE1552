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
* After illuminating all LEDs for that round, the system must wait for the appropriate **amount of button presses**. If at any point the player pushed a wrong button the game is over. If the player pushed all the buttons in correct order then it's a win.
* When the player wins (this is by pressing all the buttons correctly), the LEDs must **exhibit a chaser or sequencer behavior**. This should give the appearance of running lights. The game will only restart after pressing the reset button on the Arduino. If you are unsure what sequence to implement, you can check [this link](https://www.youtube.com/embed/kLGUHvCSHC4) for some ideas.
* Use the buzzer to **make a sound** when the player pressed an incorrect button. Turn off all the lights. The game will only restart after pressing the reset button on the Arduino.
*

### Getting Started
