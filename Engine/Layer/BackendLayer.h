#pragma once

class PluginLayer
{
public:
    BackendLayer();
    ~BackendLayer();

    virtual void Awake() {}
    virtual void Update(float deltaTime) {}
    virtual void End() {}
};