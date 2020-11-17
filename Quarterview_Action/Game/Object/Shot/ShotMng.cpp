#include <DxLib.h>
#include "../../Field.h"
#include "Shot.h"
#include "EnemyShot.h"
#include "ShotMng.h"

ShotMng::ShotMng(ShooterType type,Param param, std::shared_ptr<Field> field)
{
	type_ = type;
	data_ = param;
	shadow_ =
	{
		MV1LoadModel("model/shadow/shadow.mv1"),
		VGet(0.0f,0.0f,0.0f),
		VGet(1.0f,1.0f,1.0f),
		VGet(0.5f,0.5f,0.5f)
	};
	field_ = field;
	interval = 0;
}

ShotMng::~ShotMng()
{
}

void ShotMng::AddBullet(const VECTOR& pos, const int& dir)
{
	interval++;
	if (interval % 2 == 0)
	{
		interval = 0;
		data_.pos = VGet(pos.x,pos.y +80.0f,pos.z);

		switch (type_)
		{
		case ShooterType::PLAYER:
			shotList_.push_front(new Shot(pos, dir,data_,shadow_, field_));
			break;
		case ShooterType::ENEMY:
			shotList_.push_front(new EnemyShot(pos, dir,data_,shadow_, field_));
			break;
		default:
			break;
		}
	}
}

void ShotMng::UpDate(void)
{
	if (!shotList_.empty())
	{
		for (auto itr = shotList_.begin(); itr != shotList_.end(); )
		{
			(*itr)->UpDate();
			if ((*itr)->IsRemove())
			{
				itr = shotList_.erase(itr);
			}
			else
			{
				++itr;
			}
		}
	}
}

void ShotMng::Render(void)
{
	DrawFormatString(0, 0, 0xff0000, "_shot.size() == %d", shotList_.size());
	if (!shotList_.empty())
	{
		for (auto shot : shotList_)
		{
			shot->Render();
		}
	}
}
