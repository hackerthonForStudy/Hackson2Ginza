#include <Siv3D.hpp>
#include "CommonScene.h"


void CommonScene::Init()
{
	z_button = Rect{ 690, 500, 280, 50 };
}

void CommonScene::Update()
{
	if (z_button.leftClicked)
	{
		if (z_pGameData->state == GameState::Playing)
		{
			z_pGameData->state = GameState::Setting;
		}
		else if (z_pGameData->state == GameState::Setting)
		{
			z_pGameData->state = GameState::Playing;
		}
	}
}

void CommonScene::Draw() const
{
	Rect{ 680, 0, 300, 640 }.draw({ 255, 255, 200, 255 }).drawFrame(1, 0, Palette::Gray);
	z_font(L"お金:     ", z_pGameData->money).draw(690, 10, Palette::Black);
	z_font(L"評判:     ", z_pGameData->popularity).draw(690, 50, Palette::Black);


	//ボタン
	z_button.draw(Palette::Gray).drawFrame(1, 0, Palette::Black);
	if (z_pGameData->state == GameState::Playing)
	{
		z_buttonFont(L"アップデート").drawCenter(z_button.center, Palette::Black);
	}
	else if (z_pGameData->state == GameState::Setting)
	{
		z_buttonFont(L"運営に戻る").drawCenter(z_button.center, Palette::Black);
	}
}
