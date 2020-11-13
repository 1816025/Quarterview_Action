#include <DxLib.h>
#include "../../Field.h"
#include "Shot.h"
#include "ShotMng.h"

ShotMng::ShotMng(std::shared_ptr<Field> field)
{
	data_ =
	{
		MV1LoadModel("model/shadow/shadow.mv1"),
		VGet(0.0f,0.0f,0.0f),
		VGet(1.0f,1.0f,1.0f),
		VGet(0.3f,1.0f,0.3f)
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
		data_.pos = pos;
		shot_.push_front(new Shot(pos, dir,data_,field_));
	}
}

void ShotMng::UpDate(void)
{
	if (!shot_.empty())
	{
		for (auto itr = shot_.begin(); itr != shot_.end(); )
		{
			(*itr)->UpDate();
			if ((*itr)->IsRemove())
			{
				itr = shot_.erase(itr);
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
	DrawFormatString(0, 0, 0xff0000, "_shot.size() == %d", shot_.size());
	if (!shot_.empty())
	{
		for (auto shot : shot_)
		{
			shot->Render();
		}
	}
}
