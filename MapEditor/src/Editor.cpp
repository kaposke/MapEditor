#include "Editor.h"

bool Editor::gotResized()
{
	return ofGetWidth() != screenWidth || ofGetHeight() != screenHeight ? true : false;
}

void Editor::setupPannels()
{
	//Setting up panels positions and colors
	//gridPanel
	gridPanel = new Panel(0, 0, ofGetHeight(), ofGetHeight());
	gridPanel->setColor(100, 100, 100);

	//selectionPanel
	selectionPanel = new Panel(gridPanel->getPosition().x + gridPanel->getWidth(), 0, ofGetWidth() - gridPanel->getWidth(), ofGetHeight());
	selectionPanel->setColor(51, 51, 51);

	//buttonsPanel
	buttonsPanel = new Panel(selectionPanel->getPosition().x, selectionPanel->getPosition().y, selectionPanel->getWidth(), 50);
	buttonsPanel->setColor(51, 51, 51);
}

void Editor::setupDrawingGrid()
{
	//Setting up the drawing grid position and resolution (w/h)
	drawingGrid = new DrawingGrid(gridPanel->getPosition().x, gridPanel->getPosition().x, gridPanel->getWidth(), gridPanel->getHeight());
	drawingGrid->setRes(16,16);
}

void Editor::setupPallete()
{
	//Setting up the pallete and scroll positions
	palleteOfSet = 10;
	pallete = new SelectionGrid(selectionPanel->getPosition().x + palleteOfSet, selectionPanel->getPosition().y + palleteOfSet, selectionPanel->getWidth() - palleteOfSet * 2, selectionPanel->getHeight() - palleteOfSet * 2);
	palleteScroll = new Scroll(pallete->getPosition().x + pallete->getWidth() + palleteOfSet * 2, 0 + palleteOfSet, ofGetHeight() - buttonsPanel->getHeight() - palleteOfSet * 2);
}

void Editor::setupBehaviourGrid()
{
	//Setting up the behaviourGrid position
	behaviourGrid = new BehaviourGrid(selectionPanel->getPosition().x + palleteOfSet, selectionPanel->getPosition().y + palleteOfSet, selectionPanel->getWidth() - palleteOfSet * 2, selectionPanel->getHeight() - palleteOfSet * 2);
}

void Editor::setupTile(int w, int h)
{
	//Cropping tiles
	image.loadImage(imgPath);
	tileHandler = new TileHandler();
	tileHandler->addTiles(image, w,h);
	for (int i = 0; i < tileHandler->getTilesAmount(); i++)
	{
		pallete->addTile(tileHandler->getTile(i));
	}

	//adding a default red behaviour (collision)
	behaviours.addBehaviour(255,0,0);
}

void Editor::setupButtons()
{
	//Setting up the buttons positions
	saveButton = new Button("Save", 15, buttonsPanel->getPosition().x, buttonsPanel->getPosition().y + buttonsPanel->getHeight() / 2, 70, 30);
	loadButton = new Button("Load", 15, saveButton->getPosition().x, saveButton->getPosition().y, 70, 30);
	exportButton = new Button("Export", 15, loadButton->getPosition().x, loadButton->getPosition().y, 90, 30);
	behaviourButton = new Button("Behaviours", 15, exportButton->getPosition().x, exportButton->getPosition().y, 130, 30);
	addBehaviourButton = new Button("Add", 15, ofGetWidth(), ofGetHeight() - buttonsPanel->getHeight() - palleteOfSet, 60, 30);
	
	
	open = new Button("...", 15, 400 - 40 - 20, 20 - 10, 40, 20);
	start = new Button("Start", 15, 400 - 40 - 30, 20 + 20 + 20, 60, 30);

	//Set a different color for behaviourButton
	behaviourButton->setColor(100,255,255,100);
	behaviourButton->setActiveColor(100, 255, 255, 255);
}

void Editor::setup()
{
	ofSetVerticalSync(false);
	ofSetWindowShape(400, 100);
	ofSetWindowPosition(ofGetScreenWidth()/2 - ofGetWidth()/2, ofGetScreenHeight()/2 - ofGetHeight()/2);
	ofSetWindowTitle("Kaposke's Map Editor");

	ofBackground(51);
	imgPath = "Select you tileSheet";
	pathPos.set(20,20);

	widthSlider = new Slider(20, 50,150,1,64);
	heightSlider = new Slider(20, 80, 150, 1, 64);
	
	//Calling all setup functions
	setupPannels();
	setupDrawingGrid();
	setupPallete();
	setupBehaviourGrid();
	setupButtons();

	blueSlider = new Slider(selectionPanel->getPosition().x + palleteOfSet, buttonsPanel->getPosition().y - palleteOfSet, selectionPanel->getWidth() - addBehaviourButton->getWidth() - palleteOfSet * 3, 0,255);
	greenSlider = new Slider(selectionPanel->getPosition().x + palleteOfSet, blueSlider->getPosition().y - palleteOfSet, selectionPanel->getWidth() - addBehaviourButton->getWidth() - palleteOfSet * 3, 0, 255);
	redSlider = new Slider(selectionPanel->getPosition().x + palleteOfSet, greenSlider->getPosition().y - palleteOfSet, selectionPanel->getWidth() - addBehaviourButton->getWidth() - palleteOfSet * 3, 0, 255);
}

