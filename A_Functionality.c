/*
 * A_Functionality.c
 *
 *  Created on: Oct 22, 2014
 *      Author: C15Cassandra.McPeek
 */


#include <msp430g2553.h>

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void drawBlock(unsigned char row, unsigned char col, unsigned char color);


// definition statements for variables
#define SCREEN_WIDTH 12
#define SCREEN_HEIGHT 8

#define TRUE 1
#define FALSE 0
#define	UP_BUTTON		(P2IN & BIT5)
#define	DOWN_BUTTON		(P2IN & BIT4)


char topCollide (char y, signed char yvel);
char bottomCollide(char y, signed char yvel);
char leftCollide(char x, signed char xvel);
char rightCollide(char x, signed char xvel);
char paddleCollide(char x, char y, signed char xvel, char xpaddle, char ypaddle);

void main() {

	unsigned char	x, y, button_press, color;
	unsigned char 	xpaddle, ypaddle;

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	color = 0xFF;
	button_press = FALSE;				// initializes variables for both square and paddle
	signed char xvel = 1;
	signed char yvel = 1;
	xpaddle = 0;
	ypaddle = 3;



	init();
	initNokia();
	clearDisplay();
	x=4;		y=4;
	drawBlock(y,x, color);


	//unsigned short j;
	//unsigned short i;
	while (TRUE)
	{
		if (UP_BUTTON == 0) {					// checks to see if button is pusehd to move the paddle
			while(UP_BUTTON == 0);
			if (ypaddle>=1) ypaddle=ypaddle-1;
			//button_press = TRUE;
		}
		else if (DOWN_BUTTON == 0) {
			while(DOWN_BUTTON == 0);
			if (ypaddle<=5) ypaddle=ypaddle+1;
			//button_press = TRUE;
		}

		__delay_cycles(2000000);				// delays square movement and and continously moves square with it bouncing off the walls.
		if (topCollide(y, yvel))
			yvel *= -1;
		else if (bottomCollide(y, yvel))
			yvel *= -1;
		if (rightCollide(x, xvel))
			xvel *= -1;
		else if (paddleCollide(x,y,xvel,xpaddle,ypaddle))
			xvel *= -1;
		else if (leftCollide(x, xvel))						// if the square collides with the left wall, it will end the game and reset the squre to the center
		{
			x = 4;
			y = 4;
			xvel = 0;
			yvel = 0;
		}
		x += xvel;											//resets square position based on any collisions and changes to velocity
		y += yvel;
		clearDisplay();
		drawBlock(y,x,color);
		drawBlock(ypaddle,xpaddle,color);
		drawBlock(ypaddle+1,xpaddle,color);

	}


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


// determines if square has collided with paddle
char paddleCollide (char x, char y, signed char xvel, char xpaddle, char ypaddle)
{
	if (x == xpaddle+1 && xvel < 0)
	{
		if((y == ypaddle || y == ypaddle + 1))
			return TRUE;
	}

	return FALSE;
}


/*
 * determines if the pong has collided with right side of screen
 */
char rightCollide (char x, signed char xvel)
{
	return (x >= SCREEN_WIDTH-1 && xvel > 0) ? TRUE : FALSE;

}



