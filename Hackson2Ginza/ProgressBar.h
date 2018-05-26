#pragma once
#include <Siv3D.hpp>

class ProglessBar
{
private:
	Rect	z_area;
	int		z_progress;
public:
	ProglessBar(const Rect& area, int progress):z_area(area), z_progress(progress){}
	void SetProgress(int progress) { z_progress = progress; }
	void Update	();
	void Draw	() const;
	int		GetProgress	() { return z_progress	; }
	Rect	GetgArea	() { return z_area		; }
	bool	IsFull() { return z_progress == 100; }
};