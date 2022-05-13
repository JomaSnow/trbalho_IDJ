#ifndef COMPONENT_H
#define COMPONENT_H
#include "GameObject.h"
#include <string>

class Component{
public:
    Component(GameObject& associated);
    virtual ~Component();
    virtual void Update (float dt);
    virtual void Render ();
    virtual bool Is(std::string type);


protected:
    GameObject& associated;
};

#endif // COMPONENT_H
