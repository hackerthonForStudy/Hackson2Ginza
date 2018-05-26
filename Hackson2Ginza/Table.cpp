#include "Table.h"

void Table::Update()
{
	//�N���b�N����
	if (z_area.leftClicked)
		z_pIClick->Clicked(z_id);
	//���q�l�̏�ԕω�
	if (z_customer.IsExist())
		z_customer.Update();
}

void Table::Draw() const
{
	if (!CanUse())
	{
		z_area.draw(Palette::Brown);
	}
	z_area.drawFrame(1, 0, Palette::Black);
	//�q������Ƃ��͋q��\������
	if (z_customer.IsExist())
	{
		z_customer.Draw();
	}
	z_font(L"�e�[�u��").drawCenter(z_area.center, Palette::Black);
}

void Table::SetCustomer()
{
	z_canUse = false;
	z_customer.SetArea(Rect{ z_area.pos.movedBy(Point{ 0, -80 }), 50, 80 });
	z_customer.Start();
}

void Table::LeaveCustomer()
{
	z_customer.Reset();
}

void Table::Clear()
{
	z_customer.Reset();
	z_canUse = true;

}

bool Table::CanUse() const
{
	return z_canUse;
}

bool Table::IsCustomerEnd() const
{
	return z_customer.IsEnd();
}
