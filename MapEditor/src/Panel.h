#pragma once
#include "ofMain.h"
#include "ofVec2f.h"

class Panel
{
private:
	ofVec2f position;

	float width;
	float height;
	int r = 255;
	int g = 255;
	int b = 255;
	int a = 255;
public:
	Panel();
	Panel(float x, float y,float width, float height);

	void setPosition(float x, float y);

	ofVec2f getPosition();

	void setSize(float width, float height);

	void setColor(int r, int g, int b);
	void setColor(int r, int g, int b, int a);

	float getWidth();
	float getHeight();

	void draw();
};