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
	std::default_random_engine engine;
	std::random_device seed_gen;
	engine.seed(seed_gen());
	if (block_id_ == -1)
	{
		//auto file_name = GetFileList("model");

		for (auto name : file_name)
		{
			textur_id_.try_emplace(name, MV1LoadTexture(("model/block/texture/" + name).c_str()));
		}
		block_id_ = MV1LoadModel("model/block/block.mv1");
	}
	for (int z = 0; z < FIELD_SIZE_Z; z++)
	{
		for (int x = 0; x < FIELD_SIZE_X; x++)
		{
			if (engine() % 10 != 0)
			{
				map_data_[x][z] = std::make_shared<Block>(block_id_, textur_id_["kusa01.png"], VGet(x, 0, z));
				if (engine() % 2)
				{
					map_data_[x][z] = std::make_shared<Block>(block_id_, textur_id_["block01.png"], VGet(x, 0, z));
				}
			}
		}
	}
}

Field::~Field()
{
}

bool Field::Init(void)
{
	return true;
}

void Field::UpDate(void)
{
	
	Render();
}

std::shared_ptr<Block> Field::GetMapData(const int& x, const int& z)
{
	return map_data_[x][z];
}

bool Field::isBlock(const float& pos_x, const float& pos_y, const float& pos_z)
{
	auto x = pos_x / 100;
	auto z = pos_z / 100;
	auto result = (x>=0 && x < FIELD_SIZE_X && z >= 0 && z <   FIELD_SIZE_Z);
	return (result ? ((map_data_[x][z] == nullptr) ? false : true) : false);
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
		start_pos = VGet(0.0f, 0.0f,line * 100.0f);
		end_pos = VGet(FIELD_SIZE_X * 100.0f, 0.0f,line * 100.0f);
		DrawLine3D(start_pos, end_pos, 0xffffff);
	}

	if (map_data_.data()->front() != nullptr)
	{
		for (int z = 0;z < FIELD_SIZE_Z;z++)
		{
			for (int x = 0; x < FIELD_SIZE_X; x++)
			{
				if (map_data_[x][z] != nullptr)
				{
					
					map_data_[x][z]->Render();
				}
			}
		}
	}
}