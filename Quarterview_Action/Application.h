#pragma once

class GameScene;

class Application
{
public:
	Application() = default;
	~Application();
	//DxLib�Ȃǂ̏�����
	bool SysInit(void);
	//�Q�[�����[�v
	void Run(void);
	//�I��������
	void ShutDown(void);

private:
	//GameScene�̃|�C���^
	GameScene* _game = nullptr;
};

