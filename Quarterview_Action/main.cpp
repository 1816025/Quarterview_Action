#include <DxLib.h>
#include "Application.h"

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	//ê√ìIämï€
	Application App;
	if (App.SysInit() == false)
	{
		//é∏îsÇµÇΩÇÁèIóπ
		return 0;
	}

	App.Run();
	App.ShutDown();
	return 0;
}