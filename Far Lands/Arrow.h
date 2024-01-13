#pragma once
#include "Projectile.h"

class Arrow : public Projectile
{
public:
	Arrow(sf::Vector2f pos, sf::Vector2f aim);
	~Arrow();
};

