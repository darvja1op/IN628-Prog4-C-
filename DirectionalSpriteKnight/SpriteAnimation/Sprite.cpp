#include "Sprite.h"

#define MAX_DIRECTIONS 4

Sprite::Sprite(Graphics^ startCanvas, array<String^>^ startFileName, Random^ startRGen, int startNFrames)
{
	canvas = startCanvas;
	spriteSheets = gcnew array<Bitmap^>(MAX_DIRECTIONS);
	for (int i = 0; i < MAX_DIRECTIONS; i++)
	{
		spriteSheets[i] = gcnew Bitmap(startFileName[i]);
		spriteSheets[i]->MakeTransparent(spriteSheets[i]->GetPixel(0, 0));
	}

	velocityDirections = gcnew array<Point>(MAX_DIRECTIONS);
	velocityDirections[0] = Point(1, 0); //EAST
	velocityDirections[1] = Point(0, 1); //SOUTH
	velocityDirections[2] = Point(-1, 0); //WEST
	velocityDirections[3] = Point(0, -1); //NORTH

	rGen = startRGen;
	nFrames = startNFrames;

	currentFrame = rGen->Next(nFrames);
	
	xPos = rGen->Next(1000);
	yPos = rGen->Next(500);
	
	frameWidth = (spriteSheets[0]->Width / nFrames);
	frameHeight = spriteSheets[0]->Height;

	YVel = rGen->Next(10, 20);
	XVel = rGen->Next(4);

	SpriteDirection = EAST;
}
void Sprite::draw()
{
	int startX = currentFrame * frameWidth;
	int startY = 0;

	Rectangle drawRect = Rectangle(startX, startY, frameWidth, frameHeight);

	Bitmap^ currentBitmap = spriteSheets[SpriteDirection];

	canvas->DrawImage(currentBitmap, xPos, yPos, drawRect, GraphicsUnit::Pixel);

	System::Threading::Thread::Sleep(100);
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