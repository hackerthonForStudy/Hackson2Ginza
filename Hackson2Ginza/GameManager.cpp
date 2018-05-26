#include "GameManager.h"

void GameManager::Init()
{
	z_pGameData->money		= 10000;
	z_pGameData->payment	= 0;
	z_pGameData->days		= 0;
	z_pGameData->popularity = 10;
	z_pGameData->state		= GameState::Playing;

	z_playingScene.Init();
	z_settingScene.Init();
	z_commonScene.Init();

}

void GameManager::Update()
{
	z_commonScene.Update();
	//ゲームオーバー
	if (z_pGameData->money < 1 || z_pGameData->popularity < 0)
		z_pGameData->state = GameState::GameOver;

	//運営シーン
	if (z_pGameData->state == GameState::Playing)
		z_playingScene.Update();

	//アップデートシーン
	if (z_pGameData->state == GameState::Setting)
		z_settingScene.Update();
}

void GameManager::Draw() const
{
	//共通データ部分の描画
	z_commonScene.Draw();

	//運営シーン
	if (z_pGameData->state == GameState::Playing)
		z_playingScene.Draw();

	//アップデートシーン
	if (z_pGameData->state == GameState::Setting)
		z_settingScene.Draw();
}

