#pragma once
#include <DxLib.h>
#include <mutex>
#include "../_debug/_DebugConOut.h"
#include "../common.h"
#include "../Game/Field.h"
class KeyBoard;

class SceneBase;
class Field;
using unique_base = std::unique_ptr<SceneBase>;
class SceneBase
{
public:
	SceneBase();
	~SceneBase();
	virtual unique_base Run(unique_base own, std::unique_ptr<KeyBoard>& keyboad) = 0;
	virtual void Render(void) = 0;
	bool finalFlag_;
protected:
	//Fieldのポインタ
	std::shared_ptr<Field> field_;
};

