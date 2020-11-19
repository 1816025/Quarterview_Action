#pragma once
#include <mutex>
#include <string>
#include "../Object.h"
#include "../../../common.h"

class ShotMng;
class Field;
class Object;
using shared_Field = std::shared_ptr<Field>;
class Actor
	:public Object
{
public:
	Actor();
	~Actor();
	bool Init(const int& id, const int& shadow,const Param& data);
	virtual void Render(std::string name);
	virtual void UpDate(void);
private:
	void DrawStatus();
protected:
	void Animation(int no);
};

