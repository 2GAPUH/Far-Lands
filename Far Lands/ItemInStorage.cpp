
#include "ItemInStorage.h"
#include "ResourceManager.h"

ItemInStorage::ItemInStorage()
{
	rect.setSize(STORAGE_CELL);
	type = Type::EMPTY;
}

ItemInStorage::~ItemInStorage()
{
}

void ItemInStorage::Draw(sf::RenderWindow* win, sf::Vector2f pos)
{
	if(type != Type::EMPTY)
	{
		rect.setPosition(pos);
		win->draw(rect);
	}
}

Type ItemInStorage::GetItemType()
{
	return type;
}

//Возврат сколько поместилось
int ItemInStorage::PutItem(Type type, int count)
{
	if (this->type == Type::EMPTY)
	{
		this->type = type;
		this->count = std::min(STACK_MAX_COUNT, count);
		rect.setTexture(ResourceManager::GetInstance()->GetTexture(type));
		return this->count;
	}
	else if (this->type == type)
	{
		if (this->count + count < STACK_MAX_COUNT)
		{
			this->count += count;
			return count;
		}
		else
		{
			int tmp = STACK_MAX_COUNT - this->count;
			this->count = STACK_MAX_COUNT;
			return tmp;
		}
	}
}


