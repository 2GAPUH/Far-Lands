#pragma once
#include "ItemInStorage.h"
#include "BaseValue.h"

class Storage
{
private:
	ItemInStorage*** storage = nullptr;
	

public:
	Storage();
	~Storage();

};

