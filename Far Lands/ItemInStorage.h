#pragma once
#include "BaseValue.h"

class ItemInStorage
{
private:
	int count = 0;
	Type type;
	sf::Texture* texture = nullptr;
	sf::RectangleShape rect;
	sf::Text text;
	void UpdateText();

public:
	ItemInStorage();
	~ItemInStorage();
	void Draw(sf::RenderWindow* win, sf::Vector2f pos);
	Type GetItemType();
	int PutItem(Type type, int count);
};

