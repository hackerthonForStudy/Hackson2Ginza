#include "GameManager.h"

void GameManager::Init()
{
	z_pGameData->money		= 10000;
	z_pGameData->payment	= 0;
	z_pGameData->days		= 0;
	z_pGameData->popularity = 10;
	z_pGameData->state		= GameState::Playing;

	z_playingScene.Init();
	z_commonScene.Init();

}

void GameManager::Update()
{
	z_commonScene.Update();
	if (z_pGameData->state == GameState::Playing)
		z_playingScene.Update();
}

void GameManager::Draw() const
{
	//‹¤’Êƒf[ƒ^•”•ª‚Ì•`‰æ
	z_commonScene.Draw();
	if (z_pGameData->state == GameState::Playing)
		z_playingScene.Draw();
}

