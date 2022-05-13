#include "Component.h"

//https://stackoverflow.com/questions/19576458/constructor-for-must-explicitly-initialize-the-reference-member

Component::Component(GameObject& associated):associated(associated){
    this->associated=associated;
}
