#include <cmath>
#include "../../Field.h"
#include "EnemyShot.h"

EnemyShot::EnemyShot(const VECTOR& pos, int dir,Param param,ShadowParam shadow, std::shared_ptr<Field> field)
{
	ShotBase::field_ = field;
	data_.pos = VGet(pos.x, pos.y + 40.0f, pos.z);
	data_.dir = dir;
	data_.speed = 20.0f;
	data_.id = MV1DuplicateModel(param.id);
	id_ = MV1DuplicateModel(shadow.id);
	MV1SetScale(id_, shadow.scl * 0.7f);
	MV1SetRotationXYZ(id_, VGet(0.0f, 0.0f, 0.0f));
	MV1SetPosition(id_, VGet(data_.pos.x, pos.y, data_.pos.x));
	SetRemove(false);
	Range_ = 60.0f;
}

EnemyShot::~EnemyShot()
{
}
