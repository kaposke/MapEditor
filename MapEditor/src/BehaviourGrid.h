#pragma once
#include "ofMain.h"
#include <vector>
#include "Behaviours.h"

using std::vector;

class BehaviourGrid
{
private:
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
	BehaviourGrid(float x, float y, float width, float height);

	void setPosition(float x, float y);
	void setPosition(ofVec2f position);

	ofVec2f getPosition();

	void setSize(float width, float height);

	int getSelected(Behaviours behaviours);

	void update(Behaviours behaviours);

	float getWidth();
	float getHeight();

	void draw(Behaviours behaviours);
};