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
	//�Q�[���I�[�o�[
	if (z_pGameData->money < 1 || z_pGameData->popularity < 0)
		z_pGameData->state = GameState::GameOver;

	//�^�c�V�[��
	if (z_pGameData->state == GameState::Playing)
		z_playingScene.Update();

	//�A�b�v�f�[�g�V�[��
	if (z_pGameData->state == GameState::Setting)
		z_settingScene.Update();
}

void GameManager::Draw() const
{
	//���ʃf�[�^�����̕`��
	z_commonScene.Draw();

	//�^�c�V�[��
	if (z_pGameData->state == GameState::Playing)
		z_playingScene.Draw();

	//�A�b�v�f�[�g�V�[��
	if (z_pGameData->state == GameState::Setting)
		z_settingScene.Draw();
}

