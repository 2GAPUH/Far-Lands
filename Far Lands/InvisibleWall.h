#pragma once
#include "Object.h"

class InvisibleWall : public Object
{
public:
	InvisibleWall(sf::Vector2f pos);
	~InvisibleWall();
	bool Touch(ItemType type) override;
	void Update() override;
	ObjectType GetType() override;
};