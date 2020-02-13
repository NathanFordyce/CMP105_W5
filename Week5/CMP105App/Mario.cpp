#include "Mario.h"

Mario::Mario()
{
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(0.1f);

	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(0.1f);

	duck.addFrame(sf::IntRect(0, 41, 16, 20));
	duck.addFrame(sf::IntRect(16, 41, 16, 20));
	duck.setFrameSpeed(0.1f);


}

Mario::~Mario()
{

}

void Mario::update(float dt)
{
	if (movement == 1)
	{
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}

	if (movement == 2)
	{
		swim.animate(dt);
		setTextureRect(swim.getCurrentFrame());
	}

	if (movement == 3)
	{
		duck.animate(dt);
		setTextureRect(duck.getCurrentFrame());
	}
}