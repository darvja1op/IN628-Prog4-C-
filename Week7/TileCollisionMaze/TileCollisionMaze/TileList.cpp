#include "TileList.h"

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
