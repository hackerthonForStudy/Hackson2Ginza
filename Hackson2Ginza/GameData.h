#pragma once
#include "UserLevel.h"

enum struct GameState
{
	Playing,
	Setting,
	GameOver
};

struct GameData
{
	UserLevel	userLevel	; //レベル	
	GameState	state		; //ゲームの状態
	int			money		; //お金
	int			payment		; //支払い
	int			days		; //経過日数
	int			popularity	; //評判
};

using GameData_Ptr = std::shared_ptr<GameData>;