#include <DxLib.h>
#include "Application.h"

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	//�ÓI�m��
	Application App;
	if (App.SysInit() == false)
	{
		//���s������I��
		return 0;
	}

	App.Run();
	App.ShutDown();
	return 0;
}