#include <DxLib.h>
#include "../../../Object/Shot/ShotMng.h"
#include "../../../Field.h"
#include "Enemy2.h"

Enemy2::Enemy2()
{
}

Enemy2::Enemy2(const shared_Field field)
{
	name_ = "Itako";
	field_ = field;
	shotmng_ = std::make_shared<ShotMng>(field_);
	auto id = MV1LoadModel("model/itako/itako.mv1");
	auto shadow = MV1LoadModel("model/shadow/shadow.mv1");
	Param data = {
		id,
		6,
		0.0f,
		VGet(100.0f,0.0f,200.0f),
		VGet(0.0f, (DX_PI_F / 180 * ((6 * 45) -90)), 0.0f),
		VGet(1.0f,1.0f,1.0f)
	};
	Init(id, shadow,data);
}

Enemy2::~Enemy2()
{
}
