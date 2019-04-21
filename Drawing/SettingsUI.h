#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SettingsMgr.h"
using namespace std;
using namespace sf;


class SettingsUI
{
private:
	CircleShape blueBtn;
	CircleShape redBtn;
	CircleShape greenBtn;
	RectangleShape squareBtn;
	CircleShape circleBtn;
	SettingsMgr *settingsMGR;

public:

	SettingsUI(SettingsMgr *mgr)
	{
		settingsMGR = mgr;
		// define blue button
		Vector2f pos1(115, 100);
		blueBtn.setPosition(pos1);
		blueBtn.setRadius(12);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);
		blueBtn.setFillColor(Color::Transparent);

		// define red button
		Vector2f pos2(115, 200);
		redBtn.setPosition(pos2);
		redBtn.setRadius(12);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);
		redBtn.setFillColor(Color::Transparent);

		// draw green button
		Vector2f pos3(115, 300);
		greenBtn.setPosition(pos3);
		greenBtn.setRadius(12);
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);
		greenBtn.setFillColor(Color::Transparent);

		// define square shape selection button
		Vector2f sqPos1(115, 425);
		squareBtn.setPosition(sqPos1);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(17, 17));
		squareBtn.setFillColor(Color::Transparent);

		// define circle shape selection button
		Vector2f pos4(115, 525);
		circleBtn.setPosition(pos4);
		circleBtn.setRadius(12);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::White);
		circleBtn.setFillColor(Color::Transparent);
	}

	//================================================================================
	// handleMouseUp: finds which button was selected when the mouse was clicked
	// parameters:
	//		mouse: contains the location of the mouse the moment the mouse was clicked
	// return type: void
	//================================================================================
	void handleMouseUp(Vector2f mouse)
	{
		if (blueBtn.getGlobalBounds().contains(mouse))
		{
			blueBtn.setFillColor(Color::Blue);
			settingsMGR->setCurColor(Color::Blue);

			redBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Transparent);
		}

		if (redBtn.getGlobalBounds().contains(mouse))
		{
			redBtn.setFillColor(Color::Red);
			settingsMGR->setCurColor(Color::Red);

			blueBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Transparent);
		}

		if (greenBtn.getGlobalBounds().contains(mouse))
		{
			greenBtn.setFillColor(Color::Green);
			settingsMGR->setCurColor(Color::Green);

			redBtn.setFillColor(Color::Transparent);
			blueBtn.setFillColor(Color::Transparent);
		}

		if (squareBtn.getGlobalBounds().contains(mouse))
		{
			squareBtn.setFillColor(Color::White);
			settingsMGR->setCurShape(SQUARE);

			circleBtn.setFillColor(Color::Transparent);
		}

		if (circleBtn.getGlobalBounds().contains(mouse))
		{
			circleBtn.setFillColor(Color::White);
			settingsMGR->setCurShape(CIRCLE);

			squareBtn.setFillColor(Color::Transparent);
		}
	}

	//================================================================================
	// draw: this draws the settings window, color buttons and the shape buttons 
	// parameters: 
	//		win: contains everything that will be displayed
	// return type: void
	//================================================================================
	void draw(RenderWindow& win)
	{
		if (settingsMGR->getCurColor() == Color::Blue)
		{
			blueBtn.setFillColor(Color::Blue);
		}

		if (settingsMGR->getCurColor() == Color::Red)
		{
			redBtn.setFillColor(Color::Red);
		}

		if (settingsMGR->getCurColor() == Color::Green)
		{
			greenBtn.setFillColor(Color::Green);
		}

		if (settingsMGR->getCurShape() == SQUARE)
		{
			squareBtn.setFillColor(Color::White);
		}

		if (settingsMGR->getCurShape() == CIRCLE)
		{
			circleBtn.setFillColor(Color::White);
		}

		// loading the font
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		// draw color menu title
		Text title1("Selected Color", font, 25);
		title1.setPosition(30, 25);
		win.draw(title1);

		// draw buttons
		win.draw(redBtn);
		win.draw(blueBtn);
		win.draw(greenBtn);

		// draw shape menu title
		Text title2("Selected Shape", font, 25);
		title2.setPosition(30, 350);
		win.draw(title2);

		// draw shape buttons
		win.draw(squareBtn);
		win.draw(circleBtn);
	}

	void die(string msg)
	{
		cout << msg << endl;
		exit(-1);
	}
};












