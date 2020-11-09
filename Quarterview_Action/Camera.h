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
	/*カメラ座標*/
	VECTOR _camera_pos;
	/*焦点座標*/
	VECTOR _target_pos;
	/*カメラ上方向*/
	VECTOR _camera_up_vec;

	VECTOR _camera_offset;

	shared_Player player_;
};

