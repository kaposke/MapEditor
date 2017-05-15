#pragma once
#include "ofMain.h"
#include <vector>

using std::vector;

class SelectionGrid
{
private:
	vector<ofImage> grid;
	float columns = 0;
	float rows = 0;

	ofVec2f position;
	float width = 1;
	float height = 1;
	float horizontalSize;
	float verticalSize;

	float maxSize = 50;

	int mouseX;
	int mouseY;

	int selectedPos = -1;
	int selectedX = -1;
	int selectedY = -1;
public:
	SelectionGrid(float x, float y, float width, float height);

	void setPosition(float x, float y);
	void setPosition(ofVec2f position);

	ofVec2f getPosition();

	void setSize(float width, float height);

	int getSelected();

	void addTile(ofImage tile);

	void update();

	float getWidth();
	float getHeight();

	void draw();
};