#include "../Field.h"
#include "Shot/ShotMng.h"
#include "Object.h"

Object::Object()
{
}

Object::~Object()
{
}

void Object::UpDate(void)
{
	play_time_ += 1.0f;
	if (play_time_ >= total_time_)
	{
		play_time_ = 0.0f;
	}

	jump_force_ += gravity_;
	data_.pos.y -= jump_force_;
	if (field_->isBlock(data_.pos.x, data_.pos.y, data_.pos.z) && state_ != STATE::FALL)
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

	data_.rol = VGet(data_.rol.x, ((DX_PI_F / 180) * ((data_.dir * 45) - 90)), data_.rol.z);
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

void Object::Render()
{
	if (field_->isBlock(data_.pos.x, data_.pos.y, data_.pos.z))
	{
		MV1DrawModel(id_);
	}
}

