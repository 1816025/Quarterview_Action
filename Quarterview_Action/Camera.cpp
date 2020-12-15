#include <DxLib.h>
#include "common.h"

#include "Input/KeyBoard.h"

#include "Game/Object/Actor/Player.h"
#include "Game/Object/Actor/Actor.h"
#include "Camera.h"

Camera::Camera()
{
	cameraOffset_ = VGet(0.0f, 0.0f, 0.0f);
	cameraPos_ = VGet(0.0f, 400.0f, -750.0f);
	targetPos_ = VGet(-250.0f,0.0f, 0.0f);
	cameraUpVec_ = VGet(0.0f, 1.0f, 0.0f);
}

Camera::Camera(const shared_Player player)
{
	player_ = player;
	cameraOffset_ = VGet(0.0f, 0.0f, 0.0f);
	cameraPos_ = VGet(900.0f, 900.0f, -750.0f);
	targetPos_ = VGet(0.0f, 0.0f, 0.0f);
	cameraUpVec_ = VGet(0.0f, 1.0f, 0.0f);
}

Camera::~Camera()
{
}

void Camera::UpDate()
{
	VECTOR target_pos = player_->GetPos();
	VECTOR cam_pos = cameraPos_ + target_pos;
	SetCameraScreenCenter(SCREEN_SIZE_X / 3, SCREEN_SIZE_Y / 3 * 2);
	SetupCamera_Ortho(1400.0f);
	SetCameraPositionAndTargetAndUpVec(cam_pos, target_pos, cameraUpVec_);
}

void Camera::DemoUpDate()
{
	targetPos_.z++;
	VECTOR cam_pos = cameraPos_+ targetPos_;
	SetCameraScreenCenter(SCREEN_SIZE_X /10, SCREEN_SIZE_Y);
	SetupCamera_Ortho(700.0f);
	SetCameraPositionAndTargetAndUpVec(cam_pos,targetPos_, cameraUpVec_);
}
