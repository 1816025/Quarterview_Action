#pragma once

class Block
{
public:
	Block(int id,int new_texture, VECTOR pos);
	~Block();
	void Render(void);
private:
	int id_;
	VECTOR pos_;
	VECTOR offset_;
};
