#pragma once
#include "Object.h"
#include "Animation.h"

class Campfire : public Object
{
	Animation* animation = nullptr;
	StatusType status = StatusType::ENABLE;
	sf::Clock clock;
	float burningTime = CAMFIRE_BURNING_TIME;
	sf::FloatRect activeRect;

public:
	Campfire(sf::Vector2f pos);
	~Campfire();
	bool Touch(ItemType type) override;
	void Update() override;
	ObjectType GetType() override;
	void Draw(sf::RenderWindow* win) override;
};

