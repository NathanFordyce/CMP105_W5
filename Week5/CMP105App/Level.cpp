#include "Level.h"
#include "Zombie.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	zombTexture.loadFromFile("gfx/animZombie.png");
	zombie.setSize(sf::Vector2f(55, 108));
	zombie.setPosition(100, 100);
	zombie.setTexture(&zombTexture);

	marioTexture.loadFromFile("gfx/marioSheetT.png");
	mario.setSize(sf::Vector2f(30, 42));
	mario.setPosition(200, 200);
	mario.setTexture(&marioTexture);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	zombie.distance = zombie.speed * dt;
	zombie.moving = false;

	if (input->isKeyDown(sf::Keyboard::Right))
	{
		input->setKeyUp(sf::Keyboard::Right);
		zombie.moving = true;
		zombie.direction = false;
		zombie.move(sf::Vector2f(zombie.distance, 0));
		
	}

	if (input->isKeyDown(sf::Keyboard::Left))
	{
		input->setKeyUp(sf::Keyboard::Left);
		zombie.moving = true;
		zombie.direction = true;
		zombie.move(sf::Vector2f(-zombie.distance, 0));
	}

	if (input->isKeyDown(sf::Keyboard::W))
	{
		input->setKeyUp(sf::Keyboard::W);
		mario.movement = 1;
	}

	if (input->isKeyDown(sf::Keyboard::S))
	{
		input->setKeyUp(sf::Keyboard::S);
		mario.movement = 2;
	}

	if (input->isKeyDown(sf::Keyboard::D))
	{
		input->setKeyUp(sf::Keyboard::D);
		mario.movement = 3;
	}
}

// Update game objects
void Level::update(float dt)
{
	zombie.update(dt);
	mario.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(zombie);
	window->draw(mario);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}