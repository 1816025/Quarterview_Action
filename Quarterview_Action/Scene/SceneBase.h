#pragma once
#include <DxLib.h>
#include <mutex>
#include "../_debug/_DebugConOut.h"
#include "../common.h"
#include "../Game/Field.h"

class SceneBase;
class Field;
using unique_base = std::unique_ptr<SceneBase>;
class SceneBase
{
public:
	SceneBase();
	~SceneBase();
	virtual unique_base Run(unique_base own) = 0;
	bool finalFlag_;
protected:
	//Field‚Ìƒ|ƒCƒ“ƒ^
	std::shared_ptr<Field> field_;
};

