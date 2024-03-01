#pragma once
#include "ItemInStorage.h"
#include "BaseValue.h"

class Storage
{
protected:
	ItemInStorage*** storage = nullptr;
	bool open = false;
	sf::RectangleShape rectStorage;
	sf::Vector2f middlePos;
	sf::Vector2f topPos;
	sf::Vector2f downPos;
	virtual sf::Vector2i GetCurCell(sf::Vector2i mousePos);
	static sf::Vector2f constShift;

public:
	Storage();
	~Storage();
	void Open();
	virtual void Draw(sf::RenderWindow* win, sf::Vector2f pos);
	int PutItemAuto(ItemType type, int count);
	void Move(sf::Vector2i start, sf::Vector2i end);
	void Update(sf::RenderWindow* win);
};

