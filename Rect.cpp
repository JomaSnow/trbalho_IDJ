#include "Rect.h"

Rect::Rect(){
    this->x=0;
    this->y=0;
    this->w=0;
    this->h=0;
}

Rect::Rect(float x, float y, float w, float h){
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
}

Rect::Rect(float w, float h){
    this->x=0;
    this->y=0;
    this->w=w;
    this->h=h;
}

void Rect::setPos(float x, float y){
    this->x=x;
    this->y=y;
}
