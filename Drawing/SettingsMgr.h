#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

class SettingsMgr
{
private:
	Color color;                                   
	ShapeEnum shape;               

public:
	SettingsMgr()
	{
		color = Color::Black;
		shape = CIRCLE;
	}

	SettingsMgr(Color startingColor, ShapeEnum startingShape)
	{
		color = startingColor;
		shape = startingShape;
	}

//================================================================================
// getCurColor: gets the current selected color
// parameters:
// return type: Color
//================================================================================
	Color getCurColor()
	{
		return color;
	}

//================================================================================
// getCurShape: get the current selected shape
// parameters: 
// return type: ShapeEnum
//================================================================================
	ShapeEnum getCurShape()
	{
		return shape;
	}

//================================================================================
// setCurColor: sets the color to the color the user selected
// parameters:
//		newColor: holds the color the user chose
// return type: void
//================================================================================
	void setCurColor(Color newColor)
	{
		color = newColor;
	}

//================================================================================
// setCurShape: sets the shape to the shape the user selected
// parameters:
//		newShape: holds the shape informatoin the user chose
// return type: void
//================================================================================
	void setCurShape(ShapeEnum newShape)
	{
		shape = newShape;
	}

//================================================================================
// loadData: receives an fstream and reads the variable values 
// parameters: 
//		inputFile: containts all the stored data of previously drawn data
// return type: void
//================================================================================
	void loadData(fstream &inputFile)
	{
		int temp = 0;
		inputFile.read(reinterpret_cast<char*>(&temp), sizeof(temp));
		Color tempColor(temp);
		color = tempColor;
		inputFile.read(reinterpret_cast<char*>(&shape), sizeof(shape));

	}

//================================================================================
// saveData: takes the opened file and writes data to it
// parameters:
//		outputFile: the opened file to have data written to it
// return type: void
//================================================================================
	void saveData(fstream &outputFile)
	{
		int tempColor = 0;
		tempColor = color.toInteger();
		outputFile.write(reinterpret_cast<char*>(&tempColor), sizeof(tempColor));
		outputFile.write(reinterpret_cast<char*>(&shape), sizeof(shape));
	}
};