#include "Dungeon.h"

Dungeon::Dungeon(Random^ startRGen)
{
	rGen = startRGen;
	cellArray = gcnew array<ETileType, 2>(MAP_COLS, MAP_ROWS);
}

void Dungeon::makeNewDungeon(int nRooms)
{
	rooms = gcnew array<Room^>(nRooms);
	clearDungeon();

	for (int room = 0; room < nRooms; room++)
	{
		makeRoom(room);
	}

	for (int r = 0; r < nRooms - 1; r++)
	{
		makeCorridor(r, r + 1);
	}
}

void Dungeon::clearDungeon()
{
	//filling room with dirt tiles
	for (int column = 0; column < MAP_COLS; column++)
	{
		for (int row = 0; row < MAP_ROWS; row++)
		{
			cellArray[column, row] = ETileType::DIRT;
		}
	}
}

void Dungeon::makeRoom(int roomIndex)
{
	bool spaceAvailable = false;
	int height;
	int width;
	int leftCol;
	int topRow;

	//repeat until space is found
	while (!spaceAvailable)
	{
		height = rGen->Next(MIN_ROOM_HEIGHT, MAX_ROOM_HEIGHT);
		width = rGen->Next(MIN_ROOM_WIDTH, MAX_ROOM_WIDTH);

		leftCol = rGen->Next(MAP_COLS - MIN_ROOM_WIDTH);
		topRow = rGen->Next(MAP_ROWS - MIN_ROOM_HEIGHT);

		newRoom = gcnew Room(leftCol, topRow, width, height);

		//check if area free
		spaceAvailable = checkSpace(newRoom);
	}

	//record room in array
	rooms[roomIndex] = newRoom;

	//filling room with floor tiles
	for (int column = leftCol; column <= (leftCol + width); column++)
	{
		for (int row = topRow; row <= (topRow + height); row++)
		{
			cellArray[column, row] = ETileType::FLOOR;
		}
	}

	//filling walls in
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

	for (row = topRow; row <= (topRow + height); row++)
	{
		cellArray[leftCol, row] = ETileType::WALL;
	}

	column = leftCol + width;
	for (row = topRow; row <= (topRow + height); row++)
	{
		cellArray[column, row] = ETileType::WALL;
	}
}

void Dungeon::makeCorridor(int room1, int room2)
{
	int room1CentreCol = (rooms[room1]->width / 2) + rooms[room1]->leftCol;
	int room1CentreRow = (rooms[room1]->height / 2) + rooms[room1]->topRow;

	int room2CentreCol = (rooms[room2]->width / 2) + rooms[room2]->leftCol;
	int room2CentreRow = (rooms[room2]->height / 2) + rooms[room2]->topRow;

	//horizontal corridor
	int col;
	if (room1CentreCol < room2CentreCol)
	{
		for (col = room1CentreCol; col < room2CentreCol; col++)
		{
			switch (cellArray[col, room1CentreRow])
			{
			case ETileType::WALL:
				cellArray[col, room1CentreRow] = ETileType::DOOR;
				break;
			case ETileType::FLOOR:
				cellArray[col, room1CentreRow] = ETileType::FLOOR;
				break;
			default:
				cellArray[col, room1CentreRow] = ETileType::CORRIDOR;
				break;
			}
		}
	}
	else
	{
		for (col = room2CentreCol; col < room1CentreCol; col++)
		{
			switch (cellArray[col, room2CentreRow])
			{
			case ETileType::WALL:
				cellArray[col, room2CentreRow] = ETileType::DOOR;
				break;
			case ETileType::FLOOR:
				cellArray[col, room2CentreRow] = ETileType::FLOOR;
				break;
			case ETileType::DIRT:
				cellArray[col, room2CentreRow] = ETileType::CORRIDOR;
				break;
			case ETileType::CORRIDOR:
				cellArray[col, room2CentreRow] = ETileType::CORRIDOR;
				break;
			case ETileType::DOOR:
				cellArray[col, room2CentreRow] = ETileType::DOOR;
				break;
			}
		}
	}

	//vertical corridor
	int row;
	if (room1CentreRow < room2CentreRow)
	{
		for (row = room1CentreRow; row < room2CentreRow; row++)
		{
			switch (cellArray[col, row])
			{
			case ETileType::WALL:
				cellArray[col, row] = ETileType::DOOR;
				break;
			case ETileType::FLOOR:
				cellArray[col, row] = ETileType::FLOOR;
				break;
			default:
				cellArray[col, row] = ETileType::CORRIDOR;
				break;
			}
		}
	}
	else
	{
		for (row = room2CentreRow; row < room1CentreRow; row++)
		{
			switch (cellArray[col, row])
			{
			case ETileType::WALL:
				cellArray[col, row] = ETileType::DOOR;
				break;
			case ETileType::FLOOR:
				cellArray[col, row] = ETileType::FLOOR;
				break;
			default:
				cellArray[col, row] = ETileType::CORRIDOR;
				break;
			}
		}
	}

	//place door for testing
	//cellArray[room1CentreCol, room1CentreRow] = ETileType::DOOR;
	//cellArray[room2CentreCol, room2CentreRow] = ETileType::DOOR;
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

bool Dungeon::checkSpace(Room^ newRoom)
{
	bool spaceAvailable = true;

	if ((newRoom->width + newRoom->leftCol) >= MAP_COLS)
	{
		return false;
	}

	if ((newRoom->height + newRoom->topRow) >= MAP_ROWS)
	{
		return false;
	}

	for (int col = newRoom->leftCol; col < (newRoom->width + newRoom->leftCol); col++)
	{
		for (int row = newRoom->topRow; row < (newRoom->height + newRoom->topRow); row++)
		{
			if (cellArray[col, row] != ETileType::DIRT)
			{
				return false;
			}
		}
	}

	return spaceAvailable;
}