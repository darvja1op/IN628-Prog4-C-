#pragma once

#include "Pellet.h"

ref class PelletList
{
private:
	Pellet^ head;
	Pellet^ tail;
public:
	PelletList(void);
	void addPellet(Pellet^ newPellet);
	void deleteOnePellet(Pellet^ pelletToDelete);
	void deleteAllDeadPellets();
	void movePellets();
	void drawPellets();
	int countPellets();
	void erasePellets();
};

