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

class Editor
{
private:
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

	bool collision = false;
public:
	void setupPannels();
	void setupDrawingGrid();
	void setupPallete();
	void setupBehaviourGrid();
	void setupTile();
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