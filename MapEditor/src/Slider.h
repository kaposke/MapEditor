#pragma once
#include "ofMain.h"

class Slider
{
private:
	ofVec2f pos;
	float length;
	float min, max;
	int current;
	float currentPosition;

	bool isPressed = false;
public:
	Slider(float x, float y, float length, float min, float max);
	Slider(float x, float y, float length, float min, float max, float start);

	void update();

	void setPosition(float x, float y);

	void setLength(float size);

	ofVec2f getPosition() const;

	int getValue();

	void draw();
};