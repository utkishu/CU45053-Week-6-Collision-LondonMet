#include "Paddle.h"

Paddle::Paddle()
{	
	paddle1 = false;
	setSize(sf::Vector2f(50, 250));
	setCollisionBox(0, 0, 50, 250);
}

Paddle::~Paddle()
{
}

void Paddle::handleInput(float dt)
{
	if (paddle1)
	{
		if (input->isKeyDown(sf::Keyboard::W))
		{
			move(0, -200 * dt);
		}
		if (input->isKeyDown(sf::Keyboard::S))
		{
			move(0, 200 * dt);
		}
	}
	else
	{
		if (input->isKeyDown(sf::Keyboard::Up))
		{
			move(0, -200 * dt);
		}
		if (input->isKeyDown(sf::Keyboard::Down))
		{
			move(0, 200 * dt);
		}
	}
}

void Paddle::update(float dt)
{

}

void Paddle::setPaddle(bool b)
{
	paddle1 = b;
}
float dotProduct(const sf::Vector2f& v1, const sf::Vector2f& v2) {
	return v1.x * v2.x + v1.y * v2.y;
}
void Paddle::collisionResponse(GameObject* ball)
{
	// Calculate relative motion vectors
	sf::Vector2f ballVel = ball->getVelocity();
	sf::Vector2f paddleVel = getVelocity();

	// Relative velocity to paddle
	sf::Vector2f relVel = ballVel - paddleVel;

	// Perfect elastic collision response
	sf::Vector2f normal(-1, 0); // Assuming horizontal paddle
	sf::Vector2f tangent(0, 1);

	float vNormal = dotProduct(relVel, normal);
	float vTangent = dotProduct(relVel, tangent);

	// Calculate post-collision velocity
	sf::Vector2f newVel = paddleVel + vTangent * tangent - vNormal * normal;

	ball->setVelocity(newVel);
}