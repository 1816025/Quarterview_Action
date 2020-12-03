#include "../../Field.h"
#include "ShotBase.h"

ShotBase::ShotBase()
{
}

ShotBase::~ShotBase()
{
}
void ShotBase::UpDate(std::shared_ptr<Field> field)
{
	Range_--;
	data_.pos.x += cos((DX_PI_F / 180) * (data_.dir * 45)) * data_.speed;
	data_.pos.z -= sin((DX_PI_F / 180) * (data_.dir * 45)) * data_.speed;
	if (Range_ < 0)
	{
		SetRemove(true);
	}
	SwitchGravity();

	MV1SetPosition(id_, VGet(data_.pos.x, 0, data_.pos.z));
	MV1SetRotationXYZ(data_.id, VGet(data_.rol.x, ((DX_PI_F / 180) * (rol += 20)), data_.rol.z));
	MV1SetPosition(data_.id, VGet(data_.pos.x,data_.pos.y + 40.0f, data_.pos.z));
}

void ShotBase::Render(void)
{
	Object::Render();
	MV1DrawModel(data_.id);
}

const bool ShotBase::IsRemove(void)
{
	return isRemove_;
}

bool ShotBase::SetRemove(bool flag)
{
	return isRemove_ = flag;
}

