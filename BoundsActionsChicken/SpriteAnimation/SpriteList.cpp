#include "SpriteList.h"


SpriteList::SpriteList()
{
	head = nullptr;
	tail = nullptr;
}

void SpriteList::addSprite(Sprite^ newSprite)
{
	if (head == nullptr)
	{
		head = newSprite;
		tail = newSprite;
	}
	else
	{
		tail->Next = newSprite;
		tail = newSprite;
	}
}

void SpriteList::deleteOneSprite(Sprite^ SpriteToDelete)
{
	//if deleting first node
	if (head == SpriteToDelete)
	{
		//if only node in list
		if (head == tail)
		{
			//head and tail become nullptr
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			//move head along to second node
			head = SpriteToDelete->Next;
		}
	}
	else
	{
		//find previous and swoop
		Sprite^ SpriteWalker;
		SpriteWalker = head;

		while (SpriteWalker->Next != SpriteToDelete)
		{
			SpriteWalker = SpriteWalker->Next;
		}
		
		SpriteWalker->Next = SpriteToDelete->Next;

		//if deleted last in list
		if (SpriteWalker->Next == nullptr)
		{
			//set tail to point to previous node
			tail = SpriteWalker;
		}
	}
}

void SpriteList::moveSprites()
{
	Sprite^ SpriteWalker;
	SpriteWalker = head;

	while (SpriteWalker != nullptr)
	{
		//move Sprite
		SpriteWalker->move();
		SpriteWalker = SpriteWalker->Next;
	}
}
void SpriteList::drawSprites()
{
	Sprite^ SpriteWalker;
	SpriteWalker = head;

	while (SpriteWalker != nullptr)
	{
		if (SpriteWalker->IsAlive)
		{
			//draw Sprite
			SpriteWalker->draw();
			SpriteWalker = SpriteWalker->Next;
		}		
	}
}
void SpriteList::updateSprites()
{
	Sprite^ SpriteWalker;
	SpriteWalker = head;

	while (SpriteWalker != nullptr)
	{
		//draw Sprite
		SpriteWalker->updateFrame();
		SpriteWalker = SpriteWalker->Next;
	}
}


int SpriteList::countSprites()
{
	Sprite^ SpriteWalker;
	SpriteWalker = head;

	int count = 0;
	while (SpriteWalker != nullptr)
	{
		count++;
		SpriteWalker = SpriteWalker->Next;
	}
	return count;
}

void SpriteList::eraseSprites()
{
	Sprite^ SpriteWalker;
	SpriteWalker = head;

	while (SpriteWalker != nullptr)
	{
		SpriteWalker->erase(Color::Black);
		SpriteWalker = SpriteWalker->Next;
	}
}