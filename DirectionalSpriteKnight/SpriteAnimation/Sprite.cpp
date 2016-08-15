#include "Sprite.h"


Sprite::Sprite(Graphics^ startCanvas, String^ startSpriteSheet, Random^ startRGen, int startNFrames)
{
	canvas = startCanvas;
	spriteSheet = gcnew Bitmap(startSpriteSheet);

	Color transparentColour = spriteSheet->GetPixel(0, 0);
	spriteSheet->MakeTransparent(transparentColour);

	rGen = startRGen;
	nFrames = startNFrames;

	currentFrame = rGen->Next(nFrames);
	
	xPos = rGen->Next(1000);
	yPos = rGen->Next(500);
	
	frameWidth = (spriteSheet->Width / nFrames);
	frameHeight = spriteSheet->Height;

	yVel = rGen->Next(10, 20);
	xVel = rGen->Next(4);
}
void Sprite::draw()
{
	int startX = currentFrame * frameWidth;
	int startY = 0;

	Rectangle drawRect = Rectangle(startX, startY, frameWidth, frameHeight);

	canvas->DrawImage(spriteSheet, xPos, yPos, drawRect, GraphicsUnit::Pixel);

	System::Threading::Thread::Sleep(100);
	Application::DoEvents();
}
void Sprite::move()
{
	xPos += xVel;
	yPos += yVel;
}
void Sprite::wander()
{
	//random chance of changing X direction
	int xProbabilityChance = rGen->Next(5);
	if (xProbabilityChance == 0)
	{
		xVel *= -1;
	}
	//random chance of changing Y direction
	int yProbabilityChance = rGen->Next(5);
	if (yProbabilityChance == 0)
	{
		yVel *= -1;
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
void Sprite::setSpriteSheet(Bitmap^ newSpriteSheet, int newNFrames)
{
	nFrames = newNFrames;
	spriteSheet = newSpriteSheet;

	frameHeight = spriteSheet->Height;
	frameWidth = spriteSheet->Width / nFrames;
}