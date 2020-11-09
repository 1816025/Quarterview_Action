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

bool Actor::Init(const int& id, const int& shadow)
{
	data_ =
	{
		id,
		6,
		0.0f,
		VGet(50.0f,0.0f,50.0f),
		VGet((DX_PI_F / 180 * -90),((DX_PI_F / 180) * ((6 * 45) - 90)),0.0f),
		VGet(1.0f,1.0f,1.0f)
	};
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