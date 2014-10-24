ECE382_Lab4
===========

C - "Etch-a-Sketch and Pong"

# Purpose
  The purpose of this lab was to utilize some of the assembly code subroutines from Lab 3, along with C to create an etch-a-sketch program. 
  
  
# Prelab
  A handwritten copy of the prelab was turned into Capt Trimble on Monday 20 OCT 14.
  
# Required Functionality

  The required functionality wanted us to modify the subfunction drawBlock from Lab 3 to take in 3 values (x coord, y coord and color) instead of just 2 (x coord, y coord). The directional buttons on the LCD booster pack will be used to control the paint brush. The paint brush will draw 8x8 blocks of pixels and the auxiliary button will be used to toggle between the colors. 
  
  The only change I had to make to the drawBlock subroutine was add another input for the color. I pushed R1`4 onto the stack in order to account for the third input. I did run into a slight issue because I popped the registers off the stack in the wrong order at first, but once I fixed that, I didn't have any more issues with the nokia.asm code. 
