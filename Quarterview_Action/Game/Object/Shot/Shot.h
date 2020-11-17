#pragma once
#include "ShotBase.h"
#include "../../../common.h"
class Shot
	:public	ShotBase
{
public:
	Shot(const VECTOR& pos,int dir,Param param,ShadowParam shadow,std::shared_ptr<Field> field);
	~Shot();
private:
};

