#include "Arrow.h"

Arrow::Arrow(sf::Vector2f pos, sf::Vector2f aim) : Projectile(ProjectileType::ARROW, pos, aim)
{

}

Arrow::~Arrow()
{
}
