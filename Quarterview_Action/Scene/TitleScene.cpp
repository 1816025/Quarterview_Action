#include "../Input/KeyBoard.h"
#include "GameScene.h"
#include "TitleScene.h"

TitleScene::TitleScene()
{
	GetFileList("model");
	field_ = std::make_shared<Field>(GetTextureList());
	Init();
}

TitleScene::TitleScene(std::shared_ptr<Field> field)
{
	field_ = field;
	Init();
}

TitleScene::~TitleScene()
{
}

unique_base TitleScene::Run(unique_base own)
{
	lpKeyBoard.UpDate();
	if (lpKeyBoard.GetKeyTrigger(KEY_INPUT_SPACE))
	{
		return std::make_unique<GameScene>(field_);
	}

	SetDrawScreen(screen);
	field_->Render();
	SetDrawScreen(DX_SCREEN_BACK);
	GraphFilter(screen, DX_GRAPH_FILTER_MONO,0,0);
	GraphFilter(screen, DX_GRAPH_FILTER_GAUSS,8,200);
	DrawGraph(0, 0, screen,true);
	DrawGraph(SCREEN_SIZE_X/2 - size/2, SCREEN_SIZE_Y/4, titleImage, true);
	return std::move(own);
}

void TitleScene::Init()
{
	TRACE("TitleScene\n");
	screen = MakeScreen(SCREEN_SIZE_X,SCREEN_SIZE_Y,true);
	titleImage = LoadGraph("image/title.png");
	auto y = 0;
	GetGraphSize(titleImage, &size, &y);
}

void TitleScene::Render(void)
{
}
