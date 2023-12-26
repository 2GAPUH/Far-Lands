#include "Storage.h"

Storage::Storage()
{
	storage = new ItemInStorage**[STORAGE_SIZE.x];
	for (int i = 0; i < MAP_SIZE.x; i++)
		storage[i] = new ItemInStorage*[STORAGE_SIZE.y];

	for (int i = 0; i < STORAGE_SIZE.x; i++)
		for (int j = 0; j < STORAGE_SIZE.y; j++)
			storage[i][j] = new ItemInStorage();
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


