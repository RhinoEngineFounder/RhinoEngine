#include "Engine/RhinoCore.h"

class Player : public Object
{
public:
    Player();
    ~Player();

    void Awake() override;
    void Tick(float deltaTime) override;
    void End() override;

private:
    float speed = 0.1;
};