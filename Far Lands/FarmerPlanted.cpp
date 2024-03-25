#include "FarmerPlanted.h"

void FarmerPlanted::Update()
{
}

ObjectType FarmerPlanted::GetType()
{
	return ObjectType::FARMER_PLANTED;
}

FarmerPlanted::FarmerPlanted(sf::Vector2f pos) : Object (ObjectType::FARMER_PLANTED, pos)
{
	collision = false;
}

FarmerPlanted::~FarmerPlanted()
{
}

void FarmerPlanted::Touch()
{
}
