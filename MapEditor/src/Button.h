#pragma once
#include "ofMain.h"

class Button
{
private:
	ofTrueTypeFont font;
	int fontSize;
	
	string label;
	ofVec2f position;
	float width, height;

	int r = 255;
	int g = 255;
	int b = 255;
	int a = 255;

	int ar = 200;
	int ag = 200;
	int ab = 200;
	int aa = 255;

	bool wasClicked = false;
public:
	Button(string label, ofVec2f position, float width, float height);

	Button(string label, float x, float y, float width, float height);

	Button(string label, int fontSize, ofVec2f position, float width, float height);

	Button(string label, int fontSize, float x, float y, float width, float height);

	void setPosition(float x, float y);

	void setSize(float width, float height);

	ofVec2f getPosition();

	void setLabel(string label);

	float getWidth();
	float getHeight();

	bool checkStatus();

	bool isClicked();

	void draw();

	void setColor(int r, int g, int b);
	void setColor(int r, int g, int b, int a);

	void setActiveColor(int r, int g, int b);
	void setActiveColor(int r, int g, int b, int a);
};