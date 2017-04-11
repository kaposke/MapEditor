#pragma once
#include "ofMain.h"
#include <vector>
#include "TileHandler.h"

using std::vector;

class DrawingGrid
{
private:
	vector< vector<int> > grid;
	int columns = 2;
	int rows = 2;

	ofVec2f position;
	float width = 0;
	float height = 0;
	float horizontalSize;
	float verticalSize;

	TileHandler *tileHandler;

	int mouseX;
	int mouseY;

	int clickedX;
	int clickedY;
public:
	DrawingGrid(float x, float y, float width, float height);

	void setPosition(float x, float y);
	void setPosition(ofVec2f position);

	ofVec2f getPosition();

	void setSize(float width, float height);

	void setRes(int horizontal, int vertical);

	void update(TileHandler *tileHandler_, int tile);

	void draw();
};