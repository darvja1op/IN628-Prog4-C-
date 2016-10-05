#include "GameManager.h"

#define NUM_ROOMS 1

GameManager::GameManager(Random^ startRGen, Graphics^ startOffScreenCanvas, Graphics^ startMainCanvas, Bitmap^ startBitmap)
{
	dungeon = gcnew Dungeon(startRGen);
	offScreenCanvas = startOffScreenCanvas;
	mainCanvas = startMainCanvas;
	offScreenBitmap = startBitmap;

	Bitmap^ corridorBitmap = gcnew Bitmap("images/Corridor.jpg");
	Bitmap^ dirtBitmap = gcnew Bitmap("images/Dirt.jpg");
	Bitmap^ doorBitmap = gcnew Bitmap("images/Door.jpg");
	Bitmap^ floorBitmap = gcnew Bitmap("images/Floor.jpg");
	Bitmap^ wallBitmap = gcnew Bitmap("images/Wall.jpg");

	Tile^ corridorTile = gcnew Tile(corridorBitmap, true);
	Tile^ dirtTile = gcnew Tile(dirtBitmap, false);
	Tile^ doorTile = gcnew Tile(doorBitmap, true);
	Tile^ floorTile = gcnew Tile(floorBitmap, true);
	Tile^ wallTile = gcnew Tile(wallBitmap, false);

	TileList^ tileList = gcnew TileList();

	tileList->SetTileArrayEntry(0, dirtTile);
	tileList->SetTileArrayEntry(1, floorTile);
	tileList->SetTileArrayEntry(2, wallTile);
	tileList->SetTileArrayEntry(3, doorTile);
	tileList->SetTileArrayEntry(4, corridorTile);

	tileMap = gcnew TileMap(tileList, offScreenCanvas);
}

void GameManager::runGame()
{	
	tileMap->DrawMap();
	mainCanvas->DrawImage(offScreenBitmap, 0, 0);
}

void GameManager::loadDungeon()
{
	dungeon->makeNewDungeon(NUM_ROOMS);
	array<int, 2>^ translatedArray = dungeon->translateArray();
	tileMap->LoadMapFromArray(translatedArray);
}