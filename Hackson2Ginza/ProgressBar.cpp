#include "ProgressBar.h"

void ProglessBar::Update()
{
	++z_progress = Min(z_progress, 100);
}

void ProglessBar::Draw() const
{
	Rect{ z_area.pos, z_area.w * z_progress / 100, z_area.h }.draw(Palette::Greenyellow);
	z_area.drawFrame(1, 0, Palette::Gray);
}
