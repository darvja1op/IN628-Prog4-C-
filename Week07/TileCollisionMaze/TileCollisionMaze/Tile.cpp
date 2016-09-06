#include "Tile.h"


Tile::Tile(Bitmap^ startTileBitmap, bool startIsWalkable)
{
	TileBitmap = startTileBitmap;
	IsWalkable = startIsWalkable;
}
