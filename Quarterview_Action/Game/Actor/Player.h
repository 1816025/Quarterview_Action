#pragma once
#include <mutex>
#include "Actor.h"
#include "../../common.h"

class ShotMng;
class Field;

using shared_Field = std::shared_ptr<Field>;
class Player:
	public Actor
{
public:
	Player(const shared_Field field);
	~Player();
	void UpDate();

	const VECTOR& GetPos(void)
	{
		return data_.pos;
	}
private:
	void Shift_Dir(void);
};
