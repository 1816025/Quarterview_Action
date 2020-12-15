#pragma once
#include "SceneBase.h"
class KeyBoard;
class ResultScene:
	public SceneBase
{
public:
	ResultScene();
	ResultScene(bool alive);
	~ResultScene();
	unique_base Run(unique_base own, std::unique_ptr<KeyBoard>& keyboad);
	void Render(void);
private:
	bool aliveFlag;
};

