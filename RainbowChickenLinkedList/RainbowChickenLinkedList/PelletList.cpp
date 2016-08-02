#include "PelletList.h"


PelletList::PelletList()
{
	head = nullptr;
	tail = nullptr;
}

void PelletList::addPellet(Pellet^ newPellet)
{
	if (head == nullptr)
	{
		head = newPellet;
		tail = newPellet;
	}
	else
	{
		tail->Next = newPellet;
		tail = newPellet;
	}
}

void PelletList::deleteOnePellet(Pellet^ pelletToDelete)
{
	//if deleting first node
	if (head == pelletToDelete)
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
			head = pelletToDelete->Next;
		}
	}
	else
	{
		//find previous and swoop
		Pellet^ pelletWalker;
		pelletWalker = head;

		while (pelletWalker->Next != pelletToDelete)
		{
			pelletWalker = pelletWalker->Next;
		}
		
		pelletWalker->Next = pelletToDelete->Next;

		//if deleted last in list
		if (pelletWalker->Next == nullptr)
		{
			//set tail to point to previous node
			tail = pelletWalker;
		}
	}
}

void PelletList::deleteAllDeadPellets()
{
	Pellet^ pelletWalker;

	while (pelletWalker != nullptr)
	{
		//delete pellet if dead
		if (!pelletWalker->IsAlive)
		{
			deleteOnePellet(pelletWalker);
		}
		pelletWalker = pelletWalker->Next;
	}
}

void PelletList::movePellets()
{
	Pellet^ pelletWalker;

	while (pelletWalker != nullptr)
	{
		//move pellet
		pelletWalker->move();
		pelletWalker = pelletWalker->Next;
	}
}

void PelletList::drawPellets()
{
	Pellet^ pelletWalker;

	while (pelletWalker != nullptr)
	{
		//draw pellet
		pelletWalker->draw();
		pelletWalker = pelletWalker->Next;
	}
}

int PelletList::countPellets()
{
	Pellet^ pelletWalker;

	int count = 0;
	while (pelletWalker != nullptr)
	{
		count++;
		pelletWalker = pelletWalker->Next;
	}
	return count;
}

