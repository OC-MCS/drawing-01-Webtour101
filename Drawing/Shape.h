#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;


struct shapeData
{
	int color;        
	Vector2f pos;         
	ShapeEnum shapeType;    
};


class DrawingShape
{
private:
	Vector2f loc;  
	Color selectedColor;                          
	ShapeEnum selectedShape;                     
	shapeData chosenShapeData;

public:
	DrawingShape(Vector2f location, Color col, ShapeEnum shape)
	{
		loc = location;
		selectedColor = col;
		selectedShape = shape;

		chosenShapeData.color = col.toInteger();
		chosenShapeData.pos = location;
		chosenShapeData.shapeType = shape;
	}

	virtual void draw(RenderWindow &window) = 0;

//================================================================================
// getShapeData: gets the information in a drawingShape object
// parameters:
// return type: shapeData
//================================================================================
	shapeData getShapeData()
	{
		return chosenShapeData;
	}
};


// Derived from the DrawingShape class
class circle : public DrawingShape
{
public:
	CircleShape newCircle;

	circle(Vector2f location, Color col, ShapeEnum shape) : DrawingShape(location, col, shape)
	{
		newCircle.setPosition(location);
		newCircle.setRadius(12.0);
		newCircle.setOutlineThickness(3);
		newCircle.setOutlineColor(col);
		newCircle.setFillColor(col);
	}

//================================================================================
// draw: Draws the circle
// parameters: 
//		window: holds the information of the window
// return type: void
//================================================================================
	void draw(RenderWindow &window)
	{
		window.draw(newCircle);
	}
};

// Derived from the DrawingShape class
class square : public DrawingShape
{
public:
	RectangleShape newSquare;   

	square(Vector2f location1, Color col, ShapeEnum shape2) : DrawingShape(location1, col, shape2)
	{
		newSquare.setPosition(location1);
		newSquare.setOutlineColor(col);
		newSquare.setOutlineThickness(3);
		newSquare.setSize(Vector2f(12, 12));
		newSquare.setFillColor(col);
	}

//================================================================================
// draw: Draws the square
// parameters: 
//		window: holds the information of the window
// return type: void
//================================================================================
	void draw(RenderWindow &window)
	{
		window.draw(newSquare);
	}
};