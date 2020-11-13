#include "ShotBase.h"

ShotBase::ShotBase()
{
}

ShotBase::~ShotBase()
{
}

void ShotBase::UpDate(void)
{
	Range--;
	data_.pos.x += cos((DX_PI_F / 180) * (data_.dir * 45)) * data_.speed;
	data_.pos.z -= sin((DX_PI_F / 180) * (data_.dir * 45)) * data_.speed;
	if (Range < 0)
	{
		_is_remove = true;
	}
	MV1SetPosition(id_, VGet(data_.pos.x, 0, data_.pos.z));
}

void ShotBase::Render(void)
{
	Object::Render();
	DrawSphere3D(data_.pos, 10, 4, 0xff0000, 0xff0000, true);
}
