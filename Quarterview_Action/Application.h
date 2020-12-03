#pragma once

class SceneBase;

class Application
{
public:
	Application() = default;
	~Application();
	//DxLibなどの初期化
	bool SysInit(void);
	//ゲームループ
	void Run(void);
	//終了時処理
	void ShutDown(void);
};

