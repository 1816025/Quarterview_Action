#include "../../Shot/ShotMng.h"
#include "../../../Field.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "EnemyBase.h"

EnemyBase::EnemyBase()
{
	enemyList_.clear();
}

EnemyBase::EnemyBase(const shared_Field field,std::vector<std::string> modelList)
{
	field_ = field;
	shotmng_ = std::make_shared<ShotMng>(ShooterType::ENEMY,MV1LoadModel(("model/bullet/"+modelList[1]).c_str()), field_);
	enemy1_  = std::make_shared<Enemy1>(field,shotmng_);
	enemy2_  = std::make_shared<Enemy2>(field,shotmng_);
	Spawner(EnemyType::Kiritan);
	Spawner(EnemyType::Itako);
}

EnemyBase::~EnemyBase()
{
}

void EnemyBase::UpDate(void)
{
	for (auto enemy : enemyList_)
	{
		enemy.ptr->UpDate();
	}
}

void EnemyBase::Render(void)
{
	for (auto enemy : enemyList_)
	{
		enemy.ptr->Actor::Render(enemy.name);
	}
}

void EnemyBase::Spawner(EnemyType id)
{
	EnemyStatus status;
	switch (id)
	{
	case EnemyType::Kiritan:
		status.name = "Kiritan";
		if (enemy1_->Object::field_->isBlock(enemy1_->GetPos().x, enemy1_->GetPos().y, enemy1_->GetPos().z))
		{
			status.ptr = enemy1_;
			enemyList_.emplace_back(status);
			break;
		}
		else
		{
			enemy1_->AddPos(VGet(0,0,100));
			Spawner(EnemyType::Kiritan);
		}
		break;
	case EnemyType::Itako:
		status.name = "Itako";
		if (enemy2_->Object::field_->isBlock(enemy2_->GetPos().x, enemy2_->GetPos().y, enemy2_->GetPos().z))
		{
			status.ptr = enemy2_;
			enemyList_.emplace_back(status);
			break;
		}
		else
		{
			enemy2_->AddPos(VGet(100, 0, 0));
			Spawner(EnemyType::Itako);
		}
		break;
	default:
		
		break;
	}
}

void EnemyBase::Killer(std::shared_ptr<EnemyBase> enemy)
{
	for (auto itr = enemyList_.begin(); itr != enemyList_.end();)
	{
		if (itr->ptr == enemy)
		{
			itr = enemyList_.erase(itr);
			break;
		}
		else
		{
			itr++;
		}
	}
}

const std::list<EnemyStatus> EnemyBase::GetEnemyList(void)
{
	return enemyList_;
}
