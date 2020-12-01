#include <DxLib.h>
#include "../../Field.h"
#include "Shot.h"
#include "EnemyShot.h"
#include "ShotMng.h"

ShotMng::ShotMng(ShooterType type,int id, std::shared_ptr<Field> field)
{
	field_ = field;
	type_ = type;
	data_.id = id;
	shadow_ =
	{
		MV1LoadModel("model/shadow/shadow.mv1"),
		VGet(0.0f,0.0f,0.0f),
		VGet(1.0f,1.0f,1.0f),
		VGet(0.5f,0.5f,0.5f)
	};
}

ShotMng::~ShotMng()
{
	int a = 0;
}

void ShotMng::AddBullet(const std::string name, const VECTOR& pos, const int& dir)
{
	auto a = name;
	interval_[name]++;
	if (interval_[name] % 10 == 0)
	{
		interval_[name] = 0;
		data_.pos = VGet(pos.x,pos.y +80.0f,pos.z);

		switch (type_)
		{
		case ShooterType::PLAYER:
			shotList_.push_front(ShotData{ name,new Shot(data_.pos, dir,data_,shadow_, field_) });
			break;
		case ShooterType::ENEMY:
			shotList_.push_front(ShotData{ name, new EnemyShot(pos, dir, data_, shadow_, field_)});
			break;
		default:
			break;
		}
	}
}

void ShotMng::UpDate(std::string name)
{
	if (!shotList_.empty())
	{
		for (auto itr = shotList_.begin(); itr != shotList_.end(); )
		{
			if ((*itr).unitName == name)
			{
				(*itr).shot->UpDate();
			}
			if ((*itr).shot->IsRemove())
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

void ShotMng::Render(std::string name)
{
	DrawFormatString(0, 0, 0xff0000, "_shot.size() == %d", shotList_.size());
	if (!shotList_.empty())
	{
		for (auto shot : shotList_)
		{
			if (shot.unitName == name)
			{
				shot.shot->Render();
			}
		}
	}
}

const std::list<ShotData> ShotMng::GetShotList(void)
{
	return shotList_;
}
