#include <Windows.h>
#include <DxLib.h>
#include <string>
#include <random>

#include "../_debug/_DebugConOut.h"
#include "../Game/Object/Block.h"
#include "../common.h"
#include "Field.h"

Field::Field(std::vector<std::string>file_name)
{
	engine.seed(seed_gen());
	if (blockId_ == -1)
	{
		//auto file_name = GetFileList("model");

		for (auto name : file_name)
		{
			texturId_.try_emplace(name, MV1LoadTexture(("model/block/texture/" + name).c_str()));
		}
		blockId_ = MV1LoadModel("model/block/block.mv1");
	}
	MakeMap();
}

Field::~Field()
{
}

bool Field::Init(void)
{
	return true;
}

std::shared_ptr<Block> Field::GetMapData(const int& x, const int& z)
{
	return mapData_[x][z];
}

bool Field::isBlock(const float& pos_x, const float& pos_y, const float& pos_z)
{
	auto x = pos_x / 100;
	auto z = pos_z / 100;
	auto result = (x>=0 && x < FIELD_SIZE_X && z >= 0 && z <   FIELD_SIZE_Z);
	return (result ? ((mapData_[x][z] == nullptr) ? false : true) : false);
}

void Field::MakeMap(void)
{
	for (int z = 0; z < FIELD_SIZE_Z; z++)
	{
		for (int x = 0; x < FIELD_SIZE_X; x++)
		{
			if (engine() % 10 < 8)
			{
				if (engine() % 2)
				{
					mapData_[x].emplace_back(std::make_shared<Block>(blockId_, texturId_["block01.png"], VGet(x, 0, z)));
				}
				else
				{
					mapData_[x].emplace_back(std::make_shared<Block>(blockId_, texturId_["TNT.png"], VGet(x, 0, z)));
				}
			}
			else
			{
				mapData_[x].emplace_back(nullptr);
			}
		}
	}
	demoMapData_ = mapData_;
}

void Field::AddDemoMap(void)
{
	for (int x = 0; x < FIELD_SIZE_X; x++)
	{
		if (engine() % 10 < 8)
		{
			if (engine() % 2)
			{
				mapData_[x].emplace_back(std::make_shared<Block>(blockId_, texturId_["block01.png"], VGet(x, 0, mapData_[x].size())));
			}
			else
			{
				mapData_[x].emplace_back(std::make_shared<Block>(blockId_, texturId_["TNT.png"], VGet(x, 0, mapData_[x].size())));
			}
		}
		else
		{
			mapData_[x].emplace_back(nullptr);
		}
	}
}

void Field::Render(void)
{
	VECTOR start_pos;
	VECTOR end_pos;
	for (int line = 0; line <= FIELD_SIZE_X; ++line)
	{
		start_pos = VGet(line * 100.0f, 0.0f, 0.0f);
		end_pos = VGet(line * 100.0f, 0.0f, FIELD_SIZE_Z * 100.0f);
		DrawLine3D(start_pos, end_pos, 0xffffff);
	}
	for (int line = 0; line <= FIELD_SIZE_Z; ++line)
	{
		start_pos = VGet(0.0f, 0.0f, line * 100.0f);
		end_pos = VGet(FIELD_SIZE_X * 100.0f, 0.0f, line * 100.0f);
		DrawLine3D(start_pos, end_pos, 0xffffff);
	}

	for (int z = 0; z < mapData_[0].size(); z++)
	{
		for (int x = 0; x < FIELD_SIZE_X; x++)
		{
			if (mapData_[x][z] != nullptr)
			{
				mapData_[x][z]->Render();
			}
			else
			{
				int a = 0;
			}
		}
	}
}

void Field::DemoRender(void)
{
	VECTOR start_pos;
	VECTOR end_pos;
	for (int line = 0; line <= FIELD_SIZE_X; ++line)
	{
		start_pos = VGet(line * 100.0f, 0.0f, 0.0f);
		end_pos = VGet(line * 100.0f, 0.0f, FIELD_SIZE_Z * 100.0f);
		DrawLine3D(start_pos, end_pos, 0xffffff);
	}
	for (int line = 0; line <= FIELD_SIZE_Z; ++line)
	{
		start_pos = VGet(0.0f, 0.0f, line * 100.0f);
		end_pos = VGet(FIELD_SIZE_X * 100.0f, 0.0f, line * 100.0f);
		DrawLine3D(start_pos, end_pos, 0xffffff);
	}

	for (int z = 0; z < demoMapData_[0].size(); z++)
	{
		for (int x = 0; x < FIELD_SIZE_X; x++)
		{
			if (demoMapData_[x][z] != nullptr)
			{
				demoMapData_[x][z]->Render();
			}
			else
			{
				int a = 0;
			}
		}
	}
}
