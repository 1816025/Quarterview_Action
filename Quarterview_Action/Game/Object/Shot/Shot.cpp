#include <DxLib.h>
#include <cmath>
#include "../../Field.h"
#include "Shot.h"

Shot::Shot(const VECTOR& pos, int dir,ShadowParam param,std::shared_ptr<Field> field)
{
	field_ = field;

	data_.pos = VGet(pos.x, pos.y + 80.0f,pos.z);
	data_.dir = dir;
	data_.speed = 20.0f;

	id_ = MV1DuplicateModel(param.id);
	MV1SetScale(id_, param.scl * 0.7f);
	MV1SetRotationXYZ(id_, VGet(0.0f, 0.0f, 0.0f));
	MV1SetPosition(id_, VGet(data_.pos.x,pos.y, data_.pos.x));
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
