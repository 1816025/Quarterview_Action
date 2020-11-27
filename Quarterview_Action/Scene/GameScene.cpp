#include <DxLib.h>
#include "../_debug/_DebugConOut.h"
#include "../common.h"
#include "../Collision.hpp"

#include "../Camera.h"
#include "../Game/Field.h"
#include "../Game/Object/Object.h"
#include "../Game/Object/Sky.h"
#include "../Game/Object/Shot/ShotMng.h"
#include "../Game/Object/Shot/ShotBase.h"
#include "../Game/Object/Actor/Player.h"
#include "../Game/Object/Actor/Enemy/EnemyBase.h"

#include "GameScene.h"

GameScene::GameScene()
{
	TRACE("GameScene\n");
	GetFileList("model");
	if (!field_)
	{
		field_ = std::make_shared<Field>(GetTextureList());
		sky_ = std::make_shared<Sky>();
		enemy_ = std::make_shared<EnemyBase>(field_,GetModelList());
		player_ = std::make_shared<Player>(field_);
		camera_ = std::make_shared<Camera>(player_);
	}
	collision_ = std::make_unique<Collision>();
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

	//“G‚ÆPlayer
	for (auto enemy : enemy_->GetEnemyList())
	{
		if (collision_->SvsS(player_->GetPos(), 15, enemy.ptr->GetPos(), 15))
		{
			//TRACE(enemy.name.c_str());
		}
		if (collision_->TvsS(player_->GetPos(), 15, enemy.ptr->GetShotMng(), 50))
		{
			//TRACE((enemy.name+"hit\n").c_str());
		}
		if (collision_->TvsS(enemy.ptr->GetPos(), 15, player_->GetShotMng(), 100))
		{
			TRACE((enemy.name + "hit\n").c_str());
			enemy_->Killer(enemy.ptr);
		}
	}

	Render();
}

void GameScene::Render(void)
{
	sky_->Render();
	player_->Render();
	enemy_->Render();
}
