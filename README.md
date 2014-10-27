ECE382_Lab4
===========

C - "Etch-a-Sketch and Pong"

# Purpose
  The purpose of this lab was to utilize some of the assembly code subroutines from Lab 3, along with C to create an etch-a-sketch program. 
  
  
# Prelab
  A handwritten copy of the prelab was turned into Capt Trimble on Monday 20 OCT 14.
  
# Required Functionality

  We were given the nokia.asm file as well as lab4.c code to begin with. The required functionality wanted us to modify the subfunction drawBlock from Lab 3 to take in 3 values (x coord, y coord and color) instead of just 2 (x coord, y coord). The directional buttons on the LCD booster pack will be used to control the paint brush. The paint brush will draw 8x8 blocks of pixels and the auxiliary button will be used to toggle between the colors. 
  
  The only change I had to make to the drawBlock subroutine was add another input for the color. I pushed R14 onto the stack in order to account for the third input. That code is shown below: 
  
drawBlock:

	push	R5

	push	R12					; y input
	
	push	R13					; x input
	
	push 	R14					; color input

	
  
  I did run into a slight issue because I popped the registers off the stack in the wrong order at first, but once I fixed that, I didn't have any more issues with the nokia.asm code. Once I had the assembly code part working, I moved onto the lab4.c file and began fixing that. The first thing I did was define another unsigned char variable, color. I also initalized the variable color to 0xFF, so the block would start out filled. I had to make sure that everywhere the drawBlock subroutine was called, I added the third variable to it, color. The last thing I did, was add an else if statement to account for the Auxiliary button that would toggle the paint brush between clear and filled. This code is shown below:


 else if (AUX_BUTTON == 0){		// aux button press check to change color of square
	while(AUX_BUTTON == 0);
	color = ~color;

 
 
 When I tested this code, it worked in the sense that it moved the block around the screen, and changed the block from beign filled in, to being clear based on the pressing of the auxiliary button. The one thing that I missed, that Capt Trimble pointed out when I first demoed to her, was that it did not the screen did not fill in as the block was drawn, like an etch-a-sketch. This was an easy fix, all I had to do was comment out the cleardisplay() command within the while loop. Once I fixed that, I was able to complete the required functionality. I demonstrated the required functionality for Capt Trimble on Thursday, 23 OCT 2014. 
 
# B Functionality
