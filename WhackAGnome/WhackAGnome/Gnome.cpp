#include "Gnome.h"


Gnome::Gnome(Graphics^ startCanvas, int startXPos, int startYPos)
{
	canvas = startCanvas;
	xPos = startXPos;
	yPos = startYPos;
	isHamster = false;
	image = Image::FromFile("images\\gnome.jpg");
}

void Gnome::draw()
{
	canvas->DrawImage(image, xPos, yPos);
}

void Gnome::erase()
{
	Brush^ brush = gcnew SolidBrush(Color::LightGreen);
	canvas->FillRectangle(brush, xPos, yPos, image->Width, image->Height);
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