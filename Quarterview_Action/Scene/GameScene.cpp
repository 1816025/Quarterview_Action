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
}

unique_base GameScene::Run(unique_base own, std::unique_ptr<KeyBoard>& keyboad)
{
	camera_->UpDate();
	player_->UpDate(keyboad);
	enemy_->UpDate();

	isHit();

	return MoveScene(std::move(own));
}

unique_base GameScene::MoveScene(unique_base own)
{
	//‚Ç‚ÌƒV[ƒ“‚ÉˆÚ“®‚·‚é‚©‚Ì”»’è
	if (player_->GetLifePoint() <= 0)
	{
		return std::move(std::make_unique<ResultScene>(false));
	}
	if (enemy_->GetEnemyList().empty())
	{
		return std::move(std::make_unique<ResultScene>(true));
	}
	return std::move(own);
}

void GameScene::Render(void)
{
	sky_->Render();
	field_->Render();
	player_->Render();
	enemy_->Render();
}

void GameScene::Init()
{
	if (field_ != nullptr)
	{
		enemy_ = std::make_shared<EnemyBase>(field_, GetModelList());
		player_ = std::make_shared<Player>(field_);
		sky_ = std::make_shared<Sky>(player_);
		camera_ = std::make_shared<Camera>(player_);
	}
	collision_ = std::make_unique<Collision>();
	finalFlag_ = false;
}

void GameScene::isHit(void)
{
	//—Ž‰ºŽ€
	if (player_->GetPos().y <= -1500)
	{
		player_->ReduceLife();
	}

	//“G‚ÆPlayer
	for (auto enemy : enemy_->GetEnemyList())
	{
		if (collision_->SvsS(player_->GetPos(), 15, enemy.ptr->GetPos(), 15))
		{
		}
		if (collision_->TvsS(player_->GetPos(), 15, enemy.ptr->GetShotMng(), enemy.name, 50))
		{
			TRACE("%s\n", enemy.name.c_str());
			player_->ReduceLife();
		}
		if (collision_->TvsS(enemy.ptr->GetPos(), 15, player_->GetShotMng(),"Player",100))
		{
			enemy_->Killer(enemy.ptr);
		}
	}
}