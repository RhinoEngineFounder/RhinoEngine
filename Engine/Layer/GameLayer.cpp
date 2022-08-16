#include "GameLayer.h"

GameLayer::GameLayer()  {  }
GameLayer::~GameLayer() {}

void GameLayer::AddObject(Object* entity)
{
    this->m_Entities.push_back(entity);
}

void GameLayer::RemoveObject(Object* entity) 
{
    // clunky algorithm shit
    if(!entity) return;
    auto itr = std::find(m_Entities.begin(), m_Entities.end(), entity);
    if(itr == m_Entities.end()) return;
    m_Entities.erase(itr);
}

Object* GameLayer::GetNthObject(int n)
{
    return this->m_Entities.at(n);
}

int GameLayer::GetNumberOfEntities() { return m_Entities.size(); }

std::vector<Object*> GameLayer::GetEntites() { return this->m_Entities; }
Object* GameLayer::GetFirstObject() { return *(m_Entities.begin()); }
Object* GameLayer::GetLastObject()  { return *(m_Entities.begin()); }