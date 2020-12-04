#pragma once
#include <DxLib.h>
#include <mutex>

class Actor;
using shared_Player = std::shared_ptr<Actor>;
class Camera
{
public:
	Camera();
	Camera(const shared_Player player);
	~Camera();
	void UpDate();
	void DemoUpDate();
private:
	/*カメラ座標*/
	VECTOR cameraPos_;
	/*焦点座標*/
	VECTOR targetPos_;
	/*カメラ上方向*/
	VECTOR cameraUpVec_;

	VECTOR cameraOffset_;

	shared_Player player_;
};

