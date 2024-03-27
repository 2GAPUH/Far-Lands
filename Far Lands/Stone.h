#pragma once
#include "Object.h"
class Stone : public Object
{
public:
	Stone(sf::Vector2f pos);
	~Stone();
	bool Touch(ItemType type) override;
	void Update() override;
	ObjectType GetType() override;

};

