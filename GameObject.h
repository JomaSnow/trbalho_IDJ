#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Rect.h"
//#include "Component.h"
#include <string>
#include <memory>
#include <vector>

//https://stackoverflow.com/questions/8526819/c-header-files-including-each-other-mutually
class Component;

class GameObject{
public:
    GameObject();
    ~GameObject();

    void Update(float dt);
    void Render();
    bool IsDead();
    void RequestDelete();
    void AddComponent(Component* cpt);
    void RemoveComponent(Component* cpt);
    Component* GetComponent(std::string type);

    Rect box;

private:
    bool isDead;
    std::vector<Component*> components;
};

#endif // GAMEOBJECT_H
