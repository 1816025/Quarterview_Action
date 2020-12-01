#pragma once
#include <mutex>
#include <list>
#include <map>
#include <string>
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
struct ShotData
{
	std::string unitName;
	ShotBase* shot;
};
class ShotMng
	:public Object
{
public:
	ShotMng(ShooterType type,int id,std::shared_ptr<Field> field);
	~ShotMng();

	void AddBullet(const std::string name,const VECTOR& pos, const int& dir);
	void UpDate(std::string name);
	void Render(std::string name);
	const std::list<ShotData> GetShotList(void);
private:
	ShadowParam shadow_;
	std::map<std::string,int> interval_;
	ShooterType type_;
	std::list<ShotData> shotList_;
};

