#include <DxLib.h>
#include "../../Field.h"
#include "../../Object/Shot/ShotMng.h"
#include "Enemy/EnemyBase.h"
#include "Enemy/Enemy1.h"
#include "Enemy/Enemy2.h"
#include "Actor.h"

Actor::Actor()
{
}

Actor::Actor(const shared_Field field, std::vector<std::string> modelList)
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
void Actor::Render(void)
{
	Render(name_);
}
void Actor::Render(std::string name)
{
	Object::Render();
	MV1DrawModel(data_.id);
	DrawStatus();
	if (shotmng_ != nullptr)
	{
		shotmng_->Render(name);
	}
}

void Actor::UpDate(void)
{
		shotmng_->AddBullet(name_, data_.pos, data_.dir);
		Object::UpDate();
}

void Actor::DrawStatus()
{
	VECTOR pos = ConvWorldPosToScreenPos(VGet(data_.pos.x, data_.pos.y + 500.0f, data_.pos.z));
	DrawFormatString(pos.x, pos.y, 0x8888ff, "name:%s\npos.x: %05.0f\npos.y: %05.0f\npos.z: %05.0f", name_.c_str(), data_.pos.x, data_.pos.y, data_.pos.z);
}

void Actor::Animation(int no)
{
	MV1DetachAnim(data_.id, attach_Index_);
	attach_Index_ = MV1AttachAnim(data_.id, no, -1);
	total_time_ = MV1GetAttachAnimTotalTime(data_.id, attach_Index_);
	play_time_ = 0;
	MV1SetAttachAnimTime(data_.id, attach_Index_, play_time_);
}