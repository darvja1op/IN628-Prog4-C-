#include "TileMap.h"

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

void TileMap::LoadMapFromFile(String^ mapFileName)
{
	StreamReader^ sr = File::OpenText(mapFileName);

	String^ currentLine = "";
	array<String^>^ indexHolder = gcnew array<String^>(MAP_COLS);

	int rowCounter = 0;

	while (currentLine = sr->ReadLine())
	{
		indexHolder = currentLine->Split(',');
		for (int columnCounter = 0; columnCounter < MAP_COLS; columnCounter++)
		{
			int indexValue = Convert::ToInt16(indexHolder[columnCounter]);
			map[columnCounter, rowCounter] = indexValue;
		}
		rowCounter++;
	}
}