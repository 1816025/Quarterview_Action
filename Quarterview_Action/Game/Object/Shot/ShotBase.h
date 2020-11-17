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
	const bool IsRemove(void);
private:
	float rol;
protected:
	/*true: removeできる false: removeできない*/
	float Range;
	bool _is_remove;
	ShadowParam shadow_data_;
};

