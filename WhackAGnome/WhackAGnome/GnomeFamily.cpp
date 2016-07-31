#include "GnomeFamily.h"


GnomeFamily::GnomeFamily(Random^ startRandom, Graphics^ startCanvas, int startNGnomes)
{
	rGen = startRandom;
	canvas = startCanvas;
	nGnomes = startNGnomes;
	gnomeArray = gcnew array<Gnome^>(nGnomes);

	for (int i = 0; i < nGnomes; i++)
	{
		int newX = rGen->Next(10, 750);
		int newY = rGen->Next(10, 550);
		gnomeArray[i] = gcnew Gnome(canvas, newX, newY);
	}
}
