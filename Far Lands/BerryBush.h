#pragma once
#include "Object.h"

class BerryBush : public Object
{
private:
	sf::Clock clock;
	bool ready = false;

public:
	BerryBush(sf::Vector2f pos);
	~BerryBush();
	void Touch() override;
	void Update() override;
	ObjectType GetType() override;
};

