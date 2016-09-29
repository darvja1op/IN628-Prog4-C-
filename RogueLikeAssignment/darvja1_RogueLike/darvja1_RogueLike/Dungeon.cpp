#include "Dungeon.h"
#include "Room.h"
#include "Tile.h"
#include "TileMap.h"

public enum ETileType { Dirt, Corridor, Door, Floor, Wall};

Dungeon::Dungeon(Random^ startRGen)
{
	rGen = startRGen;
}

void Dungeon::makeNewDungeon(int nRooms)
{
	clearDungeon();

	for (int room = 0; room < nRooms; room++)
	{
		makeRoom();
	}

	for (int r = 0; r < nRooms - 1; r++)
	{
		makeCorridor(r, r + 1);
	}
}

void Dungeon::clearDungeon()
{
	
}

void Dungeon::makeRoom()
{
	//repeat until space is found

	int height = rGen->Next(MIN_ROOM_HEIGHT, MAX_ROOM_HEIGHT);
	int width = rGen->Next(MIN_ROOM_WIDTH, MAX_ROOM_WIDTH);

	int leftCol = rGen->Next(MAP_COLS);
	int topRow = rGen->Next(MAP_ROWS);

	//check if area free

	//record room in array
	
}

void Dungeon::makeCorridor(int room1, int room2)
{

}