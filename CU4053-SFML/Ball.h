#pragma once
#include "Framework/GameObject.h"
class Ball : public GameObject
{
    sf::Texture ballTexture;
public:
    Ball();
    ~Ball();

    void update(float dt)  override;
    void collisionResponse(GameObject* collider) override;
};

