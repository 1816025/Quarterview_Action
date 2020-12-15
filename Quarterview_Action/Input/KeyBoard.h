#pragma once
#include <array>

class KeyBoard
{
public:
	KeyBoard();
	~KeyBoard();

	bool UpDate(void);
	bool GetKeyTrigger(int key);
	bool GetKeyHold(int key);
private:
	std::array<char, 256>_key_data;
	std::array<char, 256>_key_data_old;
};

