#pragma once
#include <Siv3D.hpp>
#include "IClick.h"

class Rezi
{
private:
	Rect		z_area;
	int			z_id;
	IClick*		z_pIClick;
	Font z_font = Font(8);

public:
	Rezi(const Rect& area, int ID, IClick* pIClick) : z_area(area), z_id(ID), z_pIClick(pIClick) {}
	void Update();
	void Draw()const;
};