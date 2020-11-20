#pragma once
#include <mutex>
#include <vector>
#include <array>
#include <map>
class Block;

using Map_Data = std::array<std::array<std::shared_ptr<Block>, 30>, 10>;
class Field
{
public:
	Field(std::vector<std::string> file_name);
	~Field();
	bool Init(void);
	void UpDate(void);
	std::shared_ptr<Block> GetMapData(const int& x,const int& y);
	bool isBlock(const float& x,const float& y,const float& z);
private:
	void Render(void);
	int block_id_ = -1;
	std::map<std::string,int> textur_id_;
	Map_Data map_data_;
	std::vector<std::shared_ptr<Block>> block_;
};

