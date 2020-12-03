#pragma once
#include "SceneBase.h"
class TitleScene:
	public SceneBase
{
public:
	TitleScene();
	TitleScene(std::shared_ptr<Field> field);
	~TitleScene();
	unique_base Run(unique_base own);
	void Init();
private:
	void Render(void);
	int screen;
	int titleImage;
	int size;
};

