#pragma once
#include <array>
#define lpKeyBoard KeyBoard::GetInstance()

class KeyBoard
{
public:
	static KeyBoard& GetInstance(void)
	{
		static KeyBoard s_Insrance;
		return s_Insrance;
	}

	bool UpDate(void);
	bool GetKeyTrigger(int key);
	bool GetKeyHold(int key);
private:
	std::array<char, 256>_key_data;
	std::array<char, 256>_key_data_old;
};

