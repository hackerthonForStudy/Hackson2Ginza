#include "Rezi.h"

void Rezi::Update()
{
	//クリック判定
	if (z_area.leftClicked)
		z_pIClick->Clicked(z_id);
}

void Rezi::Draw() const
{
	z_area.drawFrame(1, 0, Palette::Black);
	z_font(L"レジ").drawCenter(z_area.center, Palette::Black);
}
