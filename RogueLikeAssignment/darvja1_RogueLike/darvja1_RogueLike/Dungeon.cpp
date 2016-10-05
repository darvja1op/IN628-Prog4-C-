#include "Dungeon.h"

Dungeon::Dungeon(Random^ startRGen)
{
	rGen = startRGen;
	
}

void Dungeon::makeNewDungeon(int nRooms)
{
	clearDungeon();

	rooms = gcnew array<Room^>(nRooms);
	cellArray = gcnew array<ETileType, 2>(MAP_COLS, MAP_ROWS);

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
	int height;
	int width;
	int leftCol;
	int topRow;

	//repeat until space is found
	while (!spaceAvailable)
	{
		//height = rGen->Next(MIN_ROOM_HEIGHT, MAX_ROOM_HEIGHT);
		//width = rGen->Next(MIN_ROOM_WIDTH, MAX_ROOM_WIDTH);

		//leftCol = rGen->Next(MAP_COLS);
		//topRow = rGen->Next(MAP_ROWS);

		height = 4;
		width = 4;
		leftCol = 4;
		topRow = 4;

		newRoom = gcnew Room(leftCol, topRow, width, height);

		//check if area free
		spaceAvailable = true;
	}

	//record room in array
	rooms[roomIndex] = newRoom;

	//filling room with floor tiles
	for (int column = leftCol; column < (leftCol + height); column++)
	{
		for (int row = topRow; row < (topRow + width); row++)
		{
			cellArray[column, row] = ETileType::FLOOR;
		}
	}

	//filling walls in

	//top wall 
	int column;
	int row;
	for (column = leftCol; column < (leftCol + width); column++)
	{
		cellArray[column, topRow] = ETileType::WALL;
	}

	row = topRow + height;
	for (column = leftCol; column < (leftCol + width); column++)
	{
		cellArray[column, row] = ETileType::WALL;
	}

	for (row = topRow; row < (topRow + height); row++)
	{
		cellArray[leftCol, row] = ETileType::WALL;
	}

	column = leftCol + width;
	for (row = topRow; row < (topRow + height); row++)
	{
		cellArray[column, row] = ETileType::WALL;
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

	return translatedArray;
}