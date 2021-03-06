#pragma once
#include "ofMain.h"
#include <vector>
#include "TileHandler.h"
#include "Behaviours.h"

using std::vector;

class DrawingGrid
{
private:
	vector< vector<int> > grid;
	vector< vector<int> > behaviour;
	int columns = 2;
	int rows = 2;

	ofVec2f position;
	float width = 0;
	float height = 0;
	float horizontalSize;
	float verticalSize;

	TileHandler *tileHandler;

	int mouseX;
	int mouseY;

	bool hide = false;
public:
	DrawingGrid(float x, float y, float width, float height);

	void setPosition(float x, float y);
	void setPosition(ofVec2f position);

	ofVec2f getPosition();

	void setSize(float width, float height);

	void setRes(int horizontal, int vertical);

	void hideGrid(bool input);

	int getColumns();
	int getRows();

	int getTile(int x, int y);
	int getBehaviour(int x, int y);

	void setTile(int x, int y, int tile);

	void update(TileHandler *tileHandler_, int tile);
	void updateBehaviour(int behav);

	void draw(Behaviours behaviours,bool behav);
};