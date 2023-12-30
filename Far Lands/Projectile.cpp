#include "Projectile.h"


void Projectile::UpdateMovementVector(sf::Vector2f pos, sf::Vector2f aim)
{
    sf::Vector2f direction = aim - pos;

    sf::Vector2f unitVector = direction / std::sqrt(direction.x * direction.x + direction.y * direction.y);

    movementVector = unitVector * speed;

    angle = std::atan2(movementVector.y, movementVector.x) * (180.0f / 3.14159f);
}

void Projectile::SetValues(Type type)
{
    switch (type)
    {
    case Type::ARROW:
        speed = ARROW_SPEED;
        rect.setSize(ARROW_SIZE);
        DMG = ARROW_DMG;
        break;
    }
}

Projectile::Projectile(Type type, sf::Vector2f pos, sf::Vector2f aim) : Entity(type, pos)
{
    collision = true;
    SetValues(type);
    UpdateMovementVector(pos, aim);
    rect.setRotation(angle);
}

Projectile::~Projectile()
{
}
