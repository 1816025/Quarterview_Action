#include <DxLib.h>

#include "common.h"

#include "Scene/GameScene.h"
#include "Application.h"

Application::~Application()
{
	if (_game != nullptr)
	{
		delete _game;
		_game = nullptr;
	}
}

bool Application::SysInit(void)
{
	SetWindowText(WINDOW_NAME);
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	DxLib::ChangeWindowMode(true);
	if (DxLib_Init() == -1) {
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);

	SetUseZBuffer3D(true);		//Zバッファ有効化
	SetWriteZBuffer3D(true);	//Zバッファへの書き込み有効化
	SetUseBackCulling(true);	//バックカリングの有効化
	SetUseLighting(false);		//ライティングの無効化
	SetBackgroundColor(0, 0, 0);
	if (_game == nullptr)
	{
		_game = new GameScene();
	}

	return true;
}

void Application::Run(void)
{
	while (ProcessMessage() != -1) {
		ClearDrawScreen();
		_game->Run();
		ScreenFlip();
	}
}

void Application::ShutDown(void)
{
	DxLib_End();
}
