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


 else if (AUX_BUTTON == 0)
 
	while(AUX_BUTTON == 0);
	
	color = ~color;

 
 
 When I tested this code, it worked in the sense that it moved the block around the screen, and changed the block from beign filled in, to being clear based on the pressing of the auxiliary button. The one thing that I missed, that Capt Trimble pointed out when I first demoed to her, was that it did not the screen did not fill in as the block was drawn, like an etch-a-sketch. This was an easy fix, all I had to do was comment out the cleardisplay() command within the while loop. Once I fixed that, I was able to complete the required functionality. I demonstrated the required functionality for Capt Trimble on Thursday, 23 OCT 2014. 
 
# B Functionality
	B functionality wanted us to create a bouncing block on our LCD screens. The block would move around the screen with no more than 8 pixels per jump, and would bounce off of the walls when they collided. It also wanted a delay between the blocks movements so it was easily visible. 
	
	I decided to simply copy all of the lab4.c code into a new source file and make changes there, in order to save the correct code for the required functionality. I neede to add some definition statements first. I defined the screen width and height along with True and False being equated with 1 and 0. I also initalized some char variables to represent the collision checks for the walls and the block.
	
	Next, I used a while loop to run the constant checks for a collision with any of the four walls, and if there was a collision, then drawing the block in the new position based on its velocity. At the bottom of my code, is where I determine if the block has collided with a wall of the screen and what to return to produce the correct results in the while loop above (aka where to draw the new block and, it's new velocity). 
	
	This functionality was similar to an assignment we had done, so the only problem I ran into, was slowing the block down enough for its collisions and movements to be visible. In order to do this,  I had to add a delay_cycles () command to the beginning of the while loop. I played around with the amount to delay it by, and finally decided that 2000000 cycles produced a good result. 
	
	I demonstrated B functionality to Capt Trimble on Thursday 23 OCT 14. 
