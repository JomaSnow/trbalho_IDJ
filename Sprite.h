#ifndef SPRITE_H
#define SPRITE_H
#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"


class Sprite{
private:
    SDL_Texture* texture;
    int width;
    int height;
    SDL_Rect clipRect;

public:
    Sprite();
    Sprite(const char* file);
    ~Sprite();
    void Open(const char* file);
    void SetClip(int x, int y, int w, int h);
    void Render(int x, int y);
    int GetWidth();
    int GetHeight();
    bool IsOpen();
};

#endif // SPRITE_H
