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
	MV1SetRotationXYZ(data_.id, VGet(data_.rol.x, ((DX_PI_F / 180) * (rol += 20)), data_.rol.z));
	MV1SetPosition(data_.id, VGet(data_.pos.x,data_.pos.y, data_.pos.z));
}

void ShotBase::Render(void)
{
	Object::Render();
	MV1DrawModel(data_.id);
}

const bool ShotBase::IsRemove(void)
{
	return _is_remove;
}

