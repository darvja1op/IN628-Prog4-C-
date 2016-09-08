#pragma once
#include "SimpleSprite.h"
ref class Approacher :
public SimpleSprite
{
public:
	Approacher(Graphics^ offScreenCanvas, Bitmap^ redShipBitmap, int shipFrames, Random^ rGen, int shipSpeed, Rectangle backgroundRectangle);

	virtual void orient(SimpleSprite^ target) override;
};

