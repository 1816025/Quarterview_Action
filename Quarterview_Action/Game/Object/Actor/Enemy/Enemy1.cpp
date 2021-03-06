#include <DxLib.h>
#include "../../Shot/ShotMng.h"
#include "../../../Field.h"
#include "Enemy1.h"

Enemy1::Enemy1()
{
}

Enemy1::Enemy1(const shared_Field& field,const shared_ShotMng& shotmng)
{
	auto id = MV1LoadModel("model/kiritan/kiritan.mv1");
	auto shadow = MV1LoadModel("model/shadow/shadow.mv1");
	Param data = {
		id,
		6,
		0.0f,
		VGet(50.0f,0.0f,50.0f),
		VGet((DX_PI_F / 180 * -90),((DX_PI_F / 180) * ((6 * 45) - 90)),0.0f),
		VGet(1.0f,1.0f,1.0f)
	};
	Init(id, shadow, data);

	name_ = "Kiritan";
	field_ = field;
	shotmng_ = shotmng;
}

Enemy1::~Enemy1()
{
	int a = 0;
}

void Enemy1::UpDate(void)
{
	shotmng_->AddBullet(name_, data_.pos, data_.dir);
	Actor::UpDate();
}

