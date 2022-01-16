**Physical/Virtual Hardware Needed:**

1. 8051 Board.
2. RTC DS1307.
3. 16*2 LCD display.
4. 4 Switches.

**Software/Compiler Dependencies:**

1. Kiel 4.0/5.0 to compile and generate the 8051 hex code.

**Step 1:**

Load the folder into the kiel IDE and compile the code. Refer https://www.keil.com/c51/ to download and setup up the environment.

**Step 2:**

Once the hex code is generated, load the 8051 board/simulator and make all the connections with respect to pin number assigned in the header file.

That's it, Now restart the board if it's physical one. The code will start executing.

**Direction of Use:**

1. **Switch-0 :** Long press switch 0 to enter edit mode.
2. **Switch-1 :** This is to change the cursor position.
3. **Switch-2 :** This is to change the numbers in each position.
4. **Switch-3 :** To save and go back.

