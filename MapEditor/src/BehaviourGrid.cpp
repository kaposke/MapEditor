#include "BehaviourGrid.h"

BehaviourGrid::BehaviourGrid(float x, float y, float width, float height)
{
	position.set(x, y);
	this->width = width;
	this->height = height;
}

void BehaviourGrid::setPosition(float x, float y)
{
	position.set(x, y);
}

void BehaviourGrid::setPosition(ofVec2f position)
{
	this->position = position;
}

ofVec2f BehaviourGrid::getPosition()
{
	return position;
}

void BehaviourGrid::setSize(float width, float height)
{
	this->width = width;
	this->height = height;
}

int BehaviourGrid::getSelected(Behaviours behaviours)
{
	if (selectedPos >= behaviours.behaviours.size())
		return -1;
	else
		return selectedPos;
}

void BehaviourGrid::update(Behaviours behaviours)
{
	horizontalSize = maxSize;
	verticalSize = horizontalSize;

	columns = floor(width / horizontalSize);
	rows = ceil(behaviours.behaviours.size() / columns);

	mouseX = -1;
	mouseY = -1;

	if (ofGetMouseX() > position.x && ofGetMouseX() < position.x + width && ofGetMouseY() > position.y && ofGetMouseY() < position.y + rows*maxSize)
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
					if (ofGetMousePressed(OF_MOUSE_BUTTON_1))
					{
						selectedX = x;
						selectedY = y;
						selectedPos = pos;
					}
				}
				pos++;
			}
		}
	}
}

float BehaviourGrid::getWidth()
{
	return columns * maxSize;
}

float BehaviourGrid::getHeight()
{
	return rows * maxSize;
}

void BehaviourGrid::draw(Behaviours behaviours)
{
	for (int y = 0; y <= rows; y++)
	{
		ofDrawLine(position.x, position.y + verticalSize * y, position.x + horizontalSize * columns, position.y + verticalSize * y);
	}
	for (int x = 0; x <= columns; x++)
	{
		ofDrawLine(position.x + horizontalSize * x, position.y, position.x + horizontalSize * x, position.y + verticalSize * rows);
	}

	int pos = 0;
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < columns; x++)
		{
			ofSetColor(255, 255);
			if (pos < behaviours.behaviours.size())
			{
				if (x == selectedX && y == selectedY)
				{
					ofSetColor(behaviours.behaviours[pos].r, behaviours.behaviours[pos].g, behaviours.behaviours[pos].b,255);
					ofDrawRectangle(position.x + horizontalSize * x, position.y + verticalSize * y, horizontalSize, verticalSize);
				}
				else
				{
					ofSetColor(behaviours.behaviours[pos].r, behaviours.behaviours[pos].g, behaviours.behaviours[pos].b,255);
					ofDrawRectangle((position.x + horizontalSize * x) + maxSize / 8, (position.y + verticalSize * y) + maxSize / 8, horizontalSize - maxSize / 4, verticalSize - maxSize / 4);
				}
				ofSetColor(255);
				ofDrawBitmapString(pos + 1, position.x + horizontalSize * (x+1) - 20, position.y + verticalSize * (y+1) - 10);
			}
			pos++;
		}
	}

	ofSetColor(255, 50);
	if (mouseX >= 0 && mouseY >= 0)
		ofDrawRectangle(position.x + horizontalSize * mouseX, position.y + verticalSize * mouseY, horizontalSize, verticalSize);

	ofSetColor(0, 255, 0, 20);
	if (selectedX >= 0 && selectedY >= 0)
		ofDrawRectangle(position.x + horizontalSize * selectedX, position.y + verticalSize * selectedY, horizontalSize, verticalSize);
}
