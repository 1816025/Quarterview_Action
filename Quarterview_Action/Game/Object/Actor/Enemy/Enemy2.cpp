#include <DxLib.h>
#include "../../../Object/Shot/ShotMng.h"
#include "../../../Field.h"
#include "Enemy2.h"

Enemy2::Enemy2()
{
	int a = 0;
}

Enemy2::Enemy2(const shared_Field field,const shared_ShotMng shotmng)
{
	name_ = "Itako";
	field_ = field;
	shotmng_ = shotmng;
	auto id = MV1LoadModel("model/itako/itako.mv1");
	auto shadow = MV1LoadModel("model/shadow/shadow.mv1");
	Param data = {
		id,
		6,
		0.0f,
		VGet(500.0f,0.0f,200.0f),
		VGet(0.0f, (DX_PI_F / 180 * ((6 * 45) -90)), 0.0f),
		VGet(1.0f,1.0f,1.0f)
	};
	Init(id, shadow,data);
}

void Enemy2::UpDate(void)
{
	shotmng_->AddBullet(name_, data_.pos, data_.dir);
	Actor::UpDate();
}

Enemy2::~Enemy2()
{
}
