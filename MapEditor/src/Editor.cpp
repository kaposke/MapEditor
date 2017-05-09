#include "Editor.h"

void Editor::setupPannels()
{
	gridPanel = new Panel(0, 0, ofGetHeight(), ofGetHeight());
	gridPanel->setColor(100, 100, 100);

	selectionPanel = new Panel(gridPanel->getPosition().x + gridPanel->getWidth(), 0, ofGetWidth() - gridPanel->getWidth(), ofGetHeight());
	selectionPanel->setColor(51, 51, 51);

	buttonsPanel = new Panel(selectionPanel->getPosition().x, selectionPanel->getPosition().y, selectionPanel->getWidth(), 50);
	buttonsPanel->setColor(51, 51, 51);
}

void Editor::setupDrawingGrid()
{
	drawingGrid = new DrawingGrid(gridPanel->getPosition().x, gridPanel->getPosition().x, gridPanel->getWidth(), gridPanel->getHeight());
	drawingGrid->setRes(16, 16);
}

void Editor::setupPallete()
{
	palleteOfSet = 10;
	pallete = new SelectionGrid(selectionPanel->getPosition().x + palleteOfSet, selectionPanel->getPosition().y + palleteOfSet, selectionPanel->getWidth() - palleteOfSet * 2, selectionPanel->getHeight() - palleteOfSet * 2);
}

void Editor::setupTile()
{
	image.loadImage("images/kenney.png");
	tileHandler = new TileHandler();
	tileHandler->addTiles(image, 27, 20);
	for (int i = 0; i < tileHandler->getTilesAmount(); i++)
	{
		pallete->addTile(tileHandler->getTile(i));
	}
}

void Editor::setupButtons()
{
	saveButton = new Button("Save", 15, buttonsPanel->getPosition().x, buttonsPanel->getPosition().y + buttonsPanel->getHeight() / 2, 70, 30);
	loadButton = new Button("Load", 15, saveButton->getPosition().x, saveButton->getPosition().y, 70, 30);
	exportButton = new Button("Export", 15, loadButton->getPosition().x, loadButton->getPosition().y, 90, 30);
}

void Editor::setup()
{
	setupPannels();
	setupDrawingGrid();
	setupPallete();
	setupTile();
	setupButtons();
}

void Editor::updatePannels()
{
	gridPanel->setPosition(0, 0);
	gridPanel->setSize(ofGetHeight(), ofGetHeight());

	selectionPanel->setPosition(gridPanel->getPosition().x + gridPanel->getWidth(), 0);
	selectionPanel->setSize(ofGetWidth() - gridPanel->getWidth(), ofGetHeight());

	buttonsPanel->setPosition(selectionPanel->getPosition().x, selectionPanel->getPosition().y + selectionPanel->getHeight() - buttonsPanel->getHeight());
	buttonsPanel->setSize(selectionPanel->getWidth(), buttonsPanel->getHeight());
}

void Editor::updateDrawingGrid()
{
	drawingGrid->setPosition(gridPanel->getPosition());
	drawingGrid->setSize(gridPanel->getWidth(), gridPanel->getHeight());
	drawingGrid->update(tileHandler, pallete->getSelected());
}

void Editor::updatePallete()
{
	pallete->setPosition(selectionPanel->getPosition() + palleteOfSet);
	pallete->setSize(selectionPanel->getWidth() - palleteOfSet * 2, selectionPanel->getHeight() - palleteOfSet * 2);
	pallete->update();
}

void Editor::updateButtons()
{
	saveButton->setPosition(buttonsPanel->getPosition().x + palleteOfSet, buttonsPanel->getPosition().y + buttonsPanel->getHeight() / 2 - saveButton->getHeight() / 2);
	loadButton->setPosition(saveButton->getPosition().x + saveButton->getWidth() + palleteOfSet, saveButton->getPosition().y);
	exportButton->setPosition(loadButton->getPosition().x + loadButton->getWidth() + palleteOfSet, loadButton->getPosition().y);
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
	if (exportButton->isClicked())
	{
		ofFileDialogResult result = ofSystemSaveDialog("map.png", "Save");
		if (result.bSuccess) {
			string path = result.getPath();
			path = path + ".png";
			ofImage map;
			map.grabScreen(gridPanel->getPosition().x, gridPanel->getPosition().y, gridPanel->getWidth(), gridPanel->getHeight());
			map.saveImage(path);
		}
	}
}

void Editor::update()
{
	updatePannels();
	updateDrawingGrid();
	updatePallete();
	updateButtons();
	buttonBehaviors();
}

void Editor::drawPannels()
{
	gridPanel->draw();
	selectionPanel->draw();
}

void Editor::drawDrawingGrid()
{
	ofSetColor(0, 50);
	drawingGrid->draw();
}

void Editor::drawPallete()
{
	ofSetColor(255, 50);
	pallete->draw();
}

void Editor::drawButtons()
{
	//Drawing the buttonPanel overiding the pallete
	buttonsPanel->draw();

	//Drawing buttons
	saveButton->draw();
	loadButton->draw();
	exportButton->draw();
}

void Editor::draw()
{
	drawPannels();
	drawDrawingGrid();
	drawPallete();
	drawButtons();
}
