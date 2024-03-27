#pragma once
#include "Object.h"

class FarmerPlanted : public Object
{
public:
	FarmerPlanted(sf::Vector2f pos);
	~FarmerPlanted();
	bool Touch(ItemType type) override;
	void Update() override;
	ObjectType GetType() override;
};

