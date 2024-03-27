#pragma once
#include "Object.h"

class Log : public Object
{
public:
	Log(sf::Vector2f pos);
	~Log();
	bool Touch(ItemType type) override;
	void Update() override;
	ObjectType GetType() override;
};

