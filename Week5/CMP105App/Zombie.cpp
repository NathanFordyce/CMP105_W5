#include "Zombie.h"

Zombie::Zombie()
{
	//Set up walk animation
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(0.1f);

	
	speed = 100;
	moving = false;
	walk.reset();
	setTextureRect(walk.getCurrentFrame());
	
}

Zombie:: ~Zombie()
{

}

void Zombie::update(float dt)
{
	if (moving)
	{
		walk.setFlipped(direction);
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}

}


