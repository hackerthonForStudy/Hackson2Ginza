#pragma once
#include<Siv3D.hpp>
#include "IGameScene.h"
#include "GameData.h"

class SettingScene : public IGameScene
{
private:
	//���L�f�[�^
	GameData_Ptr z_pGameData;
	//���̃N���X�����̃f�[�^
	Font z_buttonFont = Font(14);
	Rect z_userUpdateBtn;
	Rect z_catchBtn;
	Rect z_reziBtn;
	Rect z_cleanBtn;


public:
	SettingScene(GameData_Ptr pGameData) :
		z_pGameData(pGameData)
	{}
	void Init	() override;
	void Update	() override;
	void Draw	()const override;

private:
	bool CanUserUpdate();
};