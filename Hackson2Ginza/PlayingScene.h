#pragma once
#include <memory>
#include "IGameScene.h"
#include "GameData.h"

class PlayingScene : public IGameScene
{
public:
	PlayingScene(std::shared_ptr<GameData> pGameData);
	void Init	() override;
	void Update	() override;
	void Draw	()const override;
};