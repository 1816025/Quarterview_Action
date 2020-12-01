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
	bool SetRemove(bool flag);
private:
	float rol;
protected:
	/*true: removeできる false: removeできない*/
	float Range_;
	bool isRemove_;
	ShadowParam shadowData_;
};

