#include "Level.h"
#include "Framework/Collision.h"
Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ball1.setPosition(0, 200);
	ball1.setVelocity(500, 500);
	ball1.setCollisionBox(sf::FloatRect(0, 0, 50, 50));

	p1.setInput(in);
	p1.setPaddle(true);
	p1.setFillColor(sf::Color::Red);
	p1.setPosition(0, 50);

	p2.setInput(in);
	p2.setPaddle(false);
	p2.setFillColor(sf::Color::Blue);
	p2.setPosition(1150, 50);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	p1.handleInput(dt);
	p2.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	ball1.update(dt);

	if (Collision::checkBoundingBox(&p1, &ball1))
	{
		p1.collisionResponse(&ball1);
	}
	if (Collision::checkBoundingBox(&p2, &ball1))
	{
		p2.collisionResponse(&ball1);
	}

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball1);
	window->draw(p1);
	window->draw(p2);
	endDraw();
}
