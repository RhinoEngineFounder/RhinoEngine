#pragma once

class Plugin
{
public:
    Plugin()  {}
    ~Plugin() {}

    virtual void Awake() {}
    virtual void Update(float deltaTime) {}
    virtual void End() {}
};