//#pragma once
//#include <SFML/Graphics.hpp>
//#include <iostream>
//using namespace std;
//using namespace sf;
//#include "SettingsMgr.h"
//
//class SettingsUI
//{
//private:
//	CircleShape blueBtn;
//	CircleShape redBtn;
//	CircleShape greenBtn;
//	RectangleShape squareBtn;
//	CircleShape shapeBtn;
//	SettingsMgr *mngr;
//	Color chosenColor = (Color::Transparent);
//	bool isSquare = true;
//
//public:
//	SettingsUI(SettingsMgr *mgr)
//	{
//		mngr = mgr;
//	}
//	void handleMouseUp(Vector2f mouse)
//	{
//		if (blueBtn.getGlobalBounds().contains(mouse))
//		{
//			chosenColor = (Color::Blue);
//			mngr->setCurColor(Color::Blue);
//		}
//		else if (redBtn.getGlobalBounds().contains(mouse))
//		{
//			chosenColor = (Color::Red);
//			mngr->setCurColor(Color::Red);
//		}
//		else if (greenBtn.getGlobalBounds().contains(mouse))
//		{
//			chosenColor = (Color::Green);
//			mngr->setCurColor(Color::Green);
//		}
//		if (squareBtn.getGlobalBounds().contains(mouse))
//		{
//			isSquare = true;
//			mngr->setCurShape(SQUARE);
//		}
//		else if (shapeBtn.getGlobalBounds().contains(mouse))
//		{
//			isSquare = false;
//			mngr->setCurShape(CIRCLE);
//		}
//	}
//
//	void draw(RenderWindow& win)
//	{
//		// To load the font
//		Font font;
//		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
//			die("couldn't load font");
//
//		// Title for the colors
//		Text title("Drawing Color", font, 25);
//		title.setPosition(40, 25);
//		win.draw(title);
//
//		// For the blue button
//		Vector2f pos1(115, 90);
//		blueBtn.setPosition(pos1);
//		blueBtn.setRadius(15);
//		blueBtn.setOutlineThickness(2);
//		blueBtn.setOutlineColor(Color::Blue);
//
//		if (chosenColor == (Color::Blue))
//		{
//			blueBtn.setFillColor(Color::Blue);
//		}
//		else
//		{
//			blueBtn.setFillColor(Color::Transparent);
//		}
//		// Draws the blue circle on the screen
//		win.draw(blueBtn);
//
//		// For the red button
//		Vector2f pos2(115, 145);
//		redBtn.setPosition(pos2);
//		redBtn.setRadius(15);
//		redBtn.setOutlineThickness(2);
//		redBtn.setOutlineColor(Color::Red);
//
//		if (chosenColor == (Color::Red))
//		{
//			redBtn.setFillColor(Color::Red);
//		}
//		else
//		{
//			redBtn.setFillColor(Color::Transparent);
//		}
//		// Draws the red circle on the screen
//		win.draw(redBtn);
//
//		// For the green button
//		Vector2f pos3(115, 200);
//		greenBtn.setPosition(pos3);
//		greenBtn.setRadius(15);
//		greenBtn.setOutlineThickness(2);
//		greenBtn.setOutlineColor(Color::Green);
//
//		if (chosenColor == (Color::Green))
//		{
//			greenBtn.setFillColor(Color::Green);
//		}
//		else
//		{
//			greenBtn.setFillColor(Color::Transparent);
//		}
//		// Draws the green circle on the screen
//		win.draw(greenBtn);
//
//
//		// Title for the shapes
//		Text title2("Drawing Shape", font, 25);
//		title2.setPosition(40, 300);
//		win.draw(title2);
//
//		// For the Square button
//		Vector2f sqPos(115, 380);
//		squareBtn.setPosition(sqPos);
//		squareBtn.setOutlineColor(Color::White);
//		squareBtn.setOutlineThickness(2);
//		squareBtn.setSize(Vector2f(30, 30));
//
//		if (isSquare)
//		{
//			if (chosenColor == (Color::Transparent))
//			{
//				squareBtn.setFillColor(Color::White);
//			}
//			else
//			{
//				squareBtn.setFillColor(chosenColor);
//			}
//		}
//		else
//		{
//			squareBtn.setFillColor(Color::Transparent);
//		}
//
//		// renders a RectangleShape
//		win.draw(squareBtn);
//
//		
//		Vector2f pos4(115, 480);
//		shapeBtn.setPosition(pos4);
//		shapeBtn.setRadius(15);
//		shapeBtn.setOutlineThickness(2);
//		shapeBtn.setOutlineColor(Color::White);
//
//		// Displays which button is selected with what color is selected
//		if (!isSquare)
//		{
//			if (chosenColor == (Color::Transparent))
//			{
//				shapeBtn.setFillColor(Color::White);
//			}
//			else
//			{
//				shapeBtn.setFillColor(chosenColor);
//			}
//		}
//		else
//		{
//			shapeBtn.setFillColor(Color::Transparent);
//		}
//
//		// render a CircleShape
//		win.draw(shapeBtn);
//
//
//		RectangleShape drawingWindow;
//		Vector2f setPos(250, 0);
//		drawingWindow.setPosition(setPos);
//		drawingWindow.setOutlineColor(Color::White);
//		drawingWindow.setOutlineThickness(2);
//		drawingWindow.setSize(Vector2f(550, 600));
//		drawingWindow.setFillColor(Color::Transparent);
//
//		// renders a RectangleShape
//		win.draw(drawingWindow);
//	}
//
//	bool getShape()
//	{
//		return isSquare;
//	}
//
//	void die(string msg)
//	{
//		cout << msg << endl;
//		exit(-1);
//	}
//};