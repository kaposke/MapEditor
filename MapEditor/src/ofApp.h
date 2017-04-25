#pragma once

#include "ofMain.h"
#include "Panel.h"
#include "DrawingGrid.h"
#include "SelectionGrid.h"
#include "TileHandler.h"
#include "Button.h"
#include <shellapi.h>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		Panel* gridPanel;
		Panel* selectionPanel;
		Panel* buttonsPanel;

		DrawingGrid* drawingGrid;
		SelectionGrid* pallete;
		int palleteOfSet;

		ofImage image;
		TileHandler* tileHandler;

		Button* saveButton;
};
