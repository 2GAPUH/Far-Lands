
#include "ItemInStorage.h"
#include "ResourceManager.h"
#include "EntityManager.h"

void ItemInStorage::UpdateText()
{
	text.setString(std::to_string(count));
}

ItemInStorage::ItemInStorage()
{
	rect.setSize(STORAGE_CELL);
	type = ItemType::EMPTY;
	text.setFont(*ResourceManager::GetInstance()->GetFont());
	text.setFillColor(sf::Color::Black);
	text.setOutlineColor(sf::Color::Black);
	text.setCharacterSize(12);
}

ItemInStorage::~ItemInStorage()
{
}

void ItemInStorage::Draw(sf::RenderWindow* win, sf::Vector2f pos)
{
	if(type != ItemType::EMPTY)
	{
		rect.setPosition(pos);
		text.setPosition({ pos.x + 48, pos.y + 46 });
		win->draw(rect);
		win->draw(text);
	}
}

ItemType ItemInStorage::GetItemType()
{
	return type;
}

void ItemInStorage::ReduceItem()
{
	if (--count <= 0)
		type = ItemType::EMPTY;
	UpdateText();
}



//Возврат сколько поместилось
int ItemInStorage::PutItem(ItemType type, int count)
{
	if (this->type == ItemType::EMPTY)
	{
		this->type = type;
		this->count = std::min(STACK_MAX_COUNT, count);
		rect.setTexture(ResourceManager::GetInstance()->GetTexture(TypeConverter::Convert(type)));
		UpdateText();
		return this->count;
	}
	else if (this->type == type)
	{
		if (this->count + count < STACK_MAX_COUNT)
		{
			this->count += count;
			UpdateText();
			return count;
		}
		else
		{
			int tmp = STACK_MAX_COUNT - this->count;
			this->count = STACK_MAX_COUNT;
			UpdateText();
			return tmp;
		}
	}
	return 0;
}




