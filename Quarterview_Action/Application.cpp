#include <DxLib.h>

#include "common.h"
#include "Input/KeyBoard.h"
#include "Scene/SceneBase.h"
#include "Scene/TitleScene.h"
#include "Application.h"

Application::~Application()
{
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

	SetUseZBuffer3D(true);		//Z�o�b�t�@�L����
	SetWriteZBuffer3D(true);	//Z�o�b�t�@�ւ̏������ݗL����
	SetUseBackCulling(true);	//�o�b�N�J�����O�̗L����
	SetUseLighting(false);		//���C�e�B���O�̖�����
	SetBackgroundColor(0, 0, 0);

	return true;
}

void Application::Run(void)
{
	unique_base scene = std::make_unique<TitleScene>();
	auto keyboard = std::make_unique<KeyBoard>();
	while (ProcessMessage() != -1 && !isShutDown())
	{
		keyboard->UpDate();
		ClearDrawScreen();
		scene = scene->Run(move(scene),keyboard);
		scene->Render();
		ScreenFlip();
	}
}

bool Application::isShutDown(void)
{
	std::string pass;
	if (CheckHitKey(KEY_INPUT_ESCAPE))
	{
		char password[16] = "\0";
		DrawBox(0, SCREEN_SIZE_Y - 32, 16 * 16, SCREEN_SIZE_Y, 0x00, true);
		DrawString(0, SCREEN_SIZE_Y - 32, "password: ", 0xffffff);
		KeyInputString(0, SCREEN_SIZE_Y - 16, 16, password, false);
		pass = password;
	}
	//�w�肳�ꂽpassword�Ɠ����ł���ΏI������
	return (pass == "yumeusagi" ? true : false);
}

void Application::ShutDown(void)
{
	DxLib_End();
}
