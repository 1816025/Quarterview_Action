#pragma once
#include <mutex>

class Field;
class Camera;
class Player;
class Enemy1;
class GameScene
{
public:
	GameScene();
	~GameScene();

	void Run(void);
private:
	void Render(void);

	//Fieldのポインタ
	std::shared_ptr<Field> field_;
	//Cameraのポインタ
	std::shared_ptr<Camera> camera_;
	std::shared_ptr<Player> player_;
	std::shared_ptr<Enemy1> enemy1_;
};

