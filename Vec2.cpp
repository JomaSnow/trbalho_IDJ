#include "Vec2.h"
#include <cmath>

/*
Lembre-se trabalharemos com um eixo y que cresce para baixo, e que
as funções de trigonometria da biblioteca padrão usam ângulos em radianos.
*/

Vec2::Vec2(){
    this->x = 0;
    this->y = 0;
}

Vec2::Vec2(float x, float y){
    this->x = x;
    this->y = y;
}


Vec2* Vec2::addVecs(Vec2* v1, Vec2* v2){
    Vec2* vR = new Vec2(v1->x+v2->x, v1->y+v2->y);

    return vR;
}

Vec2* Vec2::subtractVecs(Vec2* v1, Vec2* v2){
    Vec2* vR = new Vec2(v1->x-v2->x, v1->y-v2->y);

    return vR;
}

Vec2* Vec2::multiplyByScalar(Vec2* v1, float s){
    Vec2* vR = new Vec2(v1->x*s, v1->y*s);

    return vR;
}

float Vec2::getMagnitude(){
    return std::sqrt(std::pow(this->x, 2)+std::pow(this->y,2));
}
