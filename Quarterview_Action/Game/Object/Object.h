#pragma once
#include <mutex>
#include <list>
#include <string>
#include "../../common.h"

class ShotMng;
class Field;
using shared_Field = std::shared_ptr<Field>;
class Object
{
public:
	Object();
	~Object();

	const VECTOR& GetPos(void)
	{
		return data_.pos;
	}

	void UpDate(void);
	void Render(void);
	void Collision();
	const std::shared_ptr<ShotMng> GetShotMng(void)
	{
		return shotmng_;
	}
protected:
	void SwitchGravity();
	std::string name_;

	Param data_;

	int id_;			//�e��id

	int anim_no_;
	int attach_Index_;
	float total_time_;
	float play_time_;
	//�d��
	float gravity_;
	//�W�����v��
	float jump_force_;
	//�������x
	float fall_speed_;
	//�W�����v���Ă��邩
	bool jump_flag_;
	std::shared_ptr<ShotMng> shotmng_;
	shared_Field field_;
	STATE state_;
};

