#pragma once
#include "SceneBase.h"
class Camera;
class TitleScene:
	public SceneBase
{
public:
	TitleScene();
	TitleScene(std::shared_ptr<Field> field);
	~TitleScene();
	unique_base Run(unique_base own);
	void Render(void);
	void Init();
private:
	void DrawFilter();
	int screen;
	int titleImage;
	int size;
	std::shared_ptr<Camera>camera_;
};

