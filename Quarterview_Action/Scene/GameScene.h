#pragma once
#include "SceneBase.h"

class KeyBoad;

class Field;
class Camera;
class Player;
class EnemyBase;
class Collision;
class Sky;
class GameScene:
	public SceneBase
{
public:
	GameScene();
	GameScene(std::shared_ptr<Field> field);
	~GameScene();
	unique_base Run(unique_base own, std::unique_ptr<KeyBoard>& keyboad);
	void isHit(void);
	void Render(void);
	void Init();
private:
	unique_base MoveScene(unique_base own);
	//Cameraのポインタ
	std::shared_ptr<Camera> camera_;
	std::shared_ptr<Player> player_;
	std::shared_ptr<EnemyBase> enemy_;
	std::shared_ptr<Sky> sky_;
	std::unique_ptr<Collision> collision_;
protected:
};

