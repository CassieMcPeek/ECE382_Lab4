/* Author: C1C Cassie McPeek
 * ECE 382  -  23 OCT 2014
 * MSP4302553G microcontroller
 * Purpose: This code utilizes the nokia.asm drawBlock file to draw a block that moves around the LCD screen and is filled in as it is moved.
 * There is also a check for the auxiliary button (SW3) to toggle the color of the square being moved between white and black.
 */


#include <msp430g2553.h>

extern void init();
extern void initNokia();
extern void clearDisplay();
extern void drawBlock(unsigned char row, unsigned char col, unsigned char color);

// definiton statements for all buttons
#define		TRUE			1
#define		FALSE			0
#define		UP_BUTTON		(P2IN & BIT5)
#define		DOWN_BUTTON		(P2IN & BIT4)
#define		AUX_BUTTON		(P2IN & BIT3)
#define		LEFT_BUTTON		(P2IN & BIT2)
#define		RIGHT_BUTTON	(P2IN & BIT1)


void main() {

	//initialize the variables for the square
	unsigned char	x, y, button_press, color;

	// === Initialize system ================================================
	IFG1=0; /* clear interrupt flag1 */
	WDTCTL=WDTPW+WDTHOLD; /* stop WD */
	button_press = FALSE;  //initialization of variables
	color = 0xFF;


	init();
	initNokia();
	clearDisplay();
	x=4;		y=4;
	drawBlock(y,x, color);

	while(1) {					// while loop to check for any button presses and to move square based on presses

			if (UP_BUTTON == 0) {
				while(UP_BUTTON == 0);
				if (y>=1) y=y-1;
				button_press = TRUE;
			} else if (DOWN_BUTTON == 0) {
				while(DOWN_BUTTON == 0);
				if (y<=6) y=y+1;
				button_press = TRUE;
			} else if (LEFT_BUTTON == 0) {
				while(LEFT_BUTTON == 0);
				if (x>=1) x=x-1;
				button_press = TRUE;
			} else if (RIGHT_BUTTON == 0) {
				while(RIGHT_BUTTON == 0);
				if (x<=10) x=x+1;
				button_press = TRUE;
			}
			  else if (AUX_BUTTON == 0){		// aux button press check to change color of square
				  while(AUX_BUTTON == 0);
				  color = ~color;
			  }

			if (button_press) {
				button_press = FALSE;
				//clearDisplay();			// Do not want to clear display, want to fill in as we move the square
				drawBlock(y,x, color);
			}
		}
}
