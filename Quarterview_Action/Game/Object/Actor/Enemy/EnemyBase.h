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
	struct EnemyStatus
	{
		std::string name;
		std::shared_ptr<EnemyBase> ptr;
	};
	EnemyBase();
	EnemyBase(const shared_Field field);
	~EnemyBase();
	void UpDate(void);
	void Render(void);
	void Spawner(EnemyType id);
private:
	int frame;

	std::shared_ptr<Enemy1> enemy1_;
	std::shared_ptr<Enemy2> enemy2_;
	std::list<EnemyStatus> enemyList_;
protected:
};

