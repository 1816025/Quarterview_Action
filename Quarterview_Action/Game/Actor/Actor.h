#pragma once
#include <mutex>
#include "../../common.h"

class ShotMng;
class Field;

using shared_Field = std::shared_ptr<Field>;
class Actor
{
public:
	Actor();
	~Actor();
	bool Init(const int& id, const int& shadow);
	void UpDate(void);
	void Render(void);

	const VECTOR& GetPos(void)
	{
		return data_.pos;
	}
protected:
	void Animation(int no);
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

