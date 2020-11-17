#pragma once
#include "ShotBase.h"
#include "../../../common.h"
class EnemyShot :
	public ShotBase
{
public:
	EnemyShot(const VECTOR& pos, int dir, Param param,ShadowParam shadow, std::shared_ptr<Field> field);
	~EnemyShot();
};