void Editor::updatePannels()
{
	//Updating all panel positions(for if the screen gets resized)
	if(gotResized())
	{
		gridPanel->setPosition(0, 0);
		gridPanel->setSize(ofGetHeight(), ofGetHeight());

		selectionPanel->setPosition(gridPanel->getPosition().x + gridPanel->getWidth(), 0);
		selectionPanel->setSize(ofGetWidth() - gridPanel->getWidth(), ofGetHeight());

		buttonsPanel->setPosition(selectionPanel->getPosition().x, selectionPanel->getPosition().y + selectionPanel->getHeight() - buttonsPanel->getHeight());
		buttonsPanel->setSize(selectionPanel->getWidth(), buttonsPanel->getHeight());
	}
}

void Editor::updateDrawingGrid()
{
	//Updating the drawing grid position(for if the screen gets resized)
	if (gotResized())
	{
		drawingGrid->setPosition(gridPanel->getPosition());
		drawingGrid->setSize(gridPanel->getWidth(), gridPanel->getHeight());
	}
	//Toggle behaviour editor
	if (!collision)
		drawingGrid->update(tileHandler, pallete->getSelected());
	else
		drawingGrid->updateBehaviour(behaviourGrid->getSelected(behaviours));
}

void Editor::updatePallete()
{
	//Updating the pallete and scroll positions(for if the screen gets resized)
	if (gotResized())
	{
		pallete->setPosition(selectionPanel->getPosition() + palleteOfSet);
		pallete->setSize(selectionPanel->getWidth() - palleteOfSet * 2, selectionPanel->getHeight() - palleteOfSet * 2);
	}
	palleteScroll->setHeight(ofGetHeight() - buttonsPanel->getHeight() - palleteOfSet);
	palleteScroll->setPosition(pallete->getPosition().x + pallete->getWidth() + palleteOfSet, 0 + palleteOfSet);
	palleteScroll->update();
	pallete->setPosition(pallete->getPosition().x, ofMap(palleteScroll->getPercentage(), 0, 100, selectionPanel->getPosition().y + palleteOfSet, -pallete->getHeight() - buttonsPanel->getHeight() - palleteOfSet + ofGetHeight()));
	pallete->update();
}

void Editor::updateBehaviourGrid()
{
	//Updating the behaviour grid position(for if the screen gets resized)
	behaviourGrid->setPosition(selectionPanel->getPosition() + palleteOfSet);
	if (gotResized())
		behaviourGrid->setSize(selectionPanel->getWidth() - palleteOfSet * 2, selectionPanel->getHeight() - palleteOfSet * 2);

	//Calling functionality updates
	behaviourGrid->update(behaviours);
}

void Editor::updateButtons()
{
	//Updating all buttons positions(for if the screen gets resized)
	if (gotResized())
	{
		saveButton->setPosition(buttonsPanel->getPosition().x + palleteOfSet, buttonsPanel->getPosition().y + buttonsPanel->getHeight() / 2 - saveButton->getHeight() / 2);
		loadButton->setPosition(saveButton->getPosition().x + saveButton->getWidth() + palleteOfSet, saveButton->getPosition().y);
		exportButton->setPosition(loadButton->getPosition().x + loadButton->getWidth() + palleteOfSet, loadButton->getPosition().y);
		behaviourButton->setPosition(exportButton->getPosition().x + exportButton->getWidth() + palleteOfSet, exportButton->getPosition().y);	
	}
	if (collision)
		addBehaviourButton->setPosition(ofGetWidth() - addBehaviourButton->getWidth() - palleteOfSet, ofGetHeight() - buttonsPanel->getHeight() - addBehaviourButton->getHeight() - palleteOfSet);

	//Changing button color
	if (collision)
	{
		behaviourButton->setColor(100,255,255,255);
	}
	else
	{
		behaviourButton->setColor(100,255, 255, 100);
	}
}

