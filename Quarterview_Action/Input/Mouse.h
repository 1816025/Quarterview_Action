#pragma once
#define lpMouse Mouse::GetInstance()
class Mouse
{
public:
	static Mouse& GetInstance(void)
	{
		static Mouse s_Insrance;
		return s_Insrance;
	}

	bool UpDate(void);
	bool GetMouseTrigger(void);
	bool GetMouseHold(void);
private:
	bool mouse_input;
	bool mouse_input_old;
};

