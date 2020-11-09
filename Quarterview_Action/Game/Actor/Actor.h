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

	int id_;			//影のid

	int anim_no_;
	int attach_Index_;
	float total_time_;
	float play_time_;
	//重力
	float gravity_;
	//ジャンプ力
	float jump_force_;
	//落下速度
	float fall_speed_;
	//ジャンプしているか
	bool jump_flag_;
	std::shared_ptr<ShotMng> shotmng_;
	shared_Field field_;
	STATE state_;
};

