#include <DxLib.h>
#include "Mouse.h"

bool Mouse::UpDate(void)
{
	mouse_input_old = mouse_input;
	mouse_input = GetMouseInput() & MOUSE_INPUT_LEFT;

	return true;
}

bool Mouse::GetMouseTrigger(void)
{
	return mouse_input & ~mouse_input_old;
}

bool Mouse::GetMouseHold(void)
{
	return mouse_input;
}
