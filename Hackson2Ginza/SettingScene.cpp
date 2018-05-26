#include "SettingScene.h"

void SettingScene::Init()
{
	z_userUpdateBtn = Rect{ 50, 50, 150, 50 };
}

void SettingScene::Update()
{
	if (z_userUpdateBtn.leftClicked)
	{
		if (!CanUserUpdate())
			return;

		z_pGameData->money -= z_pGameData->userLevel.GetNextCost();
		z_pGameData->userLevel.LevelUp();
	}
}

void SettingScene::Draw() const
{
	//�w�i�F
	Rect{ 0, 0, 680, 640 }.draw(Palette::Lightgreen);

	//���[�U�[���x���A�b�v
	z_userUpdateBtn.draw(Palette::Gray).drawFrame(1, 0, Palette::Black);
	z_buttonFont(L"���x���A�b�v").drawCenter(z_userUpdateBtn.center, Palette::Black);
	auto& b = z_userUpdateBtn;
	if(!z_pGameData->userLevel.IsMax())
		z_buttonFont(L"��p:", z_pGameData->userLevel.GetNextCost()).draw(b.pos.x + b.w + 10, b.pos.y, Palette::Black);
	else
		z_buttonFont(L"���x��MAX�ł��B����������!").draw(b.pos.x + b.w + 10, b.pos.y, Palette::Black);

}

bool SettingScene::CanUserUpdate()
{
	if (z_pGameData->userLevel.IsMax())
		return false;
	return z_pGameData->userLevel.GetNextCost() <= z_pGameData->money;
}
