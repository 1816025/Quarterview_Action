#include "Sky.h"

Sky::Sky()
{
	auto id = MV1LoadModel("model/sky/sky1.mv1");
	data_ = {
		id,
		6,
		0.0f,
		VGet(0.0f,-50.0f,0.0f),
		VGet(0.0f,0.0f,0.0f),
		VGet(50.0f,50.0f,50.0f)
	};
	MV1SetScale(data_.id, data_.scl);
	MV1SetRotationXYZ(data_.id, data_.rol);
	MV1SetPosition(data_.id, data_.pos);
}

Sky::~Sky()
{
}

	auto rol = 0.0f;
void Sky::Render(void)
{
	MV1SetRotationXYZ(data_.id, VGet(data_.rol.x, ((DX_PI_F / 180) * (rol+= 0.01)), data_.rol.z));
	MV1SetPosition(data_.id, data_.pos);
	MV1DrawModel(data_.id);
}
