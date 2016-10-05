#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "Room.h"

#define MIN_ROOM_HEIGHT 5
#define MAX_ROOM_HEIGHT 15
#define MIN_ROOM_WIDTH 5
#define MAX_ROOM_WIDTH 15

#define MAP_COLS 50
#define MAP_ROWS 38

public enum ETileType { DIRT, CORRIDOR, DOOR, FLOOR, WALL };

ref class Dungeon
{
private:
	int numRooms;
	array<ETileType, 2>^ cellArray;
	array<Room^>^ rooms;
	Random^ rGen;
	Room^ newRoom;
public:
	Dungeon(Random^ startRGen);
	void makeNewDungeon(int numrooms);
	void clearDungeon();
	void makeRoom(int roomIndex);
	void makeCorridor(int room1, int room2);
	array<int, 2>^ translateArray();
	bool checkSpace(Room^ newRoom);
};

