//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include <Windows.h>
#include "util.h"/*
#include "Settings.h"
#include "UserId.h"
#include "menu.h"*/
#include "Jewel.h"
#include <cstdlib>
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
Jewel jew[8][8];
int pgno = 0;
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */

void Displayingjew() {
	string name;

	int x, y;
	x = 140; y = 0;
	for (int i = 0; i < 8; i++) {
		y = 80;
		for (int j = 0; j < 8; j++) {
			//fill[i][j] = GetRandInRange(0, 6);
			name = jew[i][j].getGem();
			x = jew[i][j].getx();
			y = jew[i][j].gety();
			
			if (name =="Pearl") {
				DrawCircle(x+5, y, 25, colors[SILVER]);
				DrawCircle(x+8, y+2, 20, colors[DARK_GRAY]);
				DrawCircle(x+11, y+4, 15, colors[BLACKO]);


			}
			else if (name == "Emerald") {
				//DrawCircle(x+5, y, 25, colors[MAGENTA]);
				//DrawCircle(x+5, y, 15, colors[DARK_TURQUOISE]);
				DrawTriangle(x -20, y , x+  10, y , x + 10, y - 30, colors[INDIGO]);
				DrawTriangle(x -20, y , x +10, y , x + 10, y +30, colors[HOT_PINK]);
				DrawTriangle(x + 10, y , x +10, y -30, x +40, y , colors[HOT_PINK]);
				DrawTriangle(x + 10, y , x + 10, y + 30, x + 40, y, colors[INDIGO]);
			}
			else if (name == "Ruby") {
				DrawTriangle(x - 20, y - 20, x + 10, y + 40, x + 40, y - 20, colors[TOMATO]);
				DrawTriangle(x - 20, y - 20, x + 10, y - 20, x + 10, y + 40, colors[MAROON]);
				DrawTriangle(x - 20, y - 20, x -10, y -30, x -10, y - 20, colors[MAROON]);
				DrawTriangle(x + 40, y - 20, x + 30, y - 30, x + 30, y - 20, colors[FIREBRICK]);
				DrawRectangle(x - 10, y - 30, 41, 11, colors[DARK_RED]);

			}
			else if (name == "Gold") {
				DrawSquare(x - 20, y - 30, 60, colors[ORANGE_RED]);
				DrawTriangle(x - 20, y + 30, x + 10, y , x + 40, y + 30, colors[MAROON]);


			}
			else if (name == "Diamond") {
				DrawRectangle(x - 25, y - 15, 70, 35, colors[CORN_FLOWER_BLUE]);
				DrawTriangle(x -35, y - 15, x -25, y - 25, x -25, y - 15, colors[CYAN]);
				DrawTriangle(x +53, y - 15, x +45, y - 25, x +45, y - 15, colors[AQUA_MARINE]);
				DrawTriangle(x -35, y +19, x -25, y +29, x -25, y +19, colors[AQUA_MARINE]);
				DrawTriangle(x  +54, y + 19, x + 44, y + 29, x+ 44, y + 19, colors[AQUA_MARINE]);
				DrawRectangle(x - 25, y +19, 70, 10, colors[DARK_CYAN]);
				DrawRectangle(x - 25, y - 24, 70, 10, colors[DARK_BLUE]);
				DrawRectangle(x - 34, y - 15, 10, 35, colors[DARK_TURQUOISE]);
				DrawRectangle(x +44, y - 15, 10, 35, colors[TEAL]);


			}
			else if (name == "Gemstone") {
				DrawSquare(x - 20, y - 30, 60, colors[YELLOW]);
				DrawTriangle(x - 20, y + 15, x + 10, y - 30, x + 40, y +15, colors[GREEN_YELLOW]);
				DrawTriangle(x - 20, y - 15, x + 10, y + 30, x + 40, y - 15, colors[GREEN_YELLOW]);
			}
			y = y + 100;
		}x += 100;
	}

}
void RandomizingJew() {
	int x, y, ran;
	x = 140; y = 0;
	for (int i = 0; i < 8; i++) {
		y = 80;
		for (int j = 0; j < 8; j++) {
			ran = GetRandInRange(0, 6);

			if (ran == 0) {
				jew[i][j].setx(x);
				jew[i][j].sety(y);
				jew[i][j].setGem("Pearl");
			}
			else if (ran == 1) {
				jew[i][j].setx(x);
				jew[i][j].sety(y);
				jew[i][j].setGem("Emerald");
			}
			else if (ran == 2) {
				jew[i][j].setx(x);
				jew[i][j].sety(y);
				jew[i][j].setGem("Ruby");
			}
			else if (ran == 3) {
				jew[i][j].setx(x);
				jew[i][j].sety(y);
				jew[i][j].setGem("Gold");
			}
			else if (ran == 4) {
				jew[i][j].setx(x);
				jew[i][j].sety(y);
				jew[i][j].setGem("Diamond");
			}
			else if (ran == 5) {
				jew[i][j].setx(x);
				jew[i][j].sety(y);
				jew[i][j].setGem("Gemstone");
			}
			y = y + 100;
		}x += 100;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << "The name is " << jew[i][j].getGem() <<endl;
		}
	}
}

