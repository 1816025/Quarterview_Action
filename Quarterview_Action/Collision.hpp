#pragma once
#include <mutex>
#include "common.h"
#include "../Game/Object/Shot/ShotMng.h"
#include "../Game/Object/Shot/ShotBase.h"


struct Collision
{
	bool SvsS(VECTOR pos_a, float r_a, VECTOR pos_b, float r_b)
	{
		float x = pos_a.x - pos_b.x;
		float y = pos_a.y - pos_b.y;
		float z = pos_a.z - pos_b.z;
		float r = r_a + r_b;

		if (x * x + y * y + z * z < r * r)
		{
			return true;
		}
		return false;
	};
	bool TvsS(VECTOR pos_a, float r_a, std::shared_ptr<ShotMng> shotmng, float r_b)
	{
		for (auto shot : shotmng->GetShotList())
		{
			if (SvsS(pos_a, r_a, shot.shot->GetPos(), r_b))
			{
				shot.shot->SetRemove(true);
				return true;
			}
		}
		return false;
	};
};
