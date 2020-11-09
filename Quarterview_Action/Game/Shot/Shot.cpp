#include <DxLib.h>
#include <cmath>
#include "../Field.h"
#include "Shot.h"

Shot::Shot(const VECTOR& pos, int dir,ShadowParam param,std::shared_ptr<Field> field)
{
	field_ = field;

	data_.pos = VGet(pos.x, pos.y + 80.0f,pos.z);
	data_.dir = dir;
	data_.speed = 20.0f;

	shadow_data_.id = MV1DuplicateModel(param.id);
	shadow_data_.pos = VGet(data_.pos.x,pos.y, data_.pos.z);
	shadow_data_.rol = param.rol;
	shadow_data_.scl = param.scl;

	MV1SetScale(shadow_data_.id, shadow_data_.scl * 0.7f);
	MV1SetRotationXYZ(shadow_data_.id, VGet(0.0f, 0.0f, 0.0f));
	MV1SetPosition(shadow_data_.id, shadow_data_.pos);

	_is_remove = false;
	Range = 60.0f;
}

Shot::~Shot()
{
}

const bool Shot::IsRemove(void)
{
	return _is_remove;
}

void Shot::UpDate(void)
{
	Range--;
	data_.pos.x += cos((DX_PI_F / 180) * (data_.dir * 45)) * data_.speed;
	data_.pos.z -= sin((DX_PI_F / 180) * (data_.dir * 45)) * data_.speed;
	if (Range < 0)
	{
		_is_remove = true;
	}
	MV1SetPosition(shadow_data_.id, VGet(data_.pos.x,0, data_.pos.z));
}

void Shot::Render(void)
{
	if (field_->isBlock(data_.pos))
	{
		MV1DrawModel(shadow_data_.id);
	}
	DrawSphere3D(data_.pos, 10, 4, 0xff0000, 0xff0000, true);
}
