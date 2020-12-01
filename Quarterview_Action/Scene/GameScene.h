#pragma once
#include <mutex>

class Field;
class Camera;
class Player;
class EnemyBase;
class Collision;
class Sky;
class GameScene
{
public:
	GameScene();
	~GameScene();

	void Run(void);
	void Render(void);
private:

	//Fieldのポインタ
	std::shared_ptr<Field> field_;
	//Cameraのポインタ
	std::shared_ptr<Camera> camera_;
	std::shared_ptr<Player> player_;
	std::shared_ptr<EnemyBase> enemy_;
	std::shared_ptr<Sky> sky_;
	std::unique_ptr<Collision> collision_;
};

