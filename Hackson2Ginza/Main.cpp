# include <Siv3D.hpp>
#include "GameManager.h"

void Main()
{
	Window::Resize(980, 640);
	Graphics::SetBackground(Palette::Whitesmoke);

	GameManager z_gameManager;
	z_gameManager.Init();

	while (System::Update())
	{
		z_gameManager.Update();
		z_gameManager.Draw();
	}
}
