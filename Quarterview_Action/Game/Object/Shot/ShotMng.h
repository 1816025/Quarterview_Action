#pragma once
#include <mutex>
#include <list>
#include "../Object.h"
#include "../../../common.h"
enum class ShooterType
{
	PLAYER,
	ENEMY
};
class Shot;
class Field;
class ShotBase;
class EnemyShot;
class Shot;
class ShotMng
	:public Object
{
public:
	ShotMng(ShooterType type,Param param,std::shared_ptr<Field> field);
	~ShotMng();

	void AddBullet(const VECTOR& pos, const int& dir);
	void UpDate(void);
	void Render(void);
private:
	ShadowParam shadow_;
	int interval;
	ShooterType type_;
	std::list<ShotBase*> shotList_;
};

