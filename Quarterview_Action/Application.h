#pragma once
#include <mutex>
class KeyBoard;
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
	bool isShutDown(void);
	//�I��������
	void ShutDown(void);

};

