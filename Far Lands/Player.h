#pragma once
#include "BaseValue.h"
#include "Stats.h"

class Player
{
private:
	Stats* stats = nullptr;

public:
	Player();
	~Player();
	void SetTexture();
	void AtrackItem();
	void Interact();
	void Atack();
};