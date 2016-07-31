#include "Gnome.h"


Gnome::Gnome(Graphics^ startCanvas, int startXPos, int startYPos)
{
	canvas = startCanvas;
	xPos = startXPos;
	yPos = startYPos;
	isHamster = false;
	image = Image::FromFile("gnome.jpg");
}

void Gnome::draw()
{
	canvas->DrawImage(image, xPos, yPos);
}

void Gnome::erase()
{
	Pen^ pen = gcnew Pen(Color::White);
	canvas->DrawRectangle(pen, xPos, yPos, image->Width, image->Height);
}

bool Gnome::pointInGnome(int x, int y)
{
	bool hit = false;
	if (x >= xPos)
	{
		if (x <= (xPos+image->Width))
		{
			if (y >= yPos)
			{
				if (y <= (yPos+image->Height))
				{
					hit = true;
				}
			}
		}
	}
	return hit;
}

void Gnome::changeImage(String^ newFile)
{
	image = Image::FromFile(newFile);
}