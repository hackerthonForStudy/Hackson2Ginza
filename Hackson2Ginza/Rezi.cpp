#include "Rezi.h"

void Rezi::Update()
{
	//�N���b�N����
	if (z_area.leftClicked)
		z_pIClick->Clicked(z_id);
}

void Rezi::Draw() const
{
	z_area.drawFrame(1, 0, Palette::Black);
	z_font(L"���W").drawCenter(z_area.center, Palette::Black);
}
