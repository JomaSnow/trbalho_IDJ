#ifndef FACE_H
#define FACE_H

#include "Component.h"

class Face : public Component{
public:
    Face(GameObject& associated);
    void Damage(int damage);

private:
    int hitpoints;
};

#endif // FACE_H
