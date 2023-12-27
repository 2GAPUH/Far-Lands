#pragma once
#include "ItemInStorage.h"
#include "BaseValue.h"

class Storage
{
protected:
	ItemInStorage*** storage = nullptr;
	bool open = false;
	sf::RectangleShape mainRect;
	sf::Vector2f middlePos;
	sf::Vector2f topPos;
	sf::Vector2f downPos;

public:
	Storage();
	~Storage();
	void Open();
	virtual void Draw(sf::RenderWindow* win, sf::Vector2f pos);
	int PutItemAuto(Type type, int count);
};

