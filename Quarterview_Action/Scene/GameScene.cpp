#include <DxLib.h>
#include "../_debug/_DebugConOut.h"
#include "../Camera.h"
#include "../Game/Actor/Player.h"
#include "../Game/Actor/Enemy/Enemy1.h"
#include "../Game/Actor/Enemy/Enemy2.h"
#include "../Game/Field.h"

#include "GameScene.h"

GameScene::GameScene()
{
	TRACE("GameScene\n");

	if (!field_)
	{
		field_ = std::make_shared<Field>();
		enemy1_ = std::make_shared<Enemy1>(field_);
		enemy2_ = std::make_shared<Enemy2>(field_);
		player_ = std::make_shared<Player>(field_);
		camera_ = std::make_shared<Camera>(player_);
	}
}

GameScene::~GameScene()
{
}

void GameScene::Run()
{
	camera_->UpDate();
	field_->UpDate();
	player_->UpDate();
	enemy1_->UpDate();
	enemy2_->UpDate();
	Render();
}

void GameScene::Render(void)
{
	player_->Render();
	enemy1_->Render();
	enemy2_->Render();
}
