#pragma once
#include "PlayingScene.h"

class GameManager
{
private:
	GameData z_gameData;
	PlayingScene z_playingScene{ std::make_shared<GameData>(z_gameData) };
public:
	void Init	();
	void Update	();
	void Draw	() const;
};