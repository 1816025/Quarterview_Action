#pragma once
#include <mutex>

class Field;
class Camera;
class Actor;
class EnemyBase;
class Sky;
class GameScene
{
public:
	GameScene();
	~GameScene();

	void Run(void);
	void UpDate(void);
	void Render(void);
private:

	//Field�̃|�C���^
	std::shared_ptr<Field> field_;
	//Camera�̃|�C���^
	std::shared_ptr<Camera> camera_;
	std::shared_ptr<Actor> player_;
	std::shared_ptr<Actor> enemy_;
	std::shared_ptr<Sky> sky_;
};

