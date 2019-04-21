//================================================
// Josiah Ferguson
// Drawing Assignment
// March 25, 2019 -- LATE
//================================================
#include <iostream>
#include <fstream>
#include <SFML\Graphics.hpp>
#include "SettingsMgr.h"
#include "ShapeMgr.h"
#include "SettingsUI.h"
#include "DrawingUI.h"

using namespace sf;
using namespace std;


int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Drawing");
	window.setFramerateLimit(60);


	// create the classes to control the different aspects of the program
	SettingsMgr settingsMgr(Color::Blue, ShapeEnum::CIRCLE);
	SettingsUI  settingsUI(&settingsMgr);                        
	ShapeMgr    shapeMgr;                                                              
	DrawingUI   drawingUI(Vector2f(200, 50));

	// ********* Add code here to make the managers read from shapes file (if the file exists)
	fstream myFile;
	myFile.open("drawn.bin", ios::in | ios::binary);

	if (myFile)
	{
		settingsMgr.loadData(myFile);
		shapeMgr.inputFile(myFile);
	}

	myFile.close();


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
				fstream myFile;
				myFile.open("drawn.bin", ios::out | ios::binary);
				settingsMgr.saveData(myFile);
				shapeMgr.outputFile(myFile);
				myFile.close();

			}
			else if (event.type == Event::MouseButtonReleased)
			{
				// maybe they just clicked on one of the settings "buttons"
				// check for this and handle it.
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				settingsUI.handleMouseUp(mousePos);
			}
			else if (event.type == Event::MouseMoved && Mouse::isButtonPressed(Mouse::Button::Left))
			{

				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				// check to see if mouse is in the drawing area
				if (drawingUI.isMouseInSpace(mousePos))
				{
					// add a shape to the list based on current settings
					shapeMgr.addShape(mousePos, settingsMgr.getCurShape(), settingsMgr.getCurColor());
				}
			}
		}
		window.clear();
		settingsUI.draw(window);
		drawingUI.draw(window, &shapeMgr);
		window.display();
	}
	return 0;
}