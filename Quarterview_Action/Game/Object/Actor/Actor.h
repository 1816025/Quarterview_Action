#pragma once
#include <mutex>
#include <string>
#include <list>
#include "../Object.h"
#include "../../../common.h"

class ShotMng;
class Field;
class Object;
using shared_Field = std::shared_ptr<Field>;
class EnemyBase;
class Enemy1;
class Enemy2;
	struct EnemyStatus
	{
		std::string name;
		std::shared_ptr<EnemyBase> ptr;
	};
class Actor
	:public Object
{
public:
	Actor();
	Actor(const shared_Field field, std::vector<std::string>modelList);
	virtual ~Actor();
	bool Init(const int& id, const int& shadow,const Param& data);
	virtual void Render(void);
	virtual void Render(std::string name);
	virtual void UpDate(void);
private:
	void DrawStatus();
protected:
	void Animation(int no);

	std::shared_ptr<Enemy1> enemy1_;
	std::shared_ptr<Enemy2> enemy2_;
	std::list<EnemyStatus> enemyList_;
};

