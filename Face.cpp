#include "Face.h"
#include "Sound.h"

Face::Face(GameObject& associated):Component(associated){
//    this->associated = associated;
    this->hitpoints = 30;
}

void Face::Damage(int damage){
    this->hitpoints=this->hitpoints-damage;

    if(this->hitpoints<=0){
        this->associated.RequestDelete();

//        https://stackoverflow.com/questions/5313322/c-cast-to-derived-class
        if(this->associated.GetComponent("Sound")!=nullptr){
            Sound* snd = dynamic_cast<Sound*>(this->associated.GetComponent("Sound"));
            snd->Play(1);
        }
    }
}

void Update (float dt){}

void Render(){}

bool Is(std::string type){
    if(type=="Face"){
        return true;
    }
    return false;
}
