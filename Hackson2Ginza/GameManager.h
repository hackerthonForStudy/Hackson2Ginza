#pragma once
#include "PlayingScene.h"
#include "CommonScene.h"
#include "SettingScene.h"

class GameManager
{
private:
	GameData_Ptr z_pGameData = std::make_shared<GameData>();
	PlayingScene z_playingScene{ z_pGameData };
	SettingScene z_settingScene{ z_pGameData };
	CommonScene z_commonScene{ z_pGameData };

public:
	void Init	();
	void Update	();
	void Draw	() const;
	
};