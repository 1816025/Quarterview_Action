#pragma once
#include <mutex>
#include <list>

class Enemy1;

class EnemyMng
{
public:
	EnemyMng();
	~EnemyMng();
	void UpDate(void);
	void Render(void);
	
};

