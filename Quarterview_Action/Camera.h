#pragma once
#include <mutex>

class Player;
using shared_Player = std::shared_ptr<Player>;
class Camera
{
public:
	Camera(const shared_Player player);
	~Camera();
	void UpDate();
private:
	/*�J�������W*/
	VECTOR _camera_pos;
	/*�œ_���W*/
	VECTOR _target_pos;
	/*�J���������*/
	VECTOR _camera_up_vec;

	VECTOR _camera_offset;

	shared_Player player_;
};

