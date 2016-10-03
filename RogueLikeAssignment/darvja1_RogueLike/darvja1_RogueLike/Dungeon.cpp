#include "Dungeon.h"
#include "Room.h"
#include "Tile.h"
#include "TileMap.h"

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

	/*for (int r = 0; r < nRooms - 1; r++)
	{
		makeCorridor(r, r + 1);
	}*/
}

void Dungeon::clearDungeon()
{
	
}

void Dungeon::makeRoom()
{
	bool spaceAvailable = false;
	int roomIndex = 0;
	Room^ newRoom;

	//repeat until space is found
	while (!spaceAvailable)
	{
		int height = rGen->Next(MIN_ROOM_HEIGHT, MAX_ROOM_HEIGHT);
		int width = rGen->Next(MIN_ROOM_WIDTH, MAX_ROOM_WIDTH);

		int leftCol = rGen->Next(MAP_COLS);
		int topRow = rGen->Next(MAP_ROWS);

		newRoom = gcnew Room(leftCol, topRow, width, height);

		//check if area free
		spaceAvailable = true;
	}

	//record room in array
	rooms[roomIndex] = newRoom;

	for (int column = newRoom->leftCol; column < (newRoom->leftCol + newRoom->height); column++)
	{
		for (int row = newRoom->topRow; row < (newRoom->topRow + newRoom->width); row++)
		{
			cellArray[column, row] = ETileType::FLOOR;
		}
	}
}

void Dungeon::makeCorridor(int room1, int room2)
{

}

array<int, 2>^ Dungeon::translateArray()
{
	array<int, 2>^ translatedArray = gcnew array<int, 2>(MAP_COLS,MAP_ROWS);
	for (int column = 0; column < MAP_COLS; column++)
	{
		for (int row = 0; row < MAP_ROWS; row++)
		{
			switch (cellArray[column, row])
			{
			case ETileType::DIRT:
				translatedArray[column, row] = 0;
				break;
			case ETileType::FLOOR:
				translatedArray[column, row] = 1;
				break;
			case ETileType::WALL:
				translatedArray[column, row] = 2;
				break;
			case ETileType::DOOR:
				translatedArray[column, row] = 3;
				break;
			case ETileType::CORRIDOR:
				translatedArray[column, row] = 4;
				break;
			}
		}
	}
}