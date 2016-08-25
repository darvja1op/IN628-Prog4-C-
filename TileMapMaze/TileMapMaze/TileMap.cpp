#include "TileMap.h"
#include "TileList.h"

TileMap::TileMap(TileList^ startTileList, Graphics^ startCanvas)
{
	gardenTiles = startTileList;
	canvas = startCanvas;
}

Bitmap^ TileMap::GetMapEntry(int col, int row)
{
	int currTileIndex = map[col, row];
	return gardenTiles->GetTileBitmap(currTileIndex);
}

void TileMap::DrawMap()
{

}