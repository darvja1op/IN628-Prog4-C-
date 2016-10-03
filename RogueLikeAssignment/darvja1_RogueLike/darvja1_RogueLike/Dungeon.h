#pragma once

#define MIN_ROOM_HEIGHT 5
#define MAX_ROOM_HEIGHT 15
#define MIN_ROOM_WIDTH 5
#define MAX_ROOM_WIDTH 15

public enum ETileType { DIRT, CORRIDOR, DOOR, FLOOR, WALL };

ref class Dungeon
{
private:
	int numRooms;
	array<ETileType, 2>^ cellArray;
	array<Room^>^ rooms;
	Random^ rGen;
public:
	Dungeon(Random^ startRGen);
	void makeNewDungeon(int numrooms);
	void clearDungeon();
	void makeRoom();
	void makeCorridor(int room1, int room2);
	array<int, 2>^ translateArray();
};

