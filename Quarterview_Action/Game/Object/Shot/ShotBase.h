#pragma once
#include "../Object.h"
class ShotBase
	:public Object
{
public:
	ShotBase();
	~ShotBase();
	void UpDate(void);
	void Render(void);
protected:
	/*true: remove�ł��� false: remove�ł��Ȃ�*/
	float Range;
	bool _is_remove;
	ShadowParam shadow_data_;
};

