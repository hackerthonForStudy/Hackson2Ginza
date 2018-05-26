#pragma once

enum struct GameState
{
	Playing,
	Setting
};

struct GameData
{
	GameState	state		; //ƒQ[ƒ€‚Ìó‘Ô
	int			money		; //‚¨‹à
	int			payment		; //x•¥‚¢
	int			days		; //Œo‰ß“ú”
	int			popularity	; //•]”»
};

using GameData_Ptr = std::shared_ptr<GameData>;