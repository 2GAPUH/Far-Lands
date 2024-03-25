#pragma once
#include "Object.h"


class Stump : public Object
{
public:
	Stump(sf::Vector2f pos);
	~Stump();
	void Touch() override;
	void Update() override;
	ObjectType GetType() override;
};

