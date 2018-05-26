#include "PlayingScene.h"
#include "SystemUtility.h"

void PlayingScene::Init()
{
	z_table1.SetCustomer();
}

void PlayingScene::Update()
{
	//���[�U�[�v���O���X�̍X�V
	z_time++;
	if (z_time % z_userSpeed == 0)
		z_userProgress.Update();

	//�q�̓���
	CustomerUpdate();

	//�e�[�u��
	z_table1.Update();
	z_table2.Update();
	z_table3.Update();

	//���W
	z_rezi.Update();
	//���W�̂��q�l�������Ő��񂳂���B���ʂ�������
	for (int i = 0; i < Count(z_reziCustomers); ++i)
	{
		z_reziCustomers.at(i).SetArea(Rect{ 400 + i * 60, 100 + 80, 50, 80 });
	}

	//�҂��̂��q�l�������Ő��񂳂���B���ʂ�������
	for (int i = 0; i < Count(z_waitCustomers); ++i)
	{
		z_waitCustomers.at(i).SetArea(Rect{ 150 + i * 60, 100, 50, 80 });
	}
}

void PlayingScene::Draw() const
{
	//���[�U�[�v���O���X�̕`��
	z_userProgress.Draw();

	//���X�̊O�ϕ`��
	Rect store{ 150, 80, 400, 500 };
	store.drawFrame(1, 0, Palette::Gray);
	z_font(L"���[�U�[�̍s��").draw(80, 20, Palette::Black);

	//�e�[�u���̕`��
	z_table1.Draw();
	z_table2.Draw();
	z_table3.Draw();

	//���W�̕`�� ���q�l�������ŕ`�悷��@�e�[�u���̎��ƈႤ��!
	z_rezi.Draw();
	for (int i = 0; i < Count(z_reziCustomers); ++i)
	{
		z_reziCustomers.at(i).Draw();
	}
	//�҂��̂��q�l�̕`��@�e�[�u���̎��ƈႤ��!
	for (int i = 0; i < Count(z_waitCustomers); ++i)
	{
		z_waitCustomers.at(i).Draw();
	}
}

void PlayingScene::Clicked(int id)
{
	//���[�U�[�N���b�N�������Ȃ牽�����Ȃ�
	if (!z_userProgress.IsFull())
		return;
	
	//�e�[�u���N���b�N
	if (id == 101)	//�P�ԃe�[�u��
	{
		if (!z_table1.CanUse() && !z_table1.IsCustomerExist())
		{
			z_table1.Clear();
			z_userProgress.SetProgress(0);
		}
	}
	if (id == 102)	//2�ԃe�[�u��
	{
		if (!z_table2.CanUse() && !z_table2.IsCustomerExist())
		{
			z_table2.Clear();
			z_userProgress.SetProgress(0);
		}
	}
	if (id == 103)	//3�ԃe�[�u��
	{
		if (!z_table3.CanUse() && !z_table3.IsCustomerExist())
		{
			z_table3.Clear();
			z_userProgress.SetProgress(0);
		}
	}

	//���W�N���b�N
	if (id == 1)
	{
		if (Count(z_reziCustomers) == 0)
			return;
		z_reziCustomers.pop_front();
		CustomerCheck();
		z_userProgress.SetProgress(0);
	}
}

//���q�l�̓����͂����Ő��䂵�܂�
void PlayingScene::CustomerUpdate()
{
	//���q�l�̓��X
	//�]���������قǂ����������܂�
	if (Random(0, 22000) < z_pGameData->popularity + 30)
		CustomerInStore();

	//���W�̋q�̓���
	//�v���O���X�����܂�O�ɎJ���Ȃ��ƐH�����������
	for (auto& c : z_reziCustomers)
	{
		c.Update();
	}
	//�H���������ꂽ�Ƃ��@�����[�������������玞�Ԃ��ł����璼���@�ł��Ȃ������B�B�B
	int num = Count(z_reziCustomers);
	auto result = std::remove_if(z_reziCustomers.begin(), z_reziCustomers.end(), [](Customer c) {return c.IsEnd(); });
	z_reziCustomers.erase(result, z_reziCustomers.end());
	if (Count(z_reziCustomers) < num)
		z_pGameData->popularity -= num - Count(z_reziCustomers);

	//�e�[�u���̋q�̓���
	//�v���O���X�����܂�ƃ��W�ɍs���B���W���J���ĂȂ���ΐH����������
	if (z_table1.IsCustomerEnd())
	{
		CustomerInRezi();
		z_table1.LeaveCustomer();
	}
	if (z_table2.IsCustomerEnd())
	{
		CustomerInRezi();
		z_table2.LeaveCustomer();
	}
	if (z_table3.IsCustomerEnd())
	{
		CustomerInRezi();
		z_table3.LeaveCustomer();
	}

	//�҂��̋q�̓���
	//�e�[�u���̋󂫂��m�F���ĊJ���Ă��������
	if (0 < Count(z_waitCustomers))
	{
		if (z_table1.CanUse())
		{
			z_waitCustomers.pop_front();
			z_table1.SetCustomer();
		}
		else if (z_table2.CanUse())
		{
			z_waitCustomers.pop_front();
			z_table2.SetCustomer();
		}
		else if (z_table3.CanUse())
		{
			z_waitCustomers.pop_front();
			z_table3.SetCustomer();
		}
	}
	for (auto& c : z_waitCustomers)
	{
		c.Update();
	}
	//�����[�������������玞�Ԃ��ł����璼���@�ł��Ȃ������B�B�B
	num = Count(z_waitCustomers);
	auto result2 = std::remove_if(z_waitCustomers.begin(), z_waitCustomers.end(), [](Customer c) {return c.IsEnd(); });
	z_waitCustomers.erase(result2, z_waitCustomers.end());
	if (Count(z_waitCustomers) < num)
		z_pGameData->popularity -= num - Count(z_waitCustomers);

	
}

//���q�l����X�����܂�
//�҂��֎q�������ς��̎��͋A��܂�
void PlayingScene::CustomerInStore()
{
	if (2 < Count(z_waitCustomers))
	{
		z_pGameData->popularity -= 1;
		return;
	}
	Customer customer;
	customer.Start();
	z_waitCustomers.push_back(customer);
}

//���q�l�����W�ɕ��΂��܂�
void PlayingScene::CustomerInRezi()
{
	//���W���J���Ă��Ȃ��Ɠ������܂�
	//����ɕ]����������܂�
	if (2 < Count(z_reziCustomers))
	{
		z_pGameData->popularity -= 1;
		return;
	}

	Customer customer;
	customer.Start();
	z_reziCustomers.push_back(customer);
}

//����v����
void PlayingScene::CustomerCheck()
{
	//��v
	z_pGameData->money += 1000;

	//�]���A�b�v
	z_pGameData->popularity += 2;
}
