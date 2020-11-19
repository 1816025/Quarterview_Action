#include "../../Shot/ShotMng.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "EnemyBase.h"

EnemyBase::EnemyBase()
{
}

EnemyBase::EnemyBase(const shared_Field field)
{
	field_ = field;
	shotmng_ = std::make_shared<ShotMng>(ShooterType::ENEMY,MV1LoadModel("model/bullet/bullet1.mv1"), field_);
	enemy1_  = std::make_shared<Enemy1>(field,shotmng_);
	enemy2_  = std::make_shared<Enemy2>(field,shotmng_);
}

EnemyBase::~EnemyBase()
{
}

void EnemyBase::UpDate(void)
{
	for (auto enemy : enemyList_)
	{
		enemy.ptr->Actor::UpDate();
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
		status.ptr = enemy1_;
		enemyList_.emplace_back(status);
		break;
	case EnemyType::Itako:
		status.name = "Itako";
		status.ptr = enemy2_;
		enemyList_.emplace_back(status);
		break;
	default:
		
		break;
	}
}
