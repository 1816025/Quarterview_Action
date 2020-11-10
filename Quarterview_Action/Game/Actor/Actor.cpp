#include <DxLib.h>
#include "../Field.h"
#include "../Shot/ShotMng.h"
#include "Actor.h"

Actor::Actor()
{
}

Actor::~Actor()
{
}

bool Actor::Init(const int& id, const int& shadow, const Param& data)
{
	data_ = data;
	id_ = shadow;
	jump_flag_ = false;
	gravity_ = 0.25;
	jump_force_ = 0;
	state_ = STATE::LANDING;
	MV1SetScale(id_, data_.scl * 0.7f);
	MV1SetRotationXYZ(id_, VGet(0.0f, 0.0f, 0.0f));
	MV1SetPosition(id_, VGet(data_.pos.x, 0.0f, data_.pos.x));
	MV1SetScale(data_.id, data_.scl);
	MV1SetRotationXYZ(data_.id, data_.rol);
	MV1SetPosition(data_.id, data_.pos);
	anim_no_ = 7;
	Animation(anim_no_);
	return true;
}

void Actor::UpDate(void)
{
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

	data_.rol = VGet(data_.rol.x, ((DX_PI_F / 180) * ((data_.dir * 45) - 90)),data_.rol.z);
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

void Actor::Render()
{
	if (field_->isBlock(data_.pos))
	{
		MV1DrawModel(id_);
	}
	MV1DrawModel(data_.id);

	VECTOR pos = ConvWorldPosToScreenPos(VGet(data_.pos.x, data_.pos.y + 500.0f, data_.pos.z));
	DrawFormatString(pos.x, pos.y, 0x8888ff, "pos.x: %5.3f\npos.y: %5.3f\npos.z: %5.3f", data_.pos.x, data_.pos.y, data_.pos.z);

	if (shotmng_ != nullptr)
	{
		shotmng_->Render();
	}
}

void Actor::Animation(int no)
{
	MV1DetachAnim(data_.id, attach_Index_);
	attach_Index_ = MV1AttachAnim(data_.id, no, -1);
	total_time_ = MV1GetAttachAnimTotalTime(data_.id, attach_Index_);
	play_time_ = 0;
	MV1SetAttachAnimTime(data_.id, attach_Index_, play_time_);
}