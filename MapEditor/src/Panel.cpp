#include "Panel.h"

Panel::Panel()
{
	width = 0;
	height = 0;
}

Panel::Panel(float x, float y, float width, float height)
{
	position.set(x,y);
	this->width = width;
	this->height = height;
}

void Panel::setPosition(float x, float y)
{
	position.set(x,y);
}

ofVec2f Panel::getPosition()
{
	return position;
}

void Panel::setSize(float width, float height)
{
	this->width = width;
	this->height = height;
}

void Panel::setColor(int r, int g, int b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

void Panel::setColor(int r, int g, int b, int a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

float Panel::getWidth()
{
	return width;
}

float Panel::getHeight()
{
	return height;
}

void Panel::draw()
{
	ofSetColor(r, g, b, a);
	ofDrawRectangle(position, width, height);
}
