#pragma once
#include <mutex>
#include <random>
#include <vector>
#include <array>
#include <map>
class Block;

//using Map_Data = std::array<std::array<std::shared_ptr<Block>, 30>, 10>;
using Map_Data = std::array<std::vector<std::shared_ptr<Block>>, 10>;
class Field
{
public:
	Field(std::vector<std::string> file_name);
	~Field();
	bool Init(void);
	std::shared_ptr<Block> GetMapData(const int& x, const int& y);
	bool isBlock(const float& x, const float& y, const float& z);
	void Render(void);
	void DemoRender(void);
private:
	void MakeMap(void);
	void AddDemoMap(void);
	std::default_random_engine engine;
	std::random_device seed_gen;
	int blockId_ = -1;
	std::map<std::string, int> texturId_;
	Map_Data mapData_;
	Map_Data demoMapData_;
	std::vector<std::shared_ptr<Block>> block_;
};

