#include "GameManager.h"

GameManager::GameManager(Random^ startRGen, Graphics^ startOffScreenCanvas, Hero^ startHero, Enemy^ startEnemy)
{
	dungeon = gcnew Dungeon(startRGen);
	offScreenCanvas = startOffScreenCanvas;
	hero = startHero;
	enemy = startEnemy;
	rGen = startRGen;

	treasureScore = 0;
	
	treasure = gcnew array<Sprite^>(NUM_GOLD);

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
	//if the next move is legal, allow the hero to move
	if (hero->IsLegalMove(tileMap))
	{
		hero->move();
	}

	//draw the hero and tilemap
	tileMap->DrawMap();
	hero->draw();

	//only draw enemies if they are alive
	if (enemy->IsAlive)
	{
		enemy->draw();
	}
	
	for each (Sprite^ gold in treasure)
	{
		//check collision between gold and hero
		bool hit = gold->CollidedWithMe(hero);
		
		if (hit)
		{
			gold->IsAlive = false;
			treasureScore += 100;
		}

		if (gold->IsAlive)
		{
			gold->draw();
		}
	}
}

void GameManager::loadDungeon()
{
	//make dungeon and load tilemap
	dungeon->makeNewDungeon(NUM_ROOMS);
	array<int, 2>^ translatedArray = dungeon->translateArray();
	tileMap->LoadMapFromArray(translatedArray);

	//placing sprites in rooms
	array<Room^>^ rooms = dungeon->GetRooms();
	
	int heroRoom = rGen->Next(rooms->Length);
	int heroRoomCentreCol = (rooms[heroRoom]->width / 2) + rooms[heroRoom]->leftCol;
	int heroRoomCentreRow = (rooms[heroRoom]->height / 2) + rooms[heroRoom]->topRow;

	Bitmap^ sampleTile = tileMap->GetMapEntry(heroRoomCentreCol,heroRoomCentreRow);
	int width = sampleTile->Width;
	int height = sampleTile->Height;

	hero->XPos = width * heroRoomCentreCol;
	hero->YPos = width * heroRoomCentreRow;

	//placing enemy not in same room as hero
	int enemyRoom = rGen->Next(rooms->Length);
	while (enemyRoom == heroRoom)
	{
		enemyRoom = rGen->Next(rooms->Length);
	}
	
	int enemyRoomCentreCol = (rooms[enemyRoom]->width / 2) + rooms[enemyRoom]->leftCol;
	int enemyRoomCentreRow = (rooms[enemyRoom]->height / 2) + rooms[enemyRoom]->topRow;

	enemy->XPos = width * enemyRoomCentreCol;
	enemy->YPos = width * enemyRoomCentreRow;

	//placing gold
	for (int i = 0; i < NUM_GOLD; i++)
	{
		array<String^>^ images = { "images/treasure.png", "images/treasure.png", "images/treasure.png", "images/treasure.png" };
		Sprite^ newGold = gcnew Sprite(offScreenCanvas, images, 1);

		int goldRoom = rGen->Next(rooms->Length);
		int goldRoomCentreCol = (rooms[goldRoom]->width / 2) + rooms[goldRoom]->leftCol;
		int goldRoomCentreRow = (rooms[goldRoom]->height / 2) + rooms[goldRoom]->topRow;

		newGold->XPos = width * goldRoomCentreCol;
		newGold->YPos = width * goldRoomCentreRow;

		treasure[i] = newGold;
	}
}