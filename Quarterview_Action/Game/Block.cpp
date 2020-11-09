#include <DxLib.h>
#include "../common.h"
#include "Block.h"

Block::Block(int id,int new_texture, VECTOR pos)
{
	_id = MV1DuplicateModel(id);
	//テクスチャの変更
	auto defaultIndex = MV1GetMaterialDifMapTexture(_id, 0);
	MV1SetTextureGraphHandle(_id, defaultIndex, new_texture, false);
	_pos = VGet(0.0f,0.0f,0.0f);
	_offset = (pos * BLOCK_SIZE) + VGet(50.0f, -50.0f, 50.0f);
	
}

Block::~Block()
{
}

void Block::Render(void)
{
	MV1SetPosition(_id, _pos + _offset);
	MV1DrawModel(_id);
}
