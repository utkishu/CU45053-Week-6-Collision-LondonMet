#pragma once
#include "Framework/GameObject.h"
class Paddle :
    public GameObject
{
    bool paddle1;
public:
    Paddle();
    ~Paddle();

    void handleInput(float dt)  override;
    void update(float dt) override;

    void setPaddle(bool b);
    void collisionResponse(GameObject* collider);
};