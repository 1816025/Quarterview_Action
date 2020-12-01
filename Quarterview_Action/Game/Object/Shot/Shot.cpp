#include <DxLib.h>
#include <cmath>
#include "../../Field.h"
#include "Shot.h"

Shot::Shot(const VECTOR& pos, int dir,Param param,ShadowParam shadow,std::shared_ptr<Field> field)
{
	ShotBase::field_ = field;

	data_.pos = VGet(pos.x, pos.y,pos.z);
	data_.dir = dir;
	data_.speed = 20.0f;

	data_.id = MV1DuplicateModel(param.id);
	id_ = MV1DuplicateModel(shadow.id);
	MV1SetPosition(data_.id, data_.pos);
	MV1SetPosition(id_, data_.pos);
	MV1SetScale(id_, shadow.scl * 0.7f);
	SetRemove(false);
	Range_ = 60.0f;
}

Shot::~Shot()
{
}
