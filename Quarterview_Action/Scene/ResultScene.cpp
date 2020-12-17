#include "../Input/KeyBoard.h"
#include "TitleScene.h"
#include "ResultScene.h"

ResultScene::ResultScene()
{
}

ResultScene::ResultScene(bool alive)
{
	TRACE("Result(%s)\n",alive?"clear":"dead");
	aliveFlag = alive;
}

ResultScene::~ResultScene()
{
}

unique_base ResultScene::Run(unique_base own, std::unique_ptr<KeyBoard>& keyboad)
{
	if (keyboad->GetKeyTrigger(KEY_INPUT_SPACE))
	{
		return std::make_unique<TitleScene>();
	}
	return std::move(own);
}

void ResultScene::Render(void)
{
}
