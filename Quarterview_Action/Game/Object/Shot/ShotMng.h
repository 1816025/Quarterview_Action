#pragma once
#include <mutex>
#include <list>
#include "../Object.h"
#include "../../../common.h"

class Shot;
class Field;
class ShotMng
	:public Object
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
	std::list<Shot*> shot_;
};

