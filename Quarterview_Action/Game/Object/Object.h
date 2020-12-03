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

