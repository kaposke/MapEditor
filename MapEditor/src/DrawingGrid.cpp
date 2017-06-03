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
	grid.resize(columns, vector<int>(rows, -1));

	behaviour.resize(columns, vector<int>(rows, -1));
}

void DrawingGrid::hideGrid(bool input)
{
	hide = input;
}

int DrawingGrid::getColumns()
{
	return columns;
}

int DrawingGrid::getRows()
{
	return rows;
}

int DrawingGrid::getTile(int x, int y)
{
	return grid.at(y).at(x);
}

int DrawingGrid::getBehaviour(int x, int y)
{
	return behaviour.at(y).at(x)+1;
}

void DrawingGrid::setTile(int x, int y, int tile)
{
	grid.at(y).at(x) = tile;
}

void DrawingGrid::update(TileHandler *tileHandler_,int tile)
{
	mouseX = -1;
	mouseY = -1;

	tileHandler = tileHandler_;

	horizontalSize = width / columns;
	verticalSize = height / rows;
	if (ofGetMouseX() > position.x && ofGetMouseX() < position.x + width && ofGetMouseY() > position.y && ofGetMouseY() < position.y + height)
	{
			mouseX = (position.x + ofGetMouseX()) / horizontalSize;
			mouseY = (position.y+ ofGetMouseY()) / verticalSize;
			if (ofGetMousePressed(OF_MOUSE_BUTTON_1))
			{
				grid.at(mouseY).at(mouseX) = tile;
			}
			if (ofGetMousePressed(OF_MOUSE_BUTTON_3))
			{
				grid.at(mouseY).at(mouseX) = -1;
			}
		
	}
}

void DrawingGrid::updateBehaviour(int behav)
{
	mouseX = -1;
	mouseY = -1;

	horizontalSize = width / columns;
	verticalSize = height / rows;
	if (ofGetMouseX() > position.x && ofGetMouseX() < position.x + width && ofGetMouseY() > position.y && ofGetMouseY() < position.y + height)
	{
		mouseX = (position.x + ofGetMouseX()) / horizontalSize;
		mouseY = (position.y + ofGetMouseY()) / verticalSize;
		if (ofGetMousePressed(OF_MOUSE_BUTTON_1))
		{
			behaviour.at(mouseY).at(mouseX) = behav;
		}
		if (ofGetMousePressed(OF_MOUSE_BUTTON_3))
		{
			behaviour.at(mouseY).at(mouseX) = -1;
		}
	}
}

void DrawingGrid::draw(Behaviours behaviours, bool behav)
{
	//Draws the Grid Lines
	if (!hide)
	{
		for (int x = 0; x <= columns; x++)
		{
			ofDrawLine(position.x + horizontalSize * x, position.y, position.x + horizontalSize * x, position.y + height);
		}
		for (int y = 0; y <= rows; y++)
		{
			ofDrawLine(position.x, position.y + verticalSize * y, position.x + width, position.y + verticalSize * y);
		}
	}

	//Draws the tiles
	ofSetColor(255, 255);
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < columns; x++)
		{
			if(grid.at(y).at(x) >= 0)
				tileHandler->getTile(grid.at(y).at(x)).draw(position.x + horizontalSize*x, position.y + verticalSize*y, horizontalSize, verticalSize);
		}
	}

	//Draws the behaviours
	if (behav)
	{
		for (int y = 0; y < rows; y++)
		{
			for (int x = 0; x < columns; x++)
			{
				if (behaviour.at(y).at(x) >= 0)
				{
					ofSetColor(behaviours.behaviours.at(behaviour.at(y).at(x)).r, behaviours.behaviours.at(behaviour.at(y).at(x)).g, behaviours.behaviours.at(behaviour.at(y).at(x)).b, 100);
					ofDrawRectangle(position.x + horizontalSize*x, position.y + verticalSize*y, horizontalSize, verticalSize);
				}
			}
		}
	}
	
	//Highlights the mouse position in the grid
	if (!hide)
	{
		ofSetColor(255, 50);
		ofDrawRectangle(position.x + horizontalSize * mouseX, position.y + verticalSize * mouseY, horizontalSize, verticalSize);
	}
	ofSetColor(255);
}
