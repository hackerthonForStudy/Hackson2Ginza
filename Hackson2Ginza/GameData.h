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
	UserLevel	userLevel	; //���x��	
	GameState	state		; //�Q�[���̏��
	int			money		; //����
	int			payment		; //�x����
	int			days		; //�o�ߓ���
	int			popularity	; //�]��
};

using GameData_Ptr = std::shared_ptr<GameData>;