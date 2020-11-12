#pragma once
#include <mutex>

class Field;
class Camera;
class Player;
class EnemyBase;
class GameScene
{
public:
	GameScene();
	~GameScene();

	void Run(void);
	void UpDate(void);
	void Render(void);
private:

	//Fieldのポインタ
	std::shared_ptr<Field> field_;
	//Cameraのポインタ
	std::shared_ptr<Camera> camera_;
	std::shared_ptr<Player> player_;
	std::shared_ptr<EnemyBase> enemy_;
};

