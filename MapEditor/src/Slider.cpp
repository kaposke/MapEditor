#include "Slider.h"

Slider::Slider(float x, float y, float length, float min, float max)
{
	pos.set(x,y);
	this->length = length;
	this->min = min;
	this->max = max;
	current = min;

	currentPosition = ofMap(current, min, max, 0, length);
}

Slider::Slider(float x, float y, float length, float min, float max, float start)
{
	pos.set(x, y);
	this->length = length;
	this->min = min;
	this->max = max;
	if (start >= min && start <= max)
		current = start;
	else if (start < min)
		current = min;
	else if (start > max)
		current = max;
	currentPosition = ofMap(current, min, max, 0, length);
}

void Slider::update()
{
	ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
	if (!isPressed)
	{
		if (ofGetMousePressed(OF_MOUSE_BUTTON_1))
		{
			if (mouse.distanceSquared(ofVec2f(pos.x + currentPosition, pos.y)) < 10)
			{
				isPressed = true;
			}
		}
	}
	if (isPressed)
	{
		if (ofGetMousePressed(OF_MOUSE_BUTTON_1))
		{
			currentPosition = mouse.x - pos.x;
		}
		else
			isPressed = false;
	}
	if (currentPosition < 0)
		currentPosition = 0;
	if (currentPosition > length)
		currentPosition = length;
	current = ceil(ofMap(currentPosition, 0,length, min, max));
}

void Slider::setPosition(float x, float y)
{
	pos.set(x,y);
}

void Slider::setLength(float size)
{
	length = size;
}

ofVec2f Slider::getPosition() const
{
	return pos;
}

int Slider::getValue()
{
	return current;
}

void Slider::draw()
{
	ofSetColor(255);
	ofDrawBitmapString(min, pos.x - 15, pos.y + 5);
	ofDrawBitmapString(max, pos.x + length + 10, pos.y + 5);
	ofDrawLine(pos.x, pos.y, pos.x + length, pos.y);
	
	if (isPressed)
	{
		ofSetColor(0, 100, 255);
		ofDrawCircle(pos.x + currentPosition, pos.y, 10);
		ofSetColor(255);
		ofDrawBitmapString(current, pos.x + currentPosition - 8, pos.y+ 5);
	}
	else
	{
		ofSetColor(0, 100, 255);
		ofDrawCircle(pos.x + currentPosition, pos.y, 5);
	}
	ofSetColor(255);
}
