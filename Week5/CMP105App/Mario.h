#pragma once
#include "Framework/Animation.h"
#include "Framework/GameObject.h"

class Mario: public GameObject
{
public:
	Mario();
	~Mario();

	void update(float dt) override;

	int movement = 1;

protected:
	Animation walk;
	Animation swim;
	Animation duck;

};

