#pragma once
#include "Customer.h"
#include "IClick.h"

class Table
{
private:
	Rect		z_area		;
	int			z_id		;
	bool		z_canUse	=true;
	Customer	z_customer	;
	IClick*		z_pIClick	;

	Font z_font = Font(8);
public:
	Table(const Rect& area, int ID, IClick* pIClick): z_area(area),z_id(ID), z_pIClick(pIClick){}
	void Update	();
	void Draw	()const;
	void SetCustomer();
	void LeaveCustomer();
	void Clear();

	bool CanUse() const;
	bool IsCustomerExist() const { return z_customer.IsExist(); }
	bool IsCustomerEnd() const;

};