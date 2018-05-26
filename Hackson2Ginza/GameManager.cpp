#include "GameManager.h"

void GameManager::Init()
{
	z_gameData.money	= 10000;
	z_gameData.payment	= 0;
	z_gameData.days		= 0;
	z_gameData.popularity = 0;
	z_gameData.state = GameState::Playing;
}

void GameManager::Update()
{
}

void GameManager::Draw() const
{
}
