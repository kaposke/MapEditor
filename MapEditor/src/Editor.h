#pragma once

#include "ofMain.h"
#include "Panel.h"
#include "DrawingGrid.h"
#include "SelectionGrid.h"
#include "TileHandler.h"
#include "Button.h"
#include <fstream>
#include "Scroll.h"

class Editor
{
private:
	Panel* gridPanel;
	Panel* selectionPanel;
	Panel* buttonsPanel;

	DrawingGrid* drawingGrid;
	SelectionGrid* pallete;
	int palleteOfSet;

	Scroll* palleteScroll;

	ofImage image;
	TileHandler* tileHandler;

	Button* saveButton;
	Button* loadButton;
	Button* exportButton;
public:
	void setupPannels();
	void setupDrawingGrid();
	void setupPallete();
	void setupTile();
	void setupButtons();

	void setup();

	void updatePannels();
	void updateDrawingGrid();
	void updatePallete();
	void updateButtons();
	void buttonBehaviors();

	void update();

	void drawPannels();
	void drawDrawingGrid();
	void drawPallete();
	void drawButtons();

	void draw();
};