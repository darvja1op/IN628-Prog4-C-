#include "Sprite.h"

Sprite::Sprite(Graphics^ startCanvas, array<String^>^ startFileNames, int startNFrames)
{
	canvas = startCanvas;
	spriteSheets = gcnew array<Bitmap^>(MAX_DIRECTIONS);
	for (int i = 0; i < MAX_DIRECTIONS; i++)
	{
		spriteSheets[i] = gcnew Bitmap(startFileNames[i]);
		Color transparentColour = spriteSheets[i]->GetPixel(0, 0);
		spriteSheets[i]->MakeTransparent();
	}

	IsAlive = true;

	velocityDirections = gcnew array<Point>(MAX_DIRECTIONS);
	velocityDirections[EAST] = Point(1, 0); //EAST
	velocityDirections[SOUTH] = Point(0, 1); //SOUTH
	velocityDirections[WEST] = Point(-1, 0); //WEST
	velocityDirections[NORTH] = Point(0, -1); //NORTH

	nFrames = startNFrames;

	currentFrame = 0;
	
	xPos = 62;
	yPos = 62;
	
	frameWidth = (spriteSheets[0]->Width / nFrames);
	frameHeight = spriteSheets[0]->Height;

	SpriteDirection = EAST;

	ProportionReduction = 0.8;
}
void Sprite::draw()
{
	int startX = currentFrame * frameWidth;
	int startY = 0;

	Rectangle drawRect = Rectangle(startX, startY, frameWidth, frameHeight);

	Bitmap^ currentBitmap = spriteSheets[SpriteDirection];

	canvas->DrawImage(currentBitmap, xPos, yPos, drawRect, GraphicsUnit::Pixel);
	Application::DoEvents();
}
void Sprite::move()
{
	xPos += XVel * velocityDirections[SpriteDirection].X;
	yPos += YVel * velocityDirections[SpriteDirection].Y;
}
void Sprite::erase(Color eraseColour)
{
	SolidBrush^ eraseBrush = gcnew SolidBrush(eraseColour);
	canvas->FillRectangle(eraseBrush, xPos, yPos, frameWidth, frameHeight);
}
void Sprite::updateFrame()
{
	currentFrame = (currentFrame + 1) % nFrames;
}

void Sprite::bounce()
{
	//change sprite direction
	SpriteDirection = (SpriteDirection + 2) % MAX_DIRECTIONS;
}

void Sprite::die()
{
	IsAlive = false;
}

void Sprite::stop()
{
	//set velocities to 0 so the Sprite no longer moves
	XVel = 0;
	YVel = 0;
}

bool Sprite::IsLegalMove(TileMap^ tileMap)
{
	int newxPos = xPos + XVel * velocityDirections[SpriteDirection].X;
	int newyPos = yPos + YVel * velocityDirections[SpriteDirection].Y;

	int directionCornerX;
	int directionCornerY;

	switch (SpriteDirection)
	{
	case NORTH:
		directionCornerX = newxPos;
		directionCornerY = newyPos;
		break;
	case SOUTH:
		directionCornerX = newxPos;
		directionCornerY = newyPos + frameHeight;
		break;
	case WEST:
		directionCornerX = newxPos;
		directionCornerY = newyPos + frameHeight;
		break;
	case EAST:
		directionCornerX = newxPos + frameWidth;
		directionCornerY = newyPos + frameHeight;
		break;
	default:
		break;
	}

	int column = directionCornerX / TILE_SIDE;
	int row = directionCornerY / TILE_SIDE;

	return tileMap->isTileWalkable(column, row);
}

bool Sprite::CollidedWithMe(Sprite^ otherSprite)
{
	bool collided = true;

	int sprite1BottomEdge, sprite1TopEdge, sprite1LeftEdge, sprite1RightEdge;
	int sprite2BottomEdge, sprite2TopEdge, sprite2LeftEdge, sprite2RightEdge;

	sprite1BottomEdge = yPos + frameHeight - (frameHeight * ProportionReduction);
	sprite1TopEdge = yPos + (frameHeight * ProportionReduction);
	sprite1LeftEdge = xPos + (frameWidth * ProportionReduction);
	sprite1RightEdge = xPos + frameWidth - (frameWidth * ProportionReduction);

	sprite2BottomEdge = otherSprite->yPos + frameHeight - (frameHeight * ProportionReduction);
	sprite2TopEdge = otherSprite->yPos + (frameHeight * ProportionReduction);
	sprite2LeftEdge = otherSprite->xPos + (frameWidth * ProportionReduction);
	sprite2RightEdge = otherSprite->xPos + frameWidth - (frameWidth * ProportionReduction);

	if (sprite1BottomEdge < sprite2BottomEdge)
	{
		collided = false;
	}
	if (sprite1TopEdge < sprite2TopEdge)
	{
		collided = false;
	}
	if (sprite1LeftEdge < sprite2LeftEdge)
	{
		collided = false;
	}
	if (sprite1RightEdge < sprite2RightEdge)
	{
		collided = false;
	}

	return collided;
}