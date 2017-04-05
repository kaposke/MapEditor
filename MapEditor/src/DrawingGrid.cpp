#include "DrawingGrid.h"

DrawingGrid::DrawingGrid(float x, float y, float width, float height)
{
	position.set(x, y);
	this->width = width;
	this->height = height;
}

void DrawingGrid::setPosition(float x, float y)
{
	position.set(x, y);
}

void DrawingGrid::setPosition(ofVec2f position)
{
	this->position = position;
}

ofVec2f DrawingGrid::getPosition()
{
	return position;
}

void DrawingGrid::setSize(float width, float height)
{
	this->width = width;
	this->height = height;
}

void DrawingGrid::setRes(int horizontal, int vertical)
{
	rows = horizontal;
	columns = vertical;
	for (int y = 0; y < vertical; y++)
	{
		vector<int> row(0, horizontal);
		grid.push_back(row);
	}
}

void DrawingGrid::update()
{
	mouseX = -1;
	mouseY = -1;

	horizontalSize = width / columns;
	verticalSize = height / rows;
	if (ofGetMouseX() > position.x && ofGetMouseX() < position.x + width && ofGetMouseY() > position.y && ofGetMouseY() < position.y + height)
	{
		for (int y = 0; y < rows; y++)
		{
			for (int x = 0; x < columns; x++)
			{
				if (ofGetMouseX() > position.x + horizontalSize * x && ofGetMouseX() < position.x + horizontalSize * (x + 1) && ofGetMouseY() > position.y + verticalSize * y && ofGetMouseY() < position.y + verticalSize * (y + 1))
				{
					mouseX = x;
					mouseY = y;
				}
			}
		}
	}
}

void DrawingGrid::draw()
{
	for (int y = 0; y <= rows; y++)
	{
		for (int x = 0; x <= columns; x++)
		{
			ofDrawLine(position.x + horizontalSize * x, position.y, position.x + horizontalSize * x, position.y + height);
			ofDrawLine(position.x, position.y + verticalSize * y, position.x + width, position.y + verticalSize * y);
		}
	}

	ofSetColor(255, 50);
	ofDrawRectangle(position.x + horizontalSize * mouseX, position.y + verticalSize * mouseY, horizontalSize, verticalSize);
}
