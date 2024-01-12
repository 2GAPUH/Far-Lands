#include "Inventory.h"
#include "ResourceManager.h"

void Inventory::Draw(sf::RenderWindow* win, sf::Vector2f pos)
{
	Storage::Draw(win, pos);
	if (!open)
	{
		rectBar.setPosition(pos + downPosSub);
		sf::Vector2f shift = rectBar.getPosition() + sf::Vector2f{ 24, 24 };
		rectCurElem.setPosition(shift + sf::Vector2f{ 76.f * cutLine, 0 });

		win->draw(rectBar);
		win->draw(rectCurElem);
		for (int i = 0; i < STORAGE_SIZE.x; i++)
				storage[i][curElem]->Draw(win, shift + sf::Vector2f{ 76.f * i, 0 });
	}
}

void Inventory::EditCurLine()
{
	curElem = ++curElem % 4;
}

void Inventory::EditCurElem(int i)
{
	cutLine += i;

	if (cutLine > 7) {
		cutLine = cutLine % 8;
	}
	else if (cutLine < 0) {
		cutLine = 8 + (cutLine % 8); 
	}
}

ItemType Inventory::GetCurType()
{
	return storage[cutLine][curElem]->GetItemType();
}

void Inventory::ReduceCurElem()
{
	storage[cutLine][curElem]->ReduceItem();
}

Inventory::Inventory() : Storage()
{
	rectBar.setTexture(ResourceManager::GetInstance()->GetTexture(Type::INTERFACE));
	rectBar.setTextureRect(TextureRect::HOT_BAR);
	rectBar.setSize(HOT_BAR_SIZE);
	downPosSub = (sf::Vector2f{ WIN_SIZE.x * 0.5f, WIN_SIZE.y * 0.9f } - HOT_BAR_SIZE * 0.5f);

	rectCurElem.setSize(CUR_ELEM_TEXTURE_SIZE);
	rectCurElem.setTexture(ResourceManager::GetInstance()->GetTexture(Type::INTERFACE));
	rectCurElem.setTextureRect(TextureRect::CUR_ELEM);

	curElem = 3;
}

Inventory::~Inventory()
{

}
