#pragma once
#include "BaseValue.h"

class ItemInStorage
{
private:
	int count = 0;
	Type type;
	sf::Texture* texture = nullptr;
};

