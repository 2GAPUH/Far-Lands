#pragma once
#include "BaseValue.h"

class ItemInStorage
{
private:
	int count = 0;
	ItemType type;
	sf::Texture* texture = nullptr;
	sf::RectangleShape rect;
	sf::Text text;
	void UpdateText();

public:
	ItemInStorage();
	~ItemInStorage();
	void Draw(sf::RenderWindow* win, sf::Vector2f pos);
	ItemType GetItemType();
	void ReduceItem();
	int PutItem(ItemType type, int count);
};

