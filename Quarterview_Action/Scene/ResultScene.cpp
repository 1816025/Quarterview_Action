#include "../Input/KeyBoard.h"
#include "TitleScene.h"
#include "ResultScene.h"

ResultScene::ResultScene()
{
}

ResultScene::ResultScene(bool alive)
{
	TRACE("Result\n")
	aliveFlag = alive;
}

ResultScene::~ResultScene()
{
}

unique_base ResultScene::Run(unique_base own)
{
	lpKeyBoard.UpDate();
	if (lpKeyBoard.GetKeyTrigger(KEY_INPUT_SPACE))
	{
		return std::make_unique<TitleScene>();
	}
	return std::move(own);
}