#pragma once

class Block
{
public:
	Block(int id,int new_texture, VECTOR pos);
	~Block();
	void Render(void);
private:
	int _id;
	VECTOR _pos;
	VECTOR _offset;
};
