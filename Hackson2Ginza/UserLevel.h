#pragma once

class UserLevel
{
public:
	int		level = 1;
	void	LevelUp();
	int		GetNextCost();
	bool	IsMax();
};