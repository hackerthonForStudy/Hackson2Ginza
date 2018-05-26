#include <Siv3D.hpp>
#include "CommonScene.h"


void CommonScene::Init()
{
}

void CommonScene::Update()
{
}

void CommonScene::Draw() const
{
	Rect{ 680, 0, 300, 640 }.draw({ 255, 255, 200, 255 }).drawFrame(1, 0, Palette::Gray);
	z_font(L"‚¨‹à:     ", z_pGameData->money).draw(690, 10, Palette::Black);
	z_font(L"•]”»:     ", z_pGameData->popularity).draw(690, 50, Palette::Black);
}
