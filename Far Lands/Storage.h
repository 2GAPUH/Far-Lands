#pragma once
#include "ItemInStorage.h"
#include "BaseValue.h"

class Storage
{
private:
	ItemInStorage*** storage = nullptr;
	bool open = false;
	sf::RectangleShape rect;

public:
	Storage();
	~Storage();
	void Open();
	void Draw(sf::RenderWindow* win);
	void Move(sf::Vector2f shift);
	int PutItemAuto(Type type, int count);
};

