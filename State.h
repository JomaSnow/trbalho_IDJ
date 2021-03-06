#ifndef STATE_H
#define STATE_H
#define INCLUDE_SDL
#include "SDL_include.h"
#include "Sprite.h"
#include "Music.h"
#include <memory>
#include <vector>

class State {
private:
    Sprite bg;
    Music music;
    bool quitRequested;
    void Input();
    void AddObject(int mouseX, int mouseY);

    std::vector<std::unique_ptr<GameObject>> objectArray;
public:
    State();
    ~State();
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();
};

#endif // STATE_H
