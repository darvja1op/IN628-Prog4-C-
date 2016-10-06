#include "Hero.h"


Hero::Hero(Graphics^ startCanvas, array<String^>^ startFileNames, int startNFrames, int startHealth)
: Sprite(startCanvas, startFileNames, startNFrames)
{
	health = startHealth;
}
