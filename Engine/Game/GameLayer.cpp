#include "GameLayer.h"

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

/*void GameLayer::RemoveNthObject(int i)
{
    this->m_Entities.erase(std::next(m_Entities.begin(), 1));
}

Object* GameLayer::GetNthObject(int) 
{

}*/

int GameLayer::GetNumberOfEntities() { return m_Entities.size(); }

std::vector<Object*> GameLayer::GetEntites() { return this->m_Entities; }
Object* GameLayer::GetFirstObject() { return *(m_Entities.begin()); }
Object* GameLayer::GetLastObject()  { return *(m_Entities.begin()); }