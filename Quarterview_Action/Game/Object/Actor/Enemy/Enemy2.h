#pragma once
#include "EnemyBase.h"

class Field;
class ShotMng;
using shared_Field = std::shared_ptr<Field>;
using shared_ShotMng = std::shared_ptr<ShotMng>;
class Enemy2:
	public EnemyBase
{
public:
	Enemy2();
	Enemy2(const shared_Field field,const shared_ShotMng shotmng);
	~Enemy2();
};

