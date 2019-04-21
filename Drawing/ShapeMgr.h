#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"
#include "Shape.h"

using namespace std;
using namespace sf;


class ShapeMgr
{
private:
	vector <DrawingShape*> shapeHolder;     

public:

//================================================================================
// getShapeSize: gets the size of the shape
// parameters:
// return type: int
//================================================================================
	int getShapeSize()
	{
		int tempSize;
		tempSize = shapeHolder.size();
		return tempSize;
	}

//================================================================================
// getShapeHolderPtr: gets the pointer to an item in shapeHolder
// parameters:
//		indx: the index of the DrawingShape vector
// return type: DrawingShape*
//================================================================================
	DrawingShape* getShapeHolderPtr(int indx)
	{
		DrawingShape* drwShpPtr;

		drwShpPtr = shapeHolder[indx];

		return drwShpPtr;
	}

//================================================================================
// addShape: adds the chosen shape and color onto the vector
// parameters: 
//		pos: holds the location of the position of the mouse
//		selectedShape: holds the selected shape object
//		color: holds which color has been selected
// return type: void
//================================================================================
	void addShape(Vector2f pos, ShapeEnum selectedShape, Color color)
	{
		if (selectedShape == CIRCLE)
		{
			circle* newCircle;

			newCircle = new circle(pos, color, selectedShape);
			shapeHolder.push_back(newCircle);
		}

		if (selectedShape == SQUARE)
		{
			square* newSquare;
			newSquare = new square(pos, color, selectedShape);
			shapeHolder.push_back(newSquare);
		}
	}

//================================================================================
// outputFile: recieves fstream and writes the data to the binary file 
// parameters: 
//		outputFile: the fstream variable to allow acceess to the binary file to write data to it
// return type: void
//================================================================================
	void outputFile(fstream &outputFile)
	{
		for (int i = 0; i < shapeHolder.size(); i++)
		{
			outputFile.write(reinterpret_cast<char*>(&shapeHolder[i]->getShapeData()), sizeof(shapeHolder[i]->getShapeData()));
		}

	}

//================================================================================
// inputFile: recieves fstream and reads the data from the binary file 
// parameters:
//		inputFile: the fstream variable to allow acceess to the binary file to read data from it
// return type: void
//================================================================================
	void inputFile(fstream &inputFile)
	{
		int tempColor = 0;
		Color tempColor1;
		Vector2f tempVector2f;
		ShapeEnum tempShape = CIRCLE;

		while (inputFile.read(reinterpret_cast<char*>(&tempColor), sizeof(tempColor)))
		{
			inputFile.read(reinterpret_cast<char*>(&tempVector2f), sizeof(tempVector2f));
			inputFile.read(reinterpret_cast<char*>(&tempShape), sizeof(tempShape));

			Color aColor(tempColor);
			tempColor1 = aColor;
			addShape(tempVector2f, tempShape, tempColor1);

		}
	}
};