#pragma once
#include "Storage.h"


class Inventory :public Storage
{
	sf::RectangleShape rectBar;
	sf::RectangleShape rectCurElem;
	sf::Vector2f downPosSub = {0., 0.};
	int curElem = 0;
	int cutLine = 0;

public:
	void Draw(sf::RenderWindow* win, sf::Vector2f pos) override;
	void EditCurLine();
	void EditCurElem(int i);
	Type GetCurType();
	void ReduceCurElem();
	Inventory();
	~Inventory();
};

