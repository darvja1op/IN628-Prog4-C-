#include "Sprite.h"

Sprite::Sprite(Graphics^ startCanvas, array<String^>^ startFileNames, Random^ startRGen, int startNFrames, Rectangle startBoundingArea)
{
	canvas = startCanvas;
	spriteSheets = gcnew array<Bitmap^>(MAX_DIRECTIONS);
	for (int i = 0; i < MAX_DIRECTIONS; i++)
	{
		spriteSheets[i] = gcnew Bitmap(startFileNames[i]);
		Color transparentColour = spriteSheets[i]->GetPixel(0, 0);
		spriteSheets[i]->MakeTransparent();
	}

	BoundingArea = startBoundingArea;
	BoundsAction = WRAP;

	IsAlive = true;

	velocityDirections = gcnew array<Point>(MAX_DIRECTIONS);
	velocityDirections[EAST] = Point(1, 0); //EAST
	velocityDirections[SOUTH] = Point(0, 1); //SOUTH
	velocityDirections[WEST] = Point(-1, 0); //WEST
	velocityDirections[NORTH] = Point(0, -1); //NORTH

	rGen = startRGen;
	nFrames = startNFrames;

	currentFrame = rGen->Next(nFrames);
	
	xPos = rGen->Next(50,800);
	yPos = rGen->Next(50,600);
	
	frameWidth = (spriteSheets[0]->Width / nFrames);
	frameHeight = spriteSheets[0]->Height;

	YVel = rGen->Next(7, 20);
	XVel = rGen->Next(7, 20);

	SpriteDirection = EAST;
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

	if ((xPos < BoundingArea.Left) || ((xPos+frameWidth) > BoundingArea.Right) ||
		(yPos < BoundingArea.Top) || (yPos + frameHeight > BoundingArea.Bottom))
	{
		//run bounds action
		switch (BoundsAction)
		{
		case BOUNCE:
			bounce();
			break;
		case DIE:
			die();
			break;
		case WRAP:
			wrap();
			break;
		case STOP:
			stop();
			break;
		default:
			break;
		}
	}
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

void Sprite::wrap()
{
	if (SpriteDirection == EAST)
	{
		xPos = BoundingArea.Left;
	}
	if (SpriteDirection == WEST)
	{
		xPos = BoundingArea.Right+frameWidth;
	}
	if (SpriteDirection == NORTH)
	{
		yPos = BoundingArea.Bottom + frameWidth;
	}
	if (SpriteDirection == SOUTH)
	{
		yPos = BoundingArea.Top + frameWidth;
	}
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