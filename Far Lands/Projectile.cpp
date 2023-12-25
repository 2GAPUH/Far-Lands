#include "Projectile.h"
#include "EntityManager.h"
#include "Enemy.h"

void Projectile::UpdateMovementVector(sf::Vector2f pos, sf::Vector2f aim)
{
    sf::Vector2f direction = aim - pos;

    sf::Vector2f unitVector = direction / std::sqrt(direction.x * direction.x + direction.y * direction.y);

    movementVector = unitVector * speed;

    angle = std::atan2(movementVector.y, movementVector.x) * (180.0f / 3.14159f);
}

Projectile::Projectile(Type type, sf::Vector2f pos, sf::Vector2f aim) : Entity(type, pos)
{
    switch (type)
    {
    case Type::ARROW:
        speed = ARROW_SPEED;
        rect.setSize(ARROW_SIZE);
        DMG = ARROW_DMG;
        break;
    }

    UpdateMovementVector(pos, aim);
    rect.setRotation(angle);
}

Projectile::~Projectile()
{

}

void Projectile::Update()
{
    rect.move(movementVector);

    for (Entity* enities : EntityManager::GetInstance()->vect)
    {
        if (Enemy* enemy = dynamic_cast<Enemy*>(enities))
            if (enemy->GetBounds().intersects(rect.getGlobalBounds()))
            {
                EntityManager::GetInstance()->AddInDestroyList(ID);
                enemy->Punch(DMG);
                return;
            }

    }

    sf::Vector2f pos = rect.getPosition();
    if(pos.x < 0 || pos.y < 0 || pos.x > TILE_SIZE.x * MAP_SIZE.x || pos.y > TILE_SIZE.y * MAP_SIZE.y)
        EntityManager::GetInstance()->AddInDestroyList(ID);
   
}
