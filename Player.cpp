#include "Player.h"
#include "Engine/RhinoCore.h"

Player::Player() {}
Player::~Player() {}

void Player::Awake()
{
    this->transform.location = FVector(250, 250);
    this->transform.scale = FVector(100, 100);
    SetShape(RECTANGLE);
    SetColor(Color(255, 255, 255, 1));
}

void Player::Tick(float deltaTime)
{
    if(Input::isKeyHeldDown(KeyCode_d) && !(transform.location.x >= 540))
        transform.location.x += speed * deltaTime;
    if(Input::isKeyHeldDown(KeyCode_a) && !(transform.location.x <= 0))
        transform.location.x -= speed * deltaTime;
}

void Player::End()
{}
