#ifndef SPRITE_H
#define SPRITE_H
#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"
#include "Component.h"


class Sprite : public Component{
private:
    SDL_Texture* texture;
    int width;
    int height;
    SDL_Rect clipRect;

public:
    Sprite(GameObject& associated);
    Sprite(GameObject& associated, const char* file);
    ~Sprite();
    void Open(const char* file);
    void SetClip(int x, int y, int w, int h);
    void Render();
    int GetWidth();
    int GetHeight();
    bool IsOpen();
};

#endif // SPRITE_H
