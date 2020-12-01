#pragma once
#include <mutex>

class Actor;
using shared_Player = std::shared_ptr<Actor>;
class Camera
{
public:
	Camera(const shared_Player player);
	~Camera();
	void UpDate();
private:
	/*�J�������W*/
	VECTOR cameraPos_;
	/*�œ_���W*/
	VECTOR targetPos_;
	/*�J���������*/
	VECTOR cameraUpVec_;

	VECTOR cameraOffset_;

	shared_Player player_;
};

