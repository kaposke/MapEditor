#include "Scroll.h"

Scroll::Scroll(float x, float y, float height)
{
	pos.set(x,y);
	this->height = height;
	rectPos.set(pos.x - rectWidth / 2, pos.y);
}

void Scroll::setPosition(float x, float y)
{
	pos.set(x,y);
}

void Scroll::update()
{
	rectPos.x = pos.x - rectWidth / 2;

	percentage = ofMap(rectPos.y, pos.y, pos.y + height - rectHeight, 0, 100);

	if (!isPressed)
	{
		if (ofGetMousePressed(OF_MOUSE_BUTTON_1))
		{
			if (ofGetMouseX() > rectPos.x && ofGetMouseX() < rectPos.x + rectWidth &&
				ofGetMouseY() > rectPos.y && ofGetMouseY() < rectPos.y + rectHeight)
			{
				isPressed = true;
			}
		}
	}
	if (isPressed)
	{
		if (ofGetMousePressed(OF_MOUSE_BUTTON_1))
		{
			rectPos.y = ofGetMouseY() - rectHeight /2;
		}
		else
			isPressed = false;
	}
	if (rectPos.y < pos.y)
		rectPos.y = pos.y;
	if (rectPos.y + rectHeight > pos.y + height)
		rectPos.y = pos.y + height - rectHeight;
}

void Scroll::setHeight(float height)
{
	this->height = height;
}

float Scroll::getPercentage()
{
	return percentage;
}

void Scroll::draw()
{
	ofSetColor(255);
	ofDrawLine(pos.x, pos.y, pos.x, pos.y + height);
	ofDrawRectangle(rectPos, rectWidth, rectHeight);
}
