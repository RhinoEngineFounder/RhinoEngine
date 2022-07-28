#include "Object.h"

Object::Object() 
{
    this->transform.location.x = 0;
    this->transform.location.y = 0;
    
    this->shape = RECTANGLE;
    this->color = Color(255, 255, 255, 255);
    AddComponent(input);
}

Object::Object(FVector l, FVector s)
{
    this->transform.location = l;
    this->transform.scale = s;
    
    this->shape = RECTANGLE;
    this->color = Color(255, 255, 255, 255);
    AddComponent(input);
}

void Object::AddComponent(Component* c) { this->components.push_back(c); }

Object::~Object() {}
Transform Object::GetObjectTransform()  { return this->transform; }
FVector Object::GetObjectLocation()     { return this->transform.location; }
FVector Object::GetObjectScale()        { return this->transform.scale; }
Shape Object::GetShape() { return this->shape;  }
Color Object::GetColor() { return this->color; }

void Object::SetObjectTransform(Transform t) { this->transform = t; }
void Object::SetObjectLocation(FVector l)    { this->transform.location = l; }
void Object::SetObjectScale(FVector s)       { this->transform.scale = s; }
void Object::SetShape(Shape s) { this->shape = s; }
void Object::SetColor(Color c) { this->color = c; }