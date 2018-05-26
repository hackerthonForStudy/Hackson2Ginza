#pragma once
#include <memory>
#include "IGameScene.h"
#include "GameData.h"

class CommonScene : public IGameScene
{
private:
	GameData_Ptr z_pGameData;
	Font z_font = Font(23);

public:
	CommonScene(GameData_Ptr pGameData) :z_pGameData(pGameData) {}
	void Init	() override;
	void Update	() override;
	void Draw	() const override;
};