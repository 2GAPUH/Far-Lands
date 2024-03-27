#pragma once
#include "Object.h"
#include "Animation.h"

class Campfire : public Object
{
	Animation* animation = nullptr;
	StatusType status = StatusType::ENABLE;

public:
	Campfire(sf::Vector2f pos);
	~Campfire();
	void Touch() override;
	void Update() override;
	ObjectType GetType() override;
	void Draw(sf::RenderWindow* win) override;
};

