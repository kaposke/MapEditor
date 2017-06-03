#include "Button.h"

Button::Button(string label, ofVec2f position, float width, float height)
{
	this->label = label;
	this->fontSize = 8;
	font.load("fonts/Verdana.ttf", this->fontSize);

	this->position = position;
	this->width = width;
	this->height = height;
}

Button::Button(string label, float x, float y, float width, float height)
{
	this->label = label;
	this->fontSize = 8;
	font.load("fonts/Verdana.ttf", this->fontSize);

	this->position = ofVec2f(x,y);
	this->width = width;
	this->height = height;
}

Button::Button(string label, int fontSize, ofVec2f position, float width, float height)
{
	this->label = label;
	this->fontSize = fontSize;
	font.load("fonts/Verdana.ttf", this->fontSize);

	this->position = position;
	this->width = width;
	this->height = height;
}

Button::Button(string label, int fontSize, float x, float y, float width, float height)
{
	this->label = label;
	this->fontSize = fontSize;
	font.load("fonts/Verdana.ttf", this->fontSize);

	this->position = ofVec2f(x, y);
	this->width = width;
	this->height = height;
}

void Button::setPosition(float x, float y)
{
	position.set(x,y);
}

void Button::setSize(float width, float height)
{
	this->width = width;
	this->height = height;
}

ofVec2f Button::getPosition()
{
	return position;
}

void Button::setLabel(string label)
{
	this->label = label;
}

float Button::getWidth()
{
	return width;
}

float Button::getHeight()
{
	return height;
}

bool Button::checkStatus()
{
	if (ofGetMouseX() > position.x && ofGetMouseX() < position.x + width && ofGetMouseY() > position.y && ofGetMouseY() < position.y + height)
	{
		return true;
	}
	else {
		return false;
	}
}

bool Button::isClicked()
{
	bool result;
	if (!ofGetMousePressed(OF_MOUSE_BUTTON_1) && wasClicked && checkStatus()) 
		result = true;
	else
		result = false;

	if (ofGetMousePressed(OF_MOUSE_BUTTON_1) && checkStatus())
		wasClicked = true;
	else
		wasClicked = false;

	return result;
}

void Button::draw()
{
	if (checkStatus())
	{
		ofSetColor(ar,ag,ab,aa);
	}
	else
	{
		ofSetColor(r,g,b,a);
	}
	ofDrawRectangle(position, width, height);
	ofSetColor(0);
	ofRectangle stringBox = font.getStringBoundingBox(label,0,0);
	font.drawString(label, (position.x + width/2) - stringBox.getWidth()/2, (position.y + height/2) + stringBox.getHeight()/2);
}

void Button::setColor(int r, int g, int b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

void Button::setColor(int r, int g, int b, int a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

void Button::setActiveColor(int r, int g, int b)
{
	ar = r;
	ag = g;
	ab = b;
}

void Button::setActiveColor(int r, int g, int b, int a)
{
	ar = r;
	ag = g;
	ab = b;
	aa = a;
}
