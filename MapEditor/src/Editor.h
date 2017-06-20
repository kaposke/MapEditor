#pragma once

#include "ofMain.h"
#include "Panel.h"
#include "DrawingGrid.h"
#include "SelectionGrid.h"
#include "BehaviourGrid.h"
#include "TileHandler.h"
#include "Button.h"
#include <fstream>
#include "Scroll.h"
#include "Behaviours.h"
#include "Slider.h"

#define SETUP 0
#define EDITOR 1

class Editor
{
private:
	int state = SETUP;
	//SETUP STATE
	Button* open;
	string imgPath;
	ofVec2f pathPos;
	Button* start;
	Slider* widthSlider;
	Slider* heightSlider;

	//EDITOR STATE
	float screenWidth = 0;
	float screenHeight = 0;

	Panel* gridPanel;
	Panel* selectionPanel;
	Panel* buttonsPanel;

	Behaviours behaviours;

	DrawingGrid* drawingGrid;
	SelectionGrid* pallete;
	BehaviourGrid* behaviourGrid;

	int palleteOfSet;

	Scroll* palleteScroll;

	ofImage image;
	TileHandler* tileHandler;

	ofImage map;

	Button* saveButton;
	Button* loadButton;
	Button* exportButton;
	int c = 0;
	Button* behaviourButton;
	Button* addBehaviourButton;

	Slider* redSlider;
	Slider* greenSlider;
	Slider* blueSlider;

	bool collision = false;
public:
	bool gotResized();

	void setupPannels();
	void setupDrawingGrid();
	void setupPallete();
	void setupBehaviourGrid();
	void setupTile(int w, int h);
	void setupButtons();

	void setup();

	void updatePannels();
	void updateDrawingGrid();
	void updatePallete();
	void updateBehaviourGrid();
	void updateButtons();
	void buttonBehaviors();

	void update();

	void drawPannels();
	void drawDrawingGrid();
	void drawPallete();
	void drawBehaviourGrid();
	void drawButtons();

	void draw();

	void hotKeys(int key);
};