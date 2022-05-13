#include "GameObject.h"
#include "Component.h"
#include <algorithm>

GameObject::GameObject(){
    this->isDead = false;
}

GameObject::~GameObject(){
    int vecLen = this->components.size();
    for(int i = vecLen -1; i >= 0; i--){
        delete this->components[i];
    }
    this->components.clear();
}

void GameObject::Update(float dt){
    int vecLen = this->components.size();
    for(int i = 0; i < vecLen; i++){
        this->components[i]->Update(dt);
    }
}

void GameObject::Render(){
    int vecLen = this->components.size();
    for(int i = 0; i < vecLen; i++){
        this->components[i]->Render();
    }
}

bool GameObject::IsDead(){
    return this->isDead;
}

void GameObject::RequestDelete(){
    this->isDead = true;
}

void GameObject::AddComponent(Component* cpt){
    this->components.push_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt){
    this->components.erase(std::remove(this->components.begin(), this->components.end(), cpt), this->components.end());
}

Component* GameObject::GetComponent(std::string type){
    int vecLen = this->components.size();
    for(int i = 0; i < vecLen; i++){
        if(this->components[i]->Is(type)){
            return this->components[i];
        }
    }
    return nullptr;
}
