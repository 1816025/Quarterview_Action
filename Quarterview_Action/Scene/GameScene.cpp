#include <DxLib.h>
#include "../_debug/_DebugConOut.h"

#include "../Camera.h"
#include "../Game/Field.h"
#include "../Game/Object/Sky.h"
#include "../Game/Object/Actor/Player.h"
#include "../Game/Object/Actor/Enemy/EnemyBase.h"

#include "GameScene.h"

GameScene::GameScene()
{
	TRACE("GameScene\n");

	if (!field_)
	{
		field_ = std::make_shared<Field>();
		sky_ = std::make_shared<Sky>();
		enemy_ = std::make_shared<EnemyBase>(field_);
		player_ = std::make_shared<Player>(field_);
		camera_ = std::make_shared<Camera>(player_);
	}
	enemy_->Spawner(EnemyType::Kiritan);
	enemy_->Spawner(EnemyType::Itako);
}

GameScene::~GameScene()
{
}

void GameScene::Run()
{
	camera_->UpDate();
	field_->UpDate();
	player_->UpDate();
	enemy_->UpDate();
	Render();
}

void GameScene::Render(void)
{
	sky_->Render();
	player_->Render();
	enemy_->Render();
}
