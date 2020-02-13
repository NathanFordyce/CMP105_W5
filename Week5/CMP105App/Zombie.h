#pragma once
#include "Framework/Animation.h"
#include "Framework/GameObject.h"
class Zombie : public GameObject
{
public:
	Zombie();
	~Zombie();

	void update(float dt) override;

	bool direction;
	float speed;
	float distance;
	float moving;


protected:
	Animation walk;

};

