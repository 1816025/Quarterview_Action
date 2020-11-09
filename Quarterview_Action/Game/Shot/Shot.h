#pragma once
#include "../../common.h"
class Shot
{
public:
	Shot(const VECTOR& pos,int dir,ShadowParam param,std::shared_ptr<Field> field);
	~Shot();
	const bool IsRemove(void);
	void UpDate(void);
	void Render(void);
private:
	/*true: remove‚Å‚«‚é false: remove‚Å‚«‚È‚¢*/
	float Range;
	bool _is_remove;
	ShadowParam shadow_data_;
	Param data_;

	std::shared_ptr<Field> field_;
};

