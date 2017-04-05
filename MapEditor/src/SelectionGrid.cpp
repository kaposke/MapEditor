#include "SelectionGrid.h"

SelectionGrid::SelectionGrid(float x, float y, float width, float height)
{
	position.set(x, y);
	this->width = width;
	this->height = height;
}

void SelectionGrid::setPosition(float x, float y)
{
	position.set(x, y);
}

void SelectionGrid::setPosition(ofVec2f position)
{
	this->position = position;
}

ofVec2f SelectionGrid::getPosition()
{
	return position;
}

void SelectionGrid::setSize(float width, float height)
{
	this->width = width;
	this->height = height;
}

int SelectionGrid::getSelected()
{
	return selectedPos;
}

void SelectionGrid::addTile(ofImage tile)
{
	grid.push_back(tile);
}

void SelectionGrid::update()
{
	horizontalSize = maxSize;
	verticalSize = horizontalSize;

	columns = floor(width / horizontalSize);
	rows = ceil(grid.size() / columns);

	mouseX = -1;
	mouseY = -1;
	
	if (ofGetMouseX() > position.x && ofGetMouseX() < position.x + width && ofGetMouseY() > position.y && ofGetMouseY() < position.y + height)
	{
		int pos = 0;
		for (int y = 0; y < rows; y++)
		{
			for (int x = 0; x < columns; x++)
			{
				if (ofGetMouseX() > position.x + horizontalSize * x && ofGetMouseX() < position.x + horizontalSize * (x + 1) && ofGetMouseY() > position.y + verticalSize * y && ofGetMouseY() < position.y + verticalSize * (y + 1))
				{
					mouseX = x;
					mouseY = y;
					if (ofGetMousePressed())
					{
						selectedX = x;
						selectedY = y;
						selectedPos = x*columns + y*rows;
					}
				}
			}
		}
	}
}

void SelectionGrid::draw()
{
	for (int y = 0; y <= rows; y++)
	{
		for (int x = 0; x <= columns; x++)
		{
			ofDrawLine(position.x + horizontalSize * x, position.y, position.x + horizontalSize * x, position.y + verticalSize * rows);
			ofDrawLine(position.x, position.y + verticalSize * y, position.x + horizontalSize * columns, position.y + verticalSize * y);
			
		}
	}

	int pos = 0;
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < columns; x++)
		{
			ofSetColor(255, 255);
			if (pos < grid.size())
			{
				if (x == selectedX && y == selectedY)
					grid[pos].draw(position.x + horizontalSize * x, position.y + verticalSize * y, horizontalSize, verticalSize);
				else
					grid[pos].draw((position.x + horizontalSize * x) + maxSize / 8, (position.y + verticalSize * y) + maxSize / 8, horizontalSize - maxSize / 4, verticalSize - maxSize / 4);
			}
			pos++;
		}
	}

	ofSetColor(255, 50);
	if(mouseX >= 0 && mouseY >= 0)
		ofDrawRectangle(position.x + horizontalSize * mouseX, position.y + verticalSize * mouseY, horizontalSize, verticalSize);
	
	ofSetColor(0,255,0,20);
	if(selectedX >= 0 && selectedY >= 0)
		ofDrawRectangle(position.x + horizontalSize * selectedX, position.y + verticalSize * selectedY, horizontalSize, verticalSize);
}
