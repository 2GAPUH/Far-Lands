#pragma once
#include "Object.h"

class InvisibleWall : public Object
{
public:
	InvisibleWall(sf::Vector2f pos);
	~InvisibleWall();
	void Touch() override;
	void Update() override;
	ObjectType GetType() override;
};