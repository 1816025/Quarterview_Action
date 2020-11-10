#pragma once
#include <mutex>
#include "../Actor.h"
#include "../../../common.h"

class ShotMng;
class Field;
using shared_Field = std::shared_ptr<Field>;
class Enemy1:
	public Actor
{
public:
	Enemy1(const shared_Field field);
	~Enemy1();
	//virtual void UpDate();
};

