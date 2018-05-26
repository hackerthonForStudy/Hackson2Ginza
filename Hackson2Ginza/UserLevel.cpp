#include "UserLevel.h"

void UserLevel::LevelUp()
{
	if(level < 4)
		++level;
}

int UserLevel::GetNextCost()
{
	switch (level)
	{
	case 1:
	{
		return 8000;
	}
	case 2:
	{
		return 12000;
	}
	case 3:
	{
		return 20000;
	}
	default:
		break;
	}
	return 0;
}

bool UserLevel::IsMax()
{
	return level == 4;
}
