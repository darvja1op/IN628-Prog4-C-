#include "Thing.h"

Thing::Thing()
{

}
Thing::Thing(Graphics^ startcanvas, Random^ startRandom, int startWorldWidth, int startWorldHeight, String^ imageFileName)
{
	canvas = startcanvas;
	rGen = startRandom;
	worldWidth = startWorldWidth;
	worldHeight = startWorldHeight;
	thingImage = gcnew Bitmap(imageFileName);
}

void Thing::Move()
{
	location.X += direction.X;
	location.Y += direction.Y;
}
void Thing::ChangeRandomdirection()
{
	double angle = rGen->Next(360) * 0.01745;

	direction.X = (int)(Math::Cos(angle) * speed);
	direction.Y = (int)(Math::Sin(angle) * speed);
}
void Thing::Draw()
{
	canvas->DrawImage(thingImage, location);
}
void Thing::PointMeAt(int newX, int newY)
{
	double xDelta = newX - location.X;
	double yDelta = newY - location.Y;

	double angleToTarget = Math::Atan2(yDelta, xDelta);

	direction.X = Math::Cos(angleToTarget) * speed;
	direction.Y = Math::Sin(angleToTarget) * speed;
}
double Thing::ComputeDistance(Thing^ otherGuy)
{
	double xDelta = otherGuy->location.X - location.X;
	double yDelta = otherGuy->location.Y - location.Y;

	double totalDistance = xDelta + yDelta;

	return totalDistance;
}