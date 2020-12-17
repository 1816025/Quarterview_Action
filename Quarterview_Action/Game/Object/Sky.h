#pragma once
#include "Object.h"
class Player;
class Sky :
	public Object
{
public:
	Sky(std::shared_ptr<Player> player);
	~Sky();
	void Render(void);
private:
	std::shared_ptr<Player> player_;
};

