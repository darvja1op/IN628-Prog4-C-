#include "GameManager.h"

GameManager::GameManager(Random^ startRGen, Graphics^ startOffScreenCanvas, Hero^ startHero)
{
	dungeon = gcnew Dungeon(startRGen);
	offScreenCanvas = startOffScreenCanvas;
	chickenHero = startHero;

	//creating tiles
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
	if (chickenHero->IsLegalMove(tileMap))
	{
		chickenHero->move();
	}
	tileMap->DrawMap();
	chickenHero->draw();	
}

void GameManager::loadDungeon()
{
	dungeon->makeNewDungeon(NUM_ROOMS);
	array<int, 2>^ translatedArray = dungeon->translateArray();
	tileMap->LoadMapFromArray(translatedArray);
}