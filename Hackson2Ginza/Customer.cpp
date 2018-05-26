#include "Customer.h"
#include "ProgressBar.h"

Customer & Customer::operator=(const Customer & c)
{
	z_area		= c.z_area;
	z_progress	= c.z_progress;
	z_time		= c.z_time;
	z_speed		= c.z_speed;
	z_isExist	= c.z_isExist;
	return *this;
}

void Customer::Draw() const
{
	if (!IsExist())
		return;

	z_area(z_texture).draw();
	ProglessBar{ Rect{z_area.pos, z_area.w, z_area.h / 10}, z_progress }.Draw();
}

void Customer::Update()
{
	if (!IsExist())
		return;

	++z_time;
	if(z_time % z_speed == 1)
		++z_progress = Min(z_progress, 100);
}

void Customer::Start()
{
	z_isExist = true;
}

void Customer::Reset()
{
	z_progress	= 0;
	z_time		= 0;
	z_speed		= 3;
	z_isExist	= false;
}
