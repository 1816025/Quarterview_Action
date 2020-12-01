#include <DxLib.h>
#include "../../common.h"
#include "Block.h"

Block::Block(int id,int new_texture, VECTOR pos)
{
	id_ = MV1DuplicateModel(id);
	//テクスチャの変更
	auto defaultIndex = MV1GetMaterialDifMapTexture(id_, 0);
	MV1SetTextureGraphHandle(id_, defaultIndex, new_texture, false);
	pos_ = VGet(0.0f,0.0f,0.0f);
	offset_ = (pos * BLOCK_SIZE) + VGet(50.0f, -50.0f, 50.0f);
	
}

Block::~Block()
{
}

void Block::Render(void)
{
	MV1SetPosition(id_, pos_ + offset_);
	MV1DrawModel(id_);
}
