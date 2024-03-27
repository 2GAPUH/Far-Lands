#pragma once
#include "Object.h"


class Stump : public Object
{
public:
	Stump(sf::Vector2f pos);
	~Stump();
	bool Touch(ItemType type) override;
	void Update() override;
	ObjectType GetType() override;
};

