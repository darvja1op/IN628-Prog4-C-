#pragma once

#include "Sprite.h"

ref class SpriteList
{
private:
	Sprite^ head;
	Sprite^ tail;
public:
	SpriteList(void);
	void addSprite(Sprite^ newSprite);
	void deleteOneSprite(Sprite^ spriteToDelete);
	void moveSprites();
	void drawSprites();
	int countSprites();
	void eraseSprites();
	void updateSprites();
};

