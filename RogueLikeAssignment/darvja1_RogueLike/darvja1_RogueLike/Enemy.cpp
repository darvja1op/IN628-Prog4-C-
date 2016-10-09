#include "Enemy.h"


Enemy::Enemy(Graphics^ startCanvas, array<String^>^ startFileNames, int startNFrames, int startHealth)
: Sprite(startCanvas, startFileNames, startNFrames)
{
	health = startHealth;
}

