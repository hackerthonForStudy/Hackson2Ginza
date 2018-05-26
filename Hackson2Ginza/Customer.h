#pragma once
#include "ProgressBar.h"

class Customer
{
private:
	const Texture z_texture = Texture(L"Example/Customer.png");
	Rect	z_area;
	int		z_progress	= 0;
	int		z_time		= 0;
	int		z_speed		= 3;
	bool	z_isExist	= false;

public:
	Customer & operator=(const Customer& c);
	void Draw()const;
	void Update();

	void Start();
	void SetArea(const Rect& area) { z_area = area; }
	void Reset();

	bool IsExist()const  { return z_isExist; }
	bool IsEnd()  const { return !(z_progress < 100); }
};