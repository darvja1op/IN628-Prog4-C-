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
		int obstacleIndex = FindNearIndex(obstaclesInWorld);
		if (obstacleIndex != -1)
		{
			creatureState = ORIENTING;
		}
		

		//if food in range then change to EATING
		int foodIndex = FindNearIndex(foodInWorld);
		if (foodIndex != -1)
		{
			creatureState = EATING;
		}

		if (wanderingTicks % wanderingTime == 0)
		{
			creatureState = ORIENTING;
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
	}
}
void Creature::PerformAction()
{
	switch (creatureState)
	{
	case WANDERING:
		Move();
		wanderingTicks++;
		break;
	case EATING:
		radius++;
		eatingTicks++;
		break;
	case ORIENTING:
		ChangeRandomdirection();
		break;
	}
}


int Creature::FindNearIndex(array<Thing^>^ otherGuys)
{
	int index = -1;
	for (int i = 0; i < otherGuys->Length;i++)
	{
		double distance = ComputeDistance(otherGuys[i]);
		if (distance < sensingRange)
		{
			location.X -= direction.X;
			location.Y -= direction.Y;

			index = i;
		}
	}
	return index;
}