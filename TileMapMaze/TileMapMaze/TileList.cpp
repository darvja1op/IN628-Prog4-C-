#include "TileList.h"
#include "Tile.h"

#define MAX_TILES 2

TileList::TileList()
{
	tileArray = gcnew array<Tile^>(MAX_TILES);
}

Bitmap^ TileList::GetTileBitmap(int tileIndex)
{
	Tile^ selectedTile = tileArray[tileIndex];
	return selectedTile->TileBitmap;
}

void TileList::SetTileArrayEntry(int tileIndex, Tile^ tileToEnter)
{
	tileArray[tileIndex] = tileToEnter;
}
