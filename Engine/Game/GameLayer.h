#pragma once

#include <vector>
#include <algorithm>
#include "../Object/Object.h"
#include "Camera.h"

class GameLayer
{
public:
    GameLayer();
    ~GameLayer();

    void AddObject(Object*);
    void RemoveObject(Object*);
    void RemoveNthObject(int);

    int  GetNumberOfEntities();

    std::vector<Object*> GetEntites();
    Object* GetNthObject(int);
    Object* GetLastObject();
    Object* GetFirstObject();

    Color color;
    //Camera* cam;

private:
    std::vector<Object*> m_Entities;
};
