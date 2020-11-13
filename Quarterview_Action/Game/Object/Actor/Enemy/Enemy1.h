#pragma once
#include <mutex>
#include "EnemyBase.h"
#include "../../../../common.h"

class ShotMng;
class Field;
using shared_Field = std::shared_ptr<Field>;
class Enemy1:
	public EnemyBase
{
public:
	Enemy1();
	Enemy1(const shared_Field field);
	~Enemy1();
	//virtual void UpDate();
};

