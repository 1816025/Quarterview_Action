#pragma once
#include "EnemyBase.h"

class Field;
using shared_Field = std::shared_ptr<Field>;
class Enemy2:
	public EnemyBase
{
public:
	Enemy2();
	Enemy2(const shared_Field field);
	~Enemy2();
};

