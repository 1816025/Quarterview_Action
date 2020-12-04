#include "../Input/KeyBoard.h"
#include "../Camera.h"
#include "GameScene.h"
#include "TitleScene.h"

TitleScene::TitleScene()
{
	GetFileList("model");
	field_ = std::make_shared<Field>(GetTextureList());
	camera_ = std::make_shared<Camera>();
	Init();
}

TitleScene::TitleScene(std::shared_ptr<Field> field)
{
	field_ = field;
	camera_ = std::make_shared<Camera>();
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
		camera_->~Camera();
		return std::make_unique<GameScene>(field_);
	}
	camera_->DemoUpDate();
	return std::move(own);
}

void TitleScene::Init()
{
	TRACE("TitleScene\n");
	//screen = MakeScreen(SCREEN_SIZE_X,SCREEN_SIZE_Y,true);
	titleImage = LoadGraph("image/title.png");
	auto y = 0;
	GetGraphSize(titleImage, &size, &y);
}

void TitleScene::Render(void)
{
	DrawFilter();
	DrawGraph(SCREEN_SIZE_X / 2 - size / 2, SCREEN_SIZE_Y / 4, titleImage, true);
	DrawGraph(0, 0, screen, true);
}

void TitleScene::DrawFilter()
{
	SetDrawScreen(screen);
	field_->DemoRender();
	SetDrawScreen(DX_SCREEN_BACK);
	GraphFilter(screen, DX_GRAPH_FILTER_MONO, 0, 0);
	GraphFilter(screen, DX_GRAPH_FILTER_GAUSS, 8, 200);
}
