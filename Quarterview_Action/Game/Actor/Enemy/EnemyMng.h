#pragma once
#include <mutex>
#include <functional>
#include <map>
#include <list>

class Enemy1;
class Enemy2;

class EnemyMng
{
public:
	EnemyMng();
	~EnemyMng();
	void UpDate(void);
	void Render(void);
	void AddEnemy();
private:
	
};

