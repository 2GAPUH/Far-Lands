#include "Tile.h"
#include "ResourceManager.h"

enum class GrassType { TOP_LEFT = 12, TOP_MIDDLE, TOP_RIGHT, DOWN_LEFT, DOWN_MIDDLE, DOWN_RIGHT, MIDDLE_LEFT, MIDDLE_RIGHT };

Tile::Tile(Type type, sf::Vector2i pos)
{
	rect.setPosition(pos.x * TILE_SIZE.x, pos.y * TILE_SIZE.y);
	rect.setSize(TILE_SIZE);
	
	if (type == Type::GRASS)
	{
        switch (pos.x) {
        case 2:
            switch (pos.y) {
            case 2:
                rect.setTextureRect(ResourceManager::GetInstance()->GetTextureRect(type, sf::Vector2i((int)GrassType::TOP_LEFT, 0) ));
                break;
            case 47:
                rect.setTextureRect(ResourceManager::GetInstance()->GetTextureRect(type, sf::Vector2i((int)GrassType::DOWN_LEFT, 0)));
                break;
            default:
                if (pos.y >= 3 && pos.y <= 46) 
                    rect.setTextureRect(ResourceManager::GetInstance()->GetTextureRect(type, sf::Vector2i((int)GrassType::MIDDLE_RIGHT, 0)));
                break;
            }
            break;
        case 47:
            switch (pos.y) {
            case 2:
                rect.setTextureRect(ResourceManager::GetInstance()->GetTextureRect(type, sf::Vector2i((int)GrassType::TOP_RIGHT, 0)));
                break;
            case 47:
                rect.setTextureRect(ResourceManager::GetInstance()->GetTextureRect(type, sf::Vector2i((int)GrassType::DOWN_RIGHT, 0)));
                break;
            default:
                if (pos.y >= 3 && pos.y <= 46) 
                    rect.setTextureRect(ResourceManager::GetInstance()->GetTextureRect(type, sf::Vector2i((int)GrassType::MIDDLE_LEFT, 0)));
                break;
            }
            break;
        default:
            if (pos.y == 2) 
                rect.setTextureRect(ResourceManager::GetInstance()->GetTextureRect(type, sf::Vector2i((int)GrassType::TOP_MIDDLE, 0)));
            else if (pos.y == 47) 
                rect.setTextureRect(ResourceManager::GetInstance()->GetTextureRect(type, sf::Vector2i((int)GrassType::DOWN_MIDDLE, 0)));
            else
                rect.setTextureRect(ResourceManager::GetInstance()->GetTextureRect(type));
            break;
        }
	}
	else
		rect.setTextureRect(ResourceManager::GetInstance()->GetTextureRect(type));
	rect.setTexture(ResourceManager::GetInstance()->GetTexture(type));
}

Tile::~Tile()
{
	if (obj != 0)
		delete obj;
	obj = nullptr;
}

void Tile::SetObject(ObjectType type)
{
    switch (type)
    {


    default:
        obj = new Object(type, rect.getPosition());
        break;
    }
}

void Tile::Draw(sf::RenderWindow* win)
{
	win->draw(rect);
	if(obj != nullptr)
		obj->Draw(win);
}

void Tile::Move(sf::Vector2f shift)
{
	rect.move(shift);
	if (obj != nullptr)
		obj->SetPosition(rect.getPosition());
}

sf::FloatRect Tile::GetObjBounds()
{
    if (obj != 0 && obj->GetCollision())
        return obj->GetCollisionRect();
    else
        throw("Object troubles");
}

bool Tile::CheckObject()
{
	if (obj == nullptr)
		return 0;
	return 1;
}

void Tile::Update()
{
    if(obj)
        obj->Update();
}

ObjectType Tile::GetObectType()
{
    if (obj == nullptr)
        return ObjectType::EMPTY;
    return obj->GetType();
}

void Tile::Touch()
{
    if (obj)
        obj->Touch();
}


