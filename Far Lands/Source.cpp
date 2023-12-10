#include "GameCore.h"


int main()
{
	GameCore::GetInstance()->Start();

	GameCore::DestroyInstance();

	return 0;
}
