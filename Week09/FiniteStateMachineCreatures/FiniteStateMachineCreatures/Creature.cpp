#include "Creature.h"

Creature::Creature(Graphics^ startcanvas, Random^ startRandom, int startworldWidth, int startworldHeight, String^ imageFileName)
: Thing(startcanvas, startRandom, startworldWidth, startworldHeight, imageFileName)
{
}

// FSM Methods
void Creature::UpdateState(array<Thing^>^ foodInWorld, array<Thing^>^ obstaclesInWorld)
{
	switch (creatureState)
	{
	case WANDERING:
		//if obstacle in range then reverse, change state to ORIENTING
		for each (Thing^ obstacle in obstaclesInWorld)
		{
			double distance = ComputeDistance(obstacle);
			if (distance < sensingRange)
			{
				location.X -= direction.X;
				location.Y -= direction.Y;
				creatureState = ORIENTING;
			}
		}
		

		//if food in range then change to EATING
		for each (Thing^ food in foodInWorld)
		{
			double distance = ComputeDistance(food);
			if (distance < sensingRange)
			{
				creatureState = EATING;
			}
		}
		break;
	case EATING:
		//stay in eating for fixed num ticks then change to WANDERING
		if (eatingTicks % eatingTime == 0)
		{
			creatureState = WANDERING;
		}
		break;
	case ORIENTING:
		//change state to WANDERING
		creatureState = WANDERING;
		break;
	default:
		break;
	}
}
void Creature::PerformAction()
{
	switch (creatureState)
	{
	case WANDERING:
		Move();
		break;
	case EATING:
		radius++;
		eatingTicks++;
		break;
	case ORIENTING:
		ChangeRandomdirection();
		break;
	default:
		break;
	}
}


int Creature::FindNearIndex(array<Thing^>^ otherGuys)
{

}