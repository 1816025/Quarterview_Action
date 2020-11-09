#include <DxLib.h>
#include "KeyBoard.h"

bool KeyBoard::UpDate(void)
{
	_key_data_old = _key_data;
	GetHitKeyStateAll(&_key_data[0]);

	return true;
}

bool KeyBoard::GetKeyTrigger(int key)
{
	return (_key_data[key] & ~(_key_data_old[key]));
}

bool KeyBoard::GetKeyHold(int key)
{
	return (_key_data[key]);
}
