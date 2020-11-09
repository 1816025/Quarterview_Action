#pragma once
#include <mutex>
#include <list>
#include "../../common.h"

class Shot;
class Field;
class ShotMng
{
public:
	ShotMng(std::shared_ptr<Field> field);
	~ShotMng();

	void AddBullet(const VECTOR& pos, const int& dir);
	void UpDate(void);
	void Render(void);
private:
	ShadowParam data_;
	int interval;
	std::shared_ptr<Field> field_;
	std::list<Shot*> shot_;
};

