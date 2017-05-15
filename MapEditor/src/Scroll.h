#pragma once
#include "ofMain.h"

class Scroll
{
private:
	ofVec2f pos;
	ofVec2f rectPos;

	float height;
	float rectWidth =  20;
	float rectHeight = 100;
	
	bool isPressed = false;

	float percentage;
public:
	Scroll(float x, float y, float height);

	void setPosition(float x, float y);

	void update();

	void setHeight(float height);

	float getPercentage();

	void draw();
};