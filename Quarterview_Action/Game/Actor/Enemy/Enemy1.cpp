#include <DxLib.h>
#include <cmath>
#include "../../../Game/Shot/ShotMng.h"
#include "../../Field.h"
#include "Enemy1.h"

Enemy1::Enemy1(const shared_Field field)
{
	field_ = field;
	shotmng_ = std::make_shared<ShotMng>(field_);
	auto id = MV1LoadModel("model/kiritan/kiritan.mv1");
	auto shadow = MV1LoadModel("model/shadow/shadow.mv1");
	Init(id, shadow);
}

Enemy1::~Enemy1()
{
}

void Enemy1::UpDate()
{
	Actor::UpDate();
	play_time_ += 1.0f;
	if (play_time_ >= total_time_)
	{
		play_time_ = 0.0f;
	}

	jump_force_ += gravity_;
	data_.pos.y -= jump_force_;
	if (field_->isBlock(data_.pos) && state_ != STATE::FALL)
	{
		if (data_.pos.y <= 0)
		{
			state_ = STATE::LANDING;
			jump_force_ = 0;
			data_.pos.y = 0.0f;
		}
	}

	if (data_.pos.y < 0)
	{
		state_ = STATE::FALL;
	}
	data_.rol = VGet((DX_PI_F / 180 * -90), ((DX_PI_F / 180) * ((data_.dir * 45) - 90)), 0.0f);
	MV1SetRotationXYZ(data_.id, data_.rol);
	MV1SetPosition(data_.id, data_.pos);
	MV1SetAttachAnimTime(data_.id, attach_Index_, play_time_);

	MV1SetPosition(id_, VGet(data_.pos.x, 0.0f, data_.pos.z));
	MV1SetAttachAnimTime(id_, attach_Index_, play_time_);

	if (shotmng_ != nullptr)
	{
		shotmng_->UpDate();
	}
}

