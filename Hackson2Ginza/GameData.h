#pragma once

enum struct GameState
{
	Playing,
	Setting
};

struct GameData
{
	GameState	state		; //�Q�[���̏��
	int			money		; //����
	int			payment		; //�x����
	int			days		; //�o�ߓ���
	int			popularity	; //�]��
};
