#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ShapeMgr.h"
using namespace std;
using namespace sf;


class DrawingUI
{
private:
	RectangleShape border;                
	RectangleShape settingsBorder;          
public:
	// Default Constructor
	DrawingUI(Vector2f loc)
	{
	}

//================================================================================
// draw: this draws the drawing canvas, the shapes on the canvas, and the borders around it
// parameters:
//		win: Contains all the information to be drawn on the screen
//		*mgr: pointer to a shape
// return type: void
//================================================================================
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		// Draws main border
		Vector2f sqPos2(0, 0);
		border.setPosition(sqPos2);
		border.setOutlineColor(Color::White);
		border.setOutlineThickness(10);
		border.setSize(Vector2f(800, 600));
		border.setFillColor(Color::Transparent);
		win.draw(border);

		// Draw left border for settings menu
		Vector2f sqPos3(0, 0);
		settingsBorder.setPosition(sqPos3);
		settingsBorder.setOutlineColor(Color::White);
		settingsBorder.setOutlineThickness(3);
		settingsBorder.setSize(Vector2f(240, 600));
		settingsBorder.setFillColor(Color::Transparent);
		win.draw(settingsBorder);

		for (int x = 0; x < mgr->getShapeSize(); x++)
		{

			mgr->getShapeHolderPtr(x)->draw(win);
		}
	}

//================================================================================
// isMouseInCanvas: checks to see if the mouse is inside the drawing space
// parameters:
//		mousePos: holds the location of the mouse
// return type: bool
//================================================================================
	bool isMouseInSpace(Vector2f mousePos)
	{
		if (mousePos.x >= 240 && mousePos.x <= 800 && mousePos.y >= 0 && mousePos.y <= 600)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};