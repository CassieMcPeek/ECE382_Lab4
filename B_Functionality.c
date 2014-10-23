/*
 * B_Functionality.c
 *
 *  Created on: Oct 22, 2014
 *      Author: C15Cassandra.McPeek
 *      Purpose: This code completes the B functionality, which requires the block to bounce off of the four sides of the LCD screen while moving randomly.
 *      The block must change it's velocity when it collides with one of the sides, in order to continue moving throughout the screen.
 */

#include <msp430g2553.h>

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void drawBlock(unsigned char row, unsigned char col, unsigned char color);

// definitions for variables
#define SCREEN_WIDTH 12
#define SCREEN_HEIGHT 8

#define TRUE 1
#define FALSE 0

// initalizes the variables for moving the block
char topCollide (char y, signed char yvel);
char bottomCollide(char y, signed char yvel);
char leftCollide(char x, signed char xvel);
char rightCollide(char x, signed char xvel);

void main() {

	// initializes variables to draw the block as char
	unsigned char	x, y, color;


	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	color = 0xFF;

	signed char xvel = -1;				// initalizes the x and y velocites as signed char's
	signed char yvel = -1;




	init();
	initNokia();
	clearDisplay();
	x=4;		y=4;
	drawBlock(y,x, color);


	//unsigned short j;
	//unsigned short i;
	while (TRUE)
	{
		__delay_cycles(2000000);		// delays the square moving so it is visible
		if (topCollide(y, yvel))		// checks to see if the square collided with any sides and changes it's velocity so it continues to move
			yvel *= -1;
		else if (bottomCollide(y, yvel))
			yvel *= -1;
		if (leftCollide(x, xvel))
			xvel *= -1;
		else if (rightCollide(x, xvel))
			xvel *= -1;
		x += xvel;						//resets the square's position based on the change in velocity
		y += yvel;
		clearDisplay();
		drawBlock(y,x,color);			// draws the block in the new position with the new velocity
	};


}

/*
 * This section determines if the pong has collided with the top of the area
 */

char topCollide (char y, signed char yvel)
{
	return (y <= 0 && yvel < 0) ? TRUE : FALSE;
}

/*
 * Determines if the pong has collided with the bottom of the screen
 */
char bottomCollide (char y, signed char yvel)
{
	return (y >= SCREEN_HEIGHT-1 && yvel > 0) ? TRUE : FALSE;

}

/*
 * Determines if pong has collided with left side of screen
 */
char leftCollide (char x, signed char xvel)
{
	return (x <= 0 && xvel < 0) ? TRUE : FALSE;

}


/*
 * determines if the pong has collided with right side of screen
 */
char rightCollide (char x, signed char xvel)
{
	return (x >= SCREEN_WIDTH-1 && xvel > 0) ? TRUE : FALSE;

}




