#include "Storage.h"
#include "ResourceManager.h"


sf::Vector2f Storage::constShift = { 76, 76 };
sf::Vector2i Storage::GetCurCell(sf::Vector2i mousePos)
{
	sf::Vector2i start = mousePos - sf::Vector2i(middlePos + sf::Vector2f{ 24, 24 });


	if ((start.x < 0 || start.y < 0) ||
		(start.x / (int)constShift.x >= STORAGE_SIZE.x || start.y / (int)constShift.y >= STORAGE_SIZE.y))
		throw("Out of storage range!");
	else if (start.x % (int)constShift.x >= 60 || start.y % (int)constShift.y >= 60)
		throw("Storage position error!");
	else
		return sf::Vector2i{ start.x / (int)constShift.x, start.y / (int)constShift.y };
}

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

	for (int i = 0; i < STORAGE_SIZE.x; i++)
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
				storage[i][j]->Draw(win, shift + sf::Vector2f{ constShift.x * i, constShift.y * j });
	}
}

//Возврат сколько не поместилось
int Storage::PutItemAuto(ItemType type, int count)
{
	for (int j = 0; j < STORAGE_SIZE.y; j++)
	{
		for (int i = 0; i < STORAGE_SIZE.x; i++)
		{
			count -= storage[i][j]->PutItem(type, count);
			if (count <= 0)
				return count;
		}
	}

	return count;
}

int Storage::PutItemAutoInStorage(ItemType type, int count)
{
	for (int j = 1; j < STORAGE_SIZE.y; j++)
	{
		for (int i = 0; i < STORAGE_SIZE.x; i++)
		{
			count -= storage[i][j]->PutItem(type, count);
			if (count <= 0)
				return count;
		}
		if (j == 3)
			j = -1;
		else if (j == 0)
			break;
	}

	return count;
}



void Storage::Move(sf::Vector2i start, sf::Vector2i end)
{
	try
	{
		start = GetCurCell(start);
		end = GetCurCell(end);

		ItemInStorage* tmp = storage[start.x][start.y];
		storage[start.x][start.y] = storage[end.x][end.y];
		storage[end.x][end.y] = tmp;
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}
}

void Storage::Update(sf::RenderWindow* win)
{
	if (open)
	{
		static bool interact = 0;
		static sf::Vector2i start = { 0, 0 }, end = {0, 0};

		if(interact == false)
		{
			
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
			{
				interact = true;
				start = sf::Mouse::getPosition(*win);
			}
		}
		else 
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == false)
			{
				interact = false;
				end = sf::Mouse::getPosition(*win);
				Move(start, end);
			};
		}
	}
}

