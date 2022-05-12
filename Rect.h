#ifndef RECT_H
#define RECT_H


class Rect{
public:
    float x, y, w, h;
    Rect(float x, float y, float w, float h);
    Rect();
    Rect(float w, float h);
    void setPos(float x, float y);
};

#endif // RECT_H
