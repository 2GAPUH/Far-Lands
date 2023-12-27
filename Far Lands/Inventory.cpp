#include "Inventory.h"
#include "ResourceManager.h"

void Inventory::Draw(sf::RenderWindow* win, sf::Vector2f pos)
{
	Storage::Draw(win, pos);
	if (!open)
	{
		subRect.setPosition(pos + downPosSub);
		sf::Vector2f shift = subRect.getPosition() + sf::Vector2f{ 25, 25 };
		win->draw(subRect);
		for (int i = 0; i < STORAGE_SIZE.x; i++)
				storage[i][curLine]->Draw(win, shift + sf::Vector2f{ 76.f * i, 0 });
	}
}

void Inventory::EditCurLine()
{
	curLine = ++curLine % 4;
}

Inventory::Inventory() : Storage()
{
	subRect.setTexture(ResourceManager::GetInstance()->GetTexture(Type::HOT_BAR));
	subRect.setSize(HOT_BAR_SIZE);
	downPosSub = (sf::Vector2f{ WIN_SIZE.x * 0.5f, WIN_SIZE.y * 0.9f } - HOT_BAR_SIZE * 0.5f);

	curLine = 3;
}

Inventory::~Inventory()
{

}
