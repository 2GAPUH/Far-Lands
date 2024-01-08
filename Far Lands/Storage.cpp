#include "Storage.h"
#include "ResourceManager.h"

Storage::Storage()
{
	storage = new ItemInStorage**[STORAGE_SIZE.x];

	for (int i = 0; i < STORAGE_SIZE.x; i++)
		storage[i] = new ItemInStorage*[STORAGE_SIZE.y];

	for (int i = 0; i < STORAGE_SIZE.x; i++)
		for (int j = 0; j < STORAGE_SIZE.y; j++)
			storage[i][j] = new ItemInStorage();

	rectStorage.setSize(STORAGE_SIZE_OPEN);
	rectStorage.setTexture(ResourceManager::GetInstance()->GetTexture(Type::INTERFACE));
	rectStorage.setTextureRect(TextureRect::STORAGE);

	downPos = (sf::Vector2f{ WIN_SIZE.x * 0.5f, WIN_SIZE.y * 0.75f } - STORAGE_SIZE_OPEN * 0.5f);
	topPos = (sf::Vector2f{WIN_SIZE.x * 0.5f, WIN_SIZE.y * 0.25f } - STORAGE_SIZE_OPEN * 0.5f);
	middlePos = (WIN_SIZE * 0.5f - STORAGE_SIZE_OPEN * 0.5f);
}

Storage::~Storage()
{
	for (int i = 0; i < STORAGE_SIZE.x; i++)
		for (int j = 0; j < STORAGE_SIZE.y; j++)
			delete storage[i][j];

	for (int i = 0; i < MAP_SIZE.x; i++)
		delete storage[i];

	delete storage;
	storage = 0;
}

void Storage::Open()
{
	open = !open;
}

void Storage::Draw(sf::RenderWindow* win, sf::Vector2f pos)
{
	if (open)
	{
		rectStorage.setPosition(pos + middlePos);
		sf::Vector2f shift = rectStorage.getPosition() + sf::Vector2f{24, 24};
		win->draw(rectStorage);
		for (int i = 0; i < STORAGE_SIZE.x; i++)
			for (int j = 0; j < STORAGE_SIZE.y; j++)
				storage[i][j]->Draw(win, shift + sf::Vector2f{ 76.f * i,76.f * j });
	}
}

//Возврат сколько не поместилось
int Storage::PutItemAuto(Type type, int count)
{
	for (int j = 0; j < STORAGE_SIZE.y; j++)
		for (int i = 0; i < STORAGE_SIZE.x; i++)
		{
			count -= storage[i][j]->PutItem(type, count);
			if (count <= 0)
				return count;
		}

	return count;
}


