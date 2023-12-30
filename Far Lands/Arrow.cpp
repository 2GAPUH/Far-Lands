#include "Arrow.h"


void Arrow::Update()
{
    Move();
    UpdateTilePos();
}

Arrow::Arrow(sf::Vector2f pos, sf::Vector2f aim) : Projectile(Type::ARROW, pos, aim)
{
    speed = ARROW_SPEED;
    rect.setSize(ARROW_SIZE);
    DMG = ARROW_DMG;
}
