#pragma once
#include "Object.h"
class Campfire : public Object
{
public:
	Campfire(sf::Vector2f pos);
	~Campfire();
	void Touch() override;
	void Update() override;
	ObjectType GetType() override;
};