void Editor::buttonBehaviors()
{
	//saveButton
	if (saveButton->isClicked())
	{
		ofFileDialogResult result = ofSystemSaveDialog("map.txt", "Save");
		if (result.bSuccess) {
			string path = result.getPath() + ".txt";
			ofstream arquivo(path);
			for (int y = 0; y < drawingGrid->getRows(); y++)
			{
				for (int x = 0; x < drawingGrid->getColumns(); x++)
				{
					arquivo << drawingGrid->getTile(x, y) << " ";
				}
				arquivo << endl;
			}
			arquivo.close();
		}
	}

	//loadButton
	if (loadButton->isClicked())
	{
		ofFileDialogResult result = ofSystemLoadDialog("Load file");
		if (result.bSuccess) {
			string path = result.getPath();
			ifstream arquivo(path);
			for (int y = 0; y < drawingGrid->getRows(); y++)
			{
				for (int x = 0; x < drawingGrid->getColumns(); x++)
				{
					int tile;
					arquivo >> tile;
					drawingGrid->setTile(x, y, tile);
				}
			}
			arquivo.close();
		}
	}

	
	//exportButton
	if (exportButton->isClicked() || c == 1)
	{
		if (!collision || c == 1)
		{
			c = 0;
			ofFileDialogResult result = ofSystemSaveDialog("map.png", "Save");
			if (result.bSuccess) {
				string path = result.getPath();
				string imgpath = path + ".png";
				map.grabScreen(gridPanel->getPosition().x, gridPanel->getPosition().y, gridPanel->getWidth(), gridPanel->getHeight());
				map.saveImage(imgpath);
				path = path + ".txt";
				ofstream arquivo(path);
				for (int y = 0; y < drawingGrid->getRows(); y++)
				{
					for (int x = 0; x < drawingGrid->getColumns(); x++)
					{
						arquivo << drawingGrid->getBehaviour(x, y) << " ";
					}
					arquivo << endl;
				}
				arquivo.close();
			}
		}
		else
		{
			collision = false;
			c = 1;
		}
	}

	//behaviourButton
	if (behaviourButton->isClicked())
	{
		if (collision)
			collision = false;
		else
			collision = true;
	}

	//addBehaviourButton
	if(collision)
		if (addBehaviourButton->isClicked())
		{
			behaviours.addBehaviour(redSlider->getValue(), greenSlider->getValue(), blueSlider->getValue());
		}
}

void Editor::update()
{
	switch (state)
	{
	case SETUP:
		if (open->isClicked())
		{
			ofFileDialogResult result = ofSystemLoadDialog("Open");
			if (result.bSuccess) {
				imgPath = result.getPath();
			}
		}
		widthSlider->update();
		heightSlider->update();

		if (start->isClicked())
		{
			setupTile(widthSlider->getValue(), heightSlider->getValue());
			ofSetWindowShape(1200, 768);
			ofSetWindowPosition(ofGetScreenWidth() / 2 - ofGetWidth() / 2, ofGetScreenHeight() / 2 - ofGetHeight() / 2);

			state = EDITOR;
		}
		break;
	case EDITOR:
		//Calling all update functions
		updatePannels();
		updateDrawingGrid();
		//Toggle behaviour editor
		if (!collision)
			updatePallete();
		else
			updateBehaviourGrid();
		updateButtons();
		buttonBehaviors();

		if (collision)
		{
			blueSlider->setPosition(selectionPanel->getPosition().x + palleteOfSet*3, buttonsPanel->getPosition().y - palleteOfSet * 2);
			greenSlider->setPosition(selectionPanel->getPosition().x + palleteOfSet * 3, blueSlider->getPosition().y - palleteOfSet * 2);
			redSlider->setPosition(selectionPanel->getPosition().x + palleteOfSet * 3, greenSlider->getPosition().y - palleteOfSet * 2);

			redSlider->setLength(selectionPanel->getWidth() - addBehaviourButton->getWidth() - palleteOfSet *9);
			greenSlider->setLength(selectionPanel->getWidth() - addBehaviourButton->getWidth() - palleteOfSet * 9);
			blueSlider->setLength(selectionPanel->getWidth() - addBehaviourButton->getWidth() - palleteOfSet * 9);

			redSlider->update();
			greenSlider->update();
			blueSlider->update();
		}

		screenWidth = ofGetWidth();
		screenHeight = ofGetHeight();
		break;
	}
}

void Editor::drawPannels()
{
	gridPanel->draw();
	selectionPanel->draw();
}

void Editor::drawDrawingGrid()
{
	ofSetColor(0, 50);
	drawingGrid->draw(behaviours, collision);
}

void Editor::drawPallete()
{
	ofSetColor(255, 50);
	pallete->draw();
	palleteScroll->draw();
}

void Editor::drawBehaviourGrid()
{
	ofSetColor(255, 50);
	behaviourGrid->draw(behaviours);
}

void Editor::drawButtons()
{
	//Drawing the buttonPanel overiding the pallete
	buttonsPanel->draw();

	//Drawing buttons
	saveButton->draw();
	loadButton->draw();
	exportButton->draw();
	behaviourButton->draw();
	if (collision)
		addBehaviourButton->draw();
}

void Editor::draw()
{
	switch (state)
	{
	case SETUP:
		ofDrawBitmapString(imgPath, pathPos);
		open->draw();
		start->draw();
		ofSetColor(255);
		ofDrawBitmapString("Horizontal Tiles",20,40);
		widthSlider->draw();
		ofDrawBitmapString("Vertical Tiles", 20, 70);
		heightSlider->draw();
		break;
	case EDITOR:
		drawPannels();
		drawDrawingGrid();

		//Toggle behaviour mode
		if (!collision)
			drawPallete();
		else
		{
			drawBehaviourGrid();
			redSlider->draw();
			blueSlider->draw();
			greenSlider->draw();
		}

		drawButtons();
		break;
	}
}

void Editor::hotKeys(int key)
{
	switch (state)
	{
	case SETUP:
		break;
	case EDITOR:
		//Toggle behaviour mode
		if (key == 'b' || key == 'B')
		{
			if (collision)
				collision = false;
			else
				collision = true;
		}
		break;
	}
}