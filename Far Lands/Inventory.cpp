#include "Inventory.h"
#include "ResourceManager.h"

void Inventory::Draw(sf::RenderWindow* win, sf::Vector2f pos)
{
	Storage::Draw(win, pos);
	if (!open)
	{
		rectBar.setPosition(pos + downPosSub);
		sf::Vector2f shift = rectBar.getPosition() + sf::Vector2f{ 24, 24 };
		rectCurElem.setPosition(shift + sf::Vector2f{ 76.f * curElem, 0 });

		win->draw(rectBar);
		win->draw(rectCurElem);
		for (int i = 0; i < STORAGE_SIZE.x; i++)
				storage[i][curLine]->Draw(win, shift + sf::Vector2f{ 76.f * i, 0 });
	}
}

void Inventory::EditCurLine()
{
	curLine = ++curLine % 4;
}

void Inventory::EditCurElem(int i)
{
	curElem += i;

	if (curElem > 7) {
		curElem = curElem % 8;
	}
	else if (curElem < 0) {
		curElem = 8 + (curElem % 8); 
	}
}

Inventory::Inventory() : Storage()
{
	rectBar.setTexture(ResourceManager::GetInstance()->GetTexture(Type::HOT_BAR));
	rectBar.setSize(HOT_BAR_SIZE);
	downPosSub = (sf::Vector2f{ WIN_SIZE.x * 0.5f, WIN_SIZE.y * 0.9f } - HOT_BAR_SIZE * 0.5f);

	rectCurElem.setSize(CUR_ELEM_TEXTURE_SIZE);
	rectCurElem.setTexture(ResourceManager::GetInstance()->GetTexture(Type::CUR_ELEM));

	curLine = 3;
}

Inventory::~Inventory()
{

}
