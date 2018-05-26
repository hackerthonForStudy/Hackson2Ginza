#pragma once
#include<Siv3D.hpp>
#include <deque>
#include "IGameScene.h"
#include "GameData.h"
#include "IClick.h"
#include "Table.h"
#include "Rezi.h"

class PlayingScene : public IGameScene, public IClick
{
private:
	//共有データ
	GameData_Ptr z_pGameData;
	//このクラスだけのデータ
	Font	z_font = Font(14);
	Table	z_table1;
	Table	z_table2;
	Table	z_table3;
	Rezi	z_rezi;
	ProglessBar z_userProgress;
	int z_time = 0;
	int z_userSpeed = 3;
	std::deque<Customer> z_waitCustomers;
	std::deque<Customer> z_reziCustomers;

public:
	PlayingScene(GameData_Ptr pGameData) :
		z_pGameData(pGameData),
		z_table1(Rect{ 180, 450, 50, 50 }, 101, static_cast<IClick*>(this)),
		z_table2(Rect{ 260, 450, 50, 50 }, 102, static_cast<IClick*>(this)),
		z_table3(Rect{ 340, 450, 50, 50 }, 103, static_cast<IClick*>(this)),
		z_rezi  (Rect{ 400, 100, 50, 50 }, 1  , static_cast<IClick*>(this)),
		z_userProgress(Rect{250, 20, 300, 20}, 0)
	{}
	void Init	() override;
	void Update	() override;
	void Draw	()const override;
	void Clicked(int id) override;

private:
	void CustomerUpdate();
	void CustomerInStore();
	void CustomerInRezi();
	void CustomerCheck();
};