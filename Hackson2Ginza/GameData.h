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
	UserLevel	userLevel	; //ƒŒƒxƒ‹	
	GameState	state		; //ƒQ[ƒ€‚Ìó‘Ô
	int			money		; //‚¨‹à
	int			payment		; //x•¥‚¢
	int			days		; //Œo‰ß“ú”
	int			popularity	; //•]”»
};

using GameData_Ptr = std::shared_ptr<GameData>;