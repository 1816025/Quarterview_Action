#pragma once
#include <mutex>
#include <list>
#include <functional>
#include "../Actor.h"

class Field;
using shared_Field = std::shared_ptr<Field>;
class Enemy1;
class Enemy2;

enum class EnemyType
{
	Kiritan,
	Itako
};


class EnemyBase :
	public Actor
{
public:
	EnemyBase();
	EnemyBase(const shared_Field field,std::vector<std::string>modelList);
	virtual ~EnemyBase();
	void UpDate(void);
	void Render(void);
	void Spawner(EnemyType id);
	void Killer(std::shared_ptr<EnemyBase> enemy);
	const std::list<EnemyStatus> GetEnemyList(void);
private:
	int frame;/*

	std::shared_ptr<Enemy1> enemy1_;
	std::shared_ptr<Enemy2> enemy2_;
	std::list<EnemyStatus> enemyList_;*/
protected:
};

