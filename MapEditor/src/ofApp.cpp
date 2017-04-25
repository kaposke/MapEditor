#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//Panel Setup
	gridPanel = new Panel(0,0,ofGetHeight(),ofGetHeight());
	gridPanel->setColor(100,100,100);

	selectionPanel = new Panel(gridPanel->getPosition().x + gridPanel->getWidth(), 0, ofGetWidth() - gridPanel->getWidth(), ofGetHeight());
	selectionPanel->setColor(51,51,51);

	buttonsPanel = new Panel(selectionPanel->getPosition().x, selectionPanel->getPosition().y, selectionPanel->getWidth(), 50);
	buttonsPanel->setColor(51,51,51);

	//Grid Setup
	drawingGrid = new DrawingGrid(gridPanel->getPosition().x, gridPanel->getPosition().x, gridPanel->getWidth(), gridPanel->getHeight());
	drawingGrid->setRes(16,16);

	//Pallete Setup
	palleteOfSet = 20;
	pallete = new SelectionGrid(selectionPanel->getPosition().x + palleteOfSet, selectionPanel->getPosition().y + palleteOfSet, selectionPanel->getWidth() - palleteOfSet*2, selectionPanel->getHeight() - palleteOfSet*2);

	//Adding Tile
	image.loadImage("images/tileset.png");
	tileHandler = new TileHandler();
	tileHandler->addTiles(image,16,12);
	for (int i = 0; i < tileHandler->getTilesAmount(); i++)
	{
		pallete->addTile(tileHandler->getTile(i));
	}

	//Buttons Setup
	//Save Button
	saveButton = new Button("Save", 15, buttonsPanel->getPosition().x, buttonsPanel->getPosition().y + buttonsPanel->getHeight() / 2, 70, 30);
}

//--------------------------------------------------------------
void ofApp::update(){
	//Updating panels
	gridPanel->setPosition(0,0);
	gridPanel->setSize(ofGetHeight(), ofGetHeight());

	selectionPanel->setPosition(gridPanel->getPosition().x + gridPanel->getWidth(), 0);
	selectionPanel->setSize(ofGetWidth() - gridPanel->getWidth(), ofGetHeight());

	buttonsPanel->setPosition(selectionPanel->getPosition().x, selectionPanel->getPosition().y + selectionPanel->getHeight() - buttonsPanel->getHeight());
	buttonsPanel->setSize(selectionPanel->getWidth(), buttonsPanel->getHeight());

	//Updating DrawingGrid
	drawingGrid->setPosition(gridPanel->getPosition());
	drawingGrid->setSize(gridPanel->getWidth(), gridPanel->getHeight());
	drawingGrid->update(tileHandler, pallete->getSelected());

	//Updating pallete
	pallete->setPosition(selectionPanel->getPosition() + palleteOfSet);
	pallete->setSize(selectionPanel->getWidth() - palleteOfSet*2, selectionPanel->getHeight() - palleteOfSet*2);
	pallete->update();

	//Updating buttons
	saveButton->setPosition(buttonsPanel->getPosition().x + palleteOfSet, buttonsPanel->getPosition().y + buttonsPanel->getHeight()/2 - saveButton->getHeight()/2);

	//Button Behaviors
	//saveButton
	if (saveButton->isClicked())
	{

	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//Drawing Panels
	gridPanel->draw();
	selectionPanel->draw();

	//Drawing DrawingGrid
	ofSetColor(0,50);
	drawingGrid->draw();

	//Drawing pallete
	ofSetColor(255, 50);
	pallete->draw();

	//Drawing the buttonPanel overiding the pallete
	buttonsPanel->draw();

	//Drawing buttons
	saveButton->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
