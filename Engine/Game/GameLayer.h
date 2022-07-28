#pragma once

#include <vector>
#include <algorithm>
#include "../Object/Object.h"

class GameLayer
{
public:
    void AddObject(Object*);
    void RemoveObject(Object*);
    void RemoveNthObject(int);

    int  GetNumberOfEntities();

    std::vector<Object*> GetEntites();
    Object* GetNthObject(int);
    Object* GetLastObject();
    Object* GetFirstObject();

    Color color;

private:
    std::vector<Object*> m_Entities;
};
