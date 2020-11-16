#pragma once
#include "ShotBase.h"
#include "../../../common.h"
class Shot
	:public	ShotBase
{
public:
	Shot(const VECTOR& pos,int dir,ShadowParam param,std::shared_ptr<Field> field);
	~Shot();
	const bool IsRemove(void);
	/*virtual void UpDate(void) = 0;
	virtual void Render(void) = 0;*/
private:
};

