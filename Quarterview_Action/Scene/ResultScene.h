#pragma once
#include "SceneBase.h"
class ResultScene:
	public SceneBase
{
public:
	ResultScene();
	ResultScene(bool alive);
	~ResultScene();
	unique_base Run(unique_base own);
private:
	bool aliveFlag;
};

