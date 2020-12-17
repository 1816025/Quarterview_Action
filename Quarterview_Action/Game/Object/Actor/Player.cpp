#include <DxLib.h>
#include <cmath>
#include "../../../Input/Mouse.h"
#include "../Shot/ShotMng.h"
#include "../../Field.h"
#include "Player.h"

Player::Player(const shared_Field field)
{
	auto id = MV1LoadModel("model/kiritan/kiritan.mv1");
	auto shadow = MV1LoadModel("model/shadow/shadow.mv1");
	Param data = {
		id,
		6,
		0.0f,
		VGet(150.0f,0.0f,50.0f),
		VGet((DX_PI_F / 180 * -90),((DX_PI_F / 180) * ((6 * 45) - 90)),0.0f),
		VGet(1.0f,1.0f,1.0f)
	};
	Init(id,shadow,data);

	name_ = "Player";
	lifePoint_ = 10;
	field_ = field;
	data.id = MV1LoadModel("model/bullet/bullet2.mv1");
	shotmng_ = std::make_shared<ShotMng>(ShooterType::PLAYER,data.id,field_);
}

Player::~Player()
{
}

void Player::UpDate(std::unique_ptr<KeyBoard>& keyboad)
{
	lpMouse.UpDate();
	Object::UpDate();
	data_.dir = ((keyboad->GetKeyHold(KEY_INPUT_UP) || keyboad->GetKeyHold(KEY_INPUT_W)) ? 6 : data_.dir);
	data_.dir = ((keyboad->GetKeyHold(KEY_INPUT_LEFT) || keyboad->GetKeyHold(KEY_INPUT_A)) ? 4 : data_.dir);
	data_.dir = ((keyboad->GetKeyHold(KEY_INPUT_DOWN) || keyboad->GetKeyHold(KEY_INPUT_S)) ? 2 : data_.dir);
	data_.dir = ((keyboad->GetKeyHold(KEY_INPUT_RIGHT) || keyboad->GetKeyHold(KEY_INPUT_D)) ? 0 : data_.dir);
	
	if ((keyboad->GetKeyHold(KEY_INPUT_UP) || keyboad->GetKeyHold(KEY_INPUT_W))
		&& (keyboad->GetKeyHold(KEY_INPUT_RIGHT) || keyboad->GetKeyHold(KEY_INPUT_D)))
	{
		data_.dir = 7;
	}
	else if ((keyboad->GetKeyHold(KEY_INPUT_UP) || keyboad->GetKeyHold(KEY_INPUT_W))
		&& (keyboad->GetKeyHold(KEY_INPUT_LEFT) || keyboad->GetKeyHold(KEY_INPUT_A)))
	{
		data_.dir = 5;
	}
	else if ((keyboad->GetKeyHold(KEY_INPUT_DOWN) || keyboad->GetKeyHold(KEY_INPUT_S))
			&& (keyboad->GetKeyHold(KEY_INPUT_LEFT) || keyboad->GetKeyHold(KEY_INPUT_A)))
	{
		data_.dir = 3;
	}
	else if (keyboad->GetKeyHold(KEY_INPUT_DOWN) || keyboad->GetKeyHold(KEY_INPUT_S)
		&& (keyboad->GetKeyHold(KEY_INPUT_RIGHT) || keyboad->GetKeyHold(KEY_INPUT_D)))
	{
		data_.dir = 1;
	}

	if ((keyboad->GetKeyHold(KEY_INPUT_UP) || keyboad->GetKeyHold(KEY_INPUT_W))
		|| (keyboad->GetKeyHold(KEY_INPUT_LEFT) || keyboad->GetKeyHold(KEY_INPUT_A))
		|| (keyboad->GetKeyHold(KEY_INPUT_DOWN) || keyboad->GetKeyHold(KEY_INPUT_S))
		|| (keyboad->GetKeyHold(KEY_INPUT_RIGHT) || keyboad->GetKeyHold(KEY_INPUT_D)))
	{
		auto npos_x = data_.pos.x - std::sin(data_.rol.y) * 5.0;
		auto npos_z = data_.pos.z - std::cos(data_.rol.y) * 5.0;
		if (state_==STATE::LANDING)
		{
			if (field_->isBlock(npos_x, data_.pos.y, npos_z))
			{
				data_.pos.x = npos_x;
				data_.pos.z = npos_z;
			}
		}
		else
		{
			data_.pos.x -= std::sin(data_.rol.y) * 5.0;
			data_.pos.z -= std::cos(data_.rol.y) * 5.0;
		}
		if (anim_no_ != 7)
		{
			anim_no_ = 7;
			Animation(anim_no_);
		}
	}
	else
	{
		if (anim_no_ != 1)
		{
			anim_no_ = 1;
			Animation(anim_no_);
		}
	}
	if (keyboad->GetKeyTrigger(KEY_INPUT_SPACE) && state_ == STATE::LANDING)
	{
		state_ = STATE::JUMP;
		jump_force_ = -10;
	}
	if (lpMouse.GetMouseHold())
	{
		shotmng_->AddBullet(name_,data_.pos, data_.dir);
	}
}

void Player::Shift_Dir(void)
{
}
