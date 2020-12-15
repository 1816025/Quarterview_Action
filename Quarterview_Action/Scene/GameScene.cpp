#include "../Collision.hpp"
#include "../Input/KeyBoard.h"
#include "../Camera.h"
#include "../Game/Object/Object.h"
#include "../Game/Object/Sky.h"
#include "../Game/Object/Shot/ShotMng.h"
#include "../Game/Object/Shot/ShotBase.h"
#include "../Game/Object/Actor/Player.h"
#include "../Game/Object/Actor/Enemy/EnemyBase.h"

#include "ResultScene.h"
#include "GameScene.h"

GameScene::GameScene()
{
	TRACE("GameScene\n");
	GetFileList("model");
	Init();
}

GameScene::GameScene(std::shared_ptr<Field> field)
{
	TRACE("GameScene\n");
	field_ = field;
	Init();
}

GameScene::~GameScene()
{
	int a = 0;
}

unique_base GameScene::Run(unique_base own, std::unique_ptr<KeyBoard>& keyboad)
{
	camera_->UpDate();
	player_->UpDate(keyboad);
	enemy_->UpDate();

	//“G‚ÆPlayer
	for (auto enemy : enemy_->GetEnemyList())
	{
		if (collision_->SvsS(player_->GetPos(), 15, enemy.ptr->GetPos(), 15))
		{
		}
		if (collision_->TvsS(player_->GetPos(), 15, enemy.ptr->GetShotMng(), 50))
		{
			TRACE("%s\n",enemy.name.c_str())
			//return std::move(std::make_unique<ResultScene>(false));
		}
		if (collision_->TvsS(enemy.ptr->GetPos(), 15, player_->GetShotMng(), 100))
		{
			enemy_->Killer(enemy.ptr);
		}
	}
	return std::move(own);
}

void GameScene::Render(void)
{
	sky_->Render();
	player_->Render();
	field_->Render();
	enemy_->Render();
}

void GameScene::Init()
{
	if (field_ != nullptr)
	{
		sky_ = std::make_shared<Sky>();
		enemy_ = std::make_shared<EnemyBase>(field_, GetModelList());
		player_ = std::make_shared<Player>(field_);
		camera_ = std::make_shared<Camera>(player_);
	}
	collision_ = std::make_unique<Collision>();
	finalFlag_ = false;
}
