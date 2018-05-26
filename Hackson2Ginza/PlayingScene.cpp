#include "PlayingScene.h"
#include "SystemUtility.h"

void PlayingScene::Init()
{
	z_table1.SetCustomer();
}

void PlayingScene::Update()
{
	//ユーザープログレスの更新
	z_time++;
	if (z_time % z_userSpeed == 0)
		z_userProgress.Update();

	//客の動き
	CustomerUpdate();

	//テーブル
	z_table1.Update();
	z_table2.Update();
	z_table3.Update();

	//レジ
	z_rezi.Update();
	//レジのお客様をここで整列させる。無駄が多いな
	for (int i = 0; i < Count(z_reziCustomers); ++i)
	{
		z_reziCustomers.at(i).SetArea(Rect{ 400 + i * 60, 100 + 80, 50, 80 });
	}

	//待ちのお客様をここで整列させる。無駄が多いな
	for (int i = 0; i < Count(z_waitCustomers); ++i)
	{
		z_waitCustomers.at(i).SetArea(Rect{ 150 + i * 60, 100, 50, 80 });
	}
}

void PlayingScene::Draw() const
{
	//ユーザープログレスの描画
	z_userProgress.Draw();

	//お店の外観描画
	Rect store{ 150, 80, 400, 500 };
	store.drawFrame(1, 0, Palette::Gray);
	z_font(L"ユーザーの行動").draw(80, 20, Palette::Black);

	//テーブルの描画
	z_table1.Draw();
	z_table2.Draw();
	z_table3.Draw();

	//レジの描画 お客様もここで描画する　テーブルの時と違うね!
	z_rezi.Draw();
	for (int i = 0; i < Count(z_reziCustomers); ++i)
	{
		z_reziCustomers.at(i).Draw();
	}
	//待ちのお客様の描画　テーブルの時と違うね!
	for (int i = 0; i < Count(z_waitCustomers); ++i)
	{
		z_waitCustomers.at(i).Draw();
	}
}

void PlayingScene::Clicked(int id)
{
	//ユーザークリックが無効なら何もしない
	if (!z_userProgress.IsFull())
		return;
	
	//テーブルクリック
	if (id == 101)	//１番テーブル
	{
		if (!z_table1.CanUse() && !z_table1.IsCustomerExist())
		{
			z_table1.Clear();
			z_userProgress.SetProgress(0);
		}
	}
	if (id == 102)	//2番テーブル
	{
		if (!z_table2.CanUse() && !z_table2.IsCustomerExist())
		{
			z_table2.Clear();
			z_userProgress.SetProgress(0);
		}
	}
	if (id == 103)	//3番テーブル
	{
		if (!z_table3.CanUse() && !z_table3.IsCustomerExist())
		{
			z_table3.Clear();
			z_userProgress.SetProgress(0);
		}
	}

	//レジクリック
	if (id == 1)
	{
		if (Count(z_reziCustomers) == 0)
			return;
		z_reziCustomers.pop_front();
		CustomerCheck();
		z_userProgress.SetProgress(0);
	}
}

//お客様の動きはここで制御します
void PlayingScene::CustomerUpdate()
{
	//お客様の入店
	//評判がいいほどたくさん入ります
	if (Random(0, 22000) < z_pGameData->popularity + 30)
		CustomerInStore();

	//レジの客の動き
	//プログレスがたまる前に捌かないと食い逃げされる
	for (auto& c : z_reziCustomers)
	{
		c.Update();
	}
	//食い逃げされたとき　すげーかっこ悪いから時間ができたら直す　できなさそう。。。
	int num = Count(z_reziCustomers);
	auto result = std::remove_if(z_reziCustomers.begin(), z_reziCustomers.end(), [](Customer c) {return c.IsEnd(); });
	z_reziCustomers.erase(result, z_reziCustomers.end());
	if (Count(z_reziCustomers) < num)
		z_pGameData->popularity -= num - Count(z_reziCustomers);

	//テーブルの客の動き
	//プログレスがたまるとレジに行く。レジが開いてなければ食い逃げする
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

	//待ちの客の動き
	//テーブルの空きを確認して開いていたら座る
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
	//すげーかっこ悪いから時間ができたら直す　できなさそう。。。
	num = Count(z_waitCustomers);
	auto result2 = std::remove_if(z_waitCustomers.begin(), z_waitCustomers.end(), [](Customer c) {return c.IsEnd(); });
	z_waitCustomers.erase(result2, z_waitCustomers.end());
	if (Count(z_waitCustomers) < num)
		z_pGameData->popularity -= num - Count(z_waitCustomers);

	
}

//お客様を入店させます
//待ち椅子がいっぱいの時は帰ります
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

//お客様をレジに並ばせます
void PlayingScene::CustomerInRezi()
{
	//レジが開いていないと逃げられます
	//さらに評判も下がります
	if (2 < Count(z_reziCustomers))
	{
		z_pGameData->popularity -= 1;
		return;
	}

	Customer customer;
	customer.Start();
	z_reziCustomers.push_back(customer);
}

//お会計処理
void PlayingScene::CustomerCheck()
{
	//会計
	z_pGameData->money += 1000;

	//評判アップ
	z_pGameData->popularity += 2;
}
