#include "TileMap.h"

TileMap::TileMap(TileList^ startTileList, Graphics^ startCanvas)
{
	gardenTiles = startTileList;
	canvas = startCanvas;
	map = gcnew array<int, 2>(MAP_COLS, MAP_ROWS);
}

Bitmap^ TileMap::GetMapEntry(int col, int row)
{
	int currTileIndex = map[col, row];
	return gardenTiles->GetTileBitmap(currTileIndex);
}

void TileMap::DrawMap()
{
	int drawLocX;
	int drawLocY;
	int currentTileIndex;
	Bitmap^ currentTileBitmap;
	Bitmap^ sampleTile = gardenTiles->GetTileBitmap(0);
	int tileWidth = sampleTile->Width;
	int tileHeight = sampleTile->Height;

	for (int columns = 0; columns < MAP_COLS; columns++)
	{
		for (int rows = 0; rows < MAP_ROWS; rows++)
		{
			drawLocX = columns * tileWidth;
			drawLocY = rows * tileHeight;

			currentTileIndex = map[columns, rows];
			currentTileBitmap = gardenTiles->GetTileBitmap(currentTileIndex);

			canvas->DrawImage(currentTileBitmap, drawLocX, drawLocY);
		}
	}
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

void TileMap::LoadRandomMap(int numDifferentTiles)
{
	Random^ rGen = gcnew Random();
	
	for (int columns = 0; columns < MAP_COLS; columns++)
	{
		for (int rows = 0; rows < MAP_ROWS; rows++)
		{
			map[columns, rows] = rGen->Next(numDifferentTiles);
		}
	}
}

void TileMap::SetMapEntry(int col, int row, int tileIndex)
{

}