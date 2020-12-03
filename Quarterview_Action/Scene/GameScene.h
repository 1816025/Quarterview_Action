#pragma once
#include "SceneBase.h"

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
	unique_base Run(unique_base own);
	void Render(void);
	void Init();
private:
	//Camera‚Ìƒ|ƒCƒ“ƒ^
	std::shared_ptr<Camera> camera_;
	std::shared_ptr<Player> player_;
	std::shared_ptr<EnemyBase> enemy_;
	std::shared_ptr<Sky> sky_;
	std::unique_ptr<Collision> collision_;
protected:
};

