#include "GnomeFamily.h"


GnomeFamily::GnomeFamily(Random^ startRandom, Graphics^ startCanvas, int startNGnomes)
{
	rGen = startRandom;
	canvas = startCanvas;
	nGnomes = startNGnomes;
	gnomeArray = gcnew array<Gnome^>(nGnomes);

	for (int i = 0; i < nGnomes; i++)
	{
		int newX = rGen->Next(100, 700);
		int newY = rGen->Next(100, 700);
		gnomeArray[i] = gcnew Gnome(canvas, newX, newY);
	}
}

void GnomeFamily::drawAllGnomes()
{
	for (int i = 0; i < gnomeArray->Length; i++)
	{
		gnomeArray[i]->draw();
	}
}

void GnomeFamily::drawOneGnome(int gnomeIndex)
{
	gnomeArray[gnomeIndex]->draw();
}

void GnomeFamily::eraseAllGnomes()
{
	for (int i = 0; i < gnomeArray->Length; i++)
	{
		gnomeArray[i]->erase();
	}
}

void GnomeFamily::eraseOneGnome(int gnomeIndex)
{
	gnomeArray[gnomeIndex]->erase();
}

bool GnomeFamily::hitGnome(int gnomeIndex, int x, int y)
{
	return gnomeArray[gnomeIndex]->pointInGnome(x, y);
}

void GnomeFamily::changeGnomeImage(int gnomeIndex, String^ newImageFileName)
{
	gnomeArray[gnomeIndex]->changeImage(newImageFileName);
}

void GnomeFamily::setToHamster(int gnomeIndex)
{
	gnomeArray[gnomeIndex]->setIsHamster(true);
}

void GnomeFamily::resetAllGnomes()
{
	for (int i = 0; i < gnomeArray->Length; i++)
	{
		gnomeArray[i]->setIsHamster(false);
		gnomeArray[i]->erase();
		gnomeArray[i]->changeImage("images\\gnome.jpg");
	}
}