void GameDisplay()/**/{

	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	if(pgno==0){
	}
	else if (pgno==1) {
		//Fire Gun
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Mushroom
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score
	//Spider
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)

	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
		DrawLine(100, 30, 100, 830, 10, colors[MISTY_ROSE]);
		DrawLine(100, 830, 900, 830, 10, colors[MISTY_ROSE]);
		DrawLine(900, 830, 900, 30, 10, colors[MISTY_ROSE]);
		DrawLine(900, 30, 100, 30, 10, colors[MISTY_ROSE]);

		//VERTICAL GRID
		DrawLine(200, 30, 200, 830, 5, colors[MISTY_ROSE]);
		DrawLine(300, 30, 300, 830, 5, colors[MISTY_ROSE]);
		DrawLine(400, 30, 400, 830, 5, colors[MISTY_ROSE]);
		DrawLine(500, 30, 500, 830, 5, colors[MISTY_ROSE]);
		DrawLine(600, 30, 600, 830, 5, colors[MISTY_ROSE]);
		DrawLine(700, 30, 700, 830, 5, colors[MISTY_ROSE]);
		DrawLine(800, 30, 800, 830, 5, colors[MISTY_ROSE]);
		DrawLine(900, 30, 900, 830, 5, colors[MISTY_ROSE]);

		//HORIZONTAL GRID
		DrawLine(100, 130, 900, 130, 5, colors[MISTY_ROSE]);
		DrawLine(100, 230, 900, 230, 5, colors[MISTY_ROSE]);
		DrawLine(100, 330, 900, 330, 5, colors[MISTY_ROSE]);
		DrawLine(100, 430, 900, 430, 5, colors[MISTY_ROSE]);
		DrawLine(100, 530, 900, 530, 5, colors[MISTY_ROSE]);
		DrawLine(100, 630, 900, 630, 5, colors[MISTY_ROSE]);
		DrawLine(100, 730, 900, 730, 5, colors[MISTY_ROSE]);
		DrawLine(100, 830, 900, 830, 5, colors[MISTY_ROSE]);

		//Score
		//DrawString(970, 800, "Score=%d",Id.score, colors[MISTY_ROSE]);


		//DRAW GREEN BAR
		DrawRoundRect(950, 105, 100, 550, colors[DARK_KHAKI], 30);
		DrawRoundRect(970, 120, 50, 515, colors[GREEN], 30);
		DrawLine(970, 206.25, 980, 206.25, 2, colors[DARK_GREEN]);
		DrawLine(970, 287.5, 980, 287.5, 2, colors[DARK_GREEN]);
		DrawLine(970, 368.75, 980, 368.75, 2, colors[DARK_GREEN]);
		DrawLine(970, 450, 980, 450, 2, colors[DARK_GREEN]);
		DrawLine(970, 531.25, 980, 531.25, 2, colors[DARK_GREEN]);
		DrawRoundRect(975, 125, 40, 500, colors[LAWN_GREEN], 30);

		//PAUSE BUTTON
		DrawCircle(990, 50, 30, colors[DARK_KHAKI]);
		DrawCircle(990, 50, 25, colors[SIENNA]);
		DrawLine(987, 40, 987, 60, 4, colors[DARK_KHAKI]);
		DrawLine(993, 40, 993, 60, 4, colors[DARK_KHAKI]);



		/*	switch (Score) {
			case 0: DrawRoundRect(975, 125, 40, 125, colors[LAWN_GREEN], 30); break;
			case 250: DrawRoundRect(975, 125, 40, 206.25, colors[LAWN_GREEN], 30); break;
			case 500: DrawRoundRect(975, 125, 40, 287.5, colors[LAWN_GREEN], 30); break;
			case 750: DrawRoundRect(975, 125, 40, 368.75, colors[LAWN_GREEN], 30); break;
			case 1000: DrawRoundRect(975, 125, 40, 450, colors[LAWN_GREEN], 30); break;

			}*/



			//DrawCircle(50,670,10,colors[RED]);
			//
			//DrawCircle(90,670,10,colors[RED]);
			//DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
			//DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
			//DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
			//DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
			//DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);
			//, x = 30; i < 8 && x <= 830; i++, x += 100)
			//y = 100; j < 8 && y <= 900; j++, y += 100
		Displayingjew();

	}
	glutSwapBuffers(); // do not modify this line..

}
/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	if (key == 10/* Escape key ASCII*/) {
		pgno=1 ;
	}
	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {
	static int startx;
	static int oldclick_x;
	static int oldclick_y;
	static int newclick_x;
	static int newclick_y;
	static int clicked;
	startx= 100;
	Jewel count;
	int ch;

	y = 840 - y;
	static int starty;
	starty= 130;
	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		if (state == GLUT_DOWN) {

			oldclick_x = x;
			oldclick_y = y;

		}
		
			if (state == GLUT_UP) 
			{
				clicked = 0;
				int new_x;
				int new_y;
				int old_x;
				int old_y;
				newclick_x = x;
				newclick_y = y;
				if (clicked == 1) {
						for (int i = 0; i < 8; i++) {
							starty = 130;
							for (int j = 0; j < 8; j++) {
								if (x >= startx && x <= (startx + 100)) {
									if (y >= starty && y <= (starty + 100)) {
										cout << "THE SELECTED SHAPE WAS: " << jew[i][j].getGem() << endl;
										newclick_x = i;
										newclick_y = j;
										if (jew[newclick_x][newclick_y].getGem() == jew[oldclick_x][oldclick_y].getGem()) {
											cout << "They are the same" << endl;
										}
										else {
											cout << "Ye tunay kia kiya!!!!" << endl;
										}
									}
								}
								starty += 80;

							}
							startx += 100;
						}
						//cout << GLUT_DOWN << " " << GLUT_UP << endl;
					}//
				}
			else {
				for (int i = 0; i < 8; i++) {
					starty = 130;
					for (int j = 0; j < 8; j++) {
						if (x >= startx && x <= (startx + 100)) {
							if (y >= starty && y <= (starty + 100)) {
								cout << "THE SELECTED SHAPE WAS: " << jew[i][j].getGem() << endl;
								jew[i][j].choosen = 1;
								count.ch_x = i;
								count.ch_y = j;
								count.select = 1;
								oldclick_x = i;
								oldclick_x = j;
								clicked = 1;
							}
						}
						starty += 80;

					}
					startx += 100;
				}
				//cout << GLUT_DOWN << " " << GLUT_UP << endl;
			}//
			}
	
		
		else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
		{
			//	cout<<"Right Button Pressed"<<endl;
			//H2P
		}
		glutPostRedisplay();
	}

/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	InitRandomizer(); // seed the random number generator...
	RandomizingJew();
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
