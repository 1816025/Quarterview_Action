#pragma once

class SceneBase;

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
};

