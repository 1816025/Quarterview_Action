#include <DxLib.h>
#include "common.h"

#include "Input/KeyBoard.h"

#include "Game/Object/Actor/Player.h"
#include "Game/Object/Actor/Actor.h"
#include "Camera.h"

Camera::Camera(const shared_Player player)
{
	player_ = player;
	_camera_offset = VGet(0.0f, 0.0f, 0.0f);
	_camera_pos = VGet(900.0f, 900.0f, -750.0f);
	_target_pos = VGet(0.0f, 0.0f, 0.0f);
	_camera_up_vec = VGet(0.0f, 1.0f, 0.0f);
}

Camera::~Camera()
{
}

void Camera::UpDate()
{
	lpKeyBoard.UpDate();

	//_camera_offset.z += ((lpKeyBoard.GetKeyTrigger(KEY_INPUT_UP)	|| lpKeyBoard.GetKeyTrigger(KEY_INPUT_W)) ? 100.0f : 0.0f);
	//_camera_offset.x -= ((lpKeyBoard.GetKeyTrigger(KEY_INPUT_LEFT)	|| lpKeyBoard.GetKeyTrigger(KEY_INPUT_A)) ? 100.0f : 0.0f);
	//_camera_offset.z -= ((lpKeyBoard.GetKeyTrigger(KEY_INPUT_DOWN)	|| lpKeyBoard.GetKeyTrigger(KEY_INPUT_S)) ? 100.0f : 0.0f);
	//_camera_offset.x += ((lpKeyBoard.GetKeyTrigger(KEY_INPUT_RIGHT) || lpKeyBoard.GetKeyTrigger(KEY_INPUT_D)) ? 100.0f : 0.0f);
	//
	VECTOR target_pos = player_->GetPos();
	VECTOR cam_pos = _camera_pos + target_pos;


	DrawLine3D(target_pos,target_pos + VGet(100.0f,0,0), 0xff0000);
	DrawLine3D(target_pos,target_pos + VGet(0,100.0f,0), 0x00ff00);
	DrawLine3D(target_pos,target_pos + VGet(0,0,100.0f), 0x0000ff);

	SetCameraScreenCenter(SCREEN_SIZE_X / 3, SCREEN_SIZE_Y / 3 * 2);
	SetupCamera_Ortho(1400.0f);
	SetCameraPositionAndTargetAndUpVec(cam_pos, target_pos, _camera_up_vec);
}
