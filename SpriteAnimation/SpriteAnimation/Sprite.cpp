#include "Sprite.h"


Sprite::Sprite(Graphics^ startCanvas, Bitmap^ startSpriteSheet, Random^ startRGen, int startNFrames)
{
	canvas = startCanvas;
	spriteSheet = startSpriteSheet;
	rGen = startRGen;
	nFrames = startNFrames;

	currentFrame = rGen->Next(nFrames);
	
	xPos = rGen->Next(200);
	yPos = rGen->Next(200);
	
	frameWidth = (spriteSheet->Width / nFrames);
	frameHeight = spriteSheet->Height;

	yVel = rGen->Next(10, 20);
	xVel = rGen->Next(4);
}
void Sprite::draw()
{

}
void Sprite::move()
{

}
void Sprite::wander()
{

}
void Sprite::erase(Color eraseColour)
{

}
void Sprite::updateFrame()
{

}
void Sprite::setSpriteSheet(Bitmap^ newSpriteSheet, int newNFrames)
{

}