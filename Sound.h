#ifndef SOUND_H
#define SOUND_H

#include "Component.h"
#include "SDL2/SDL_mixer.h"
#include <string>

class Sound : public Component{
public:
    Sound(GameObject& associated);
    Sound(GameObject& associated, const char* file);
    ~Sound();

    void Play(int times = 1);
    void Stop();
    void Open(const char* file);
    bool IsOpen();

//    void Update(float dt);
//    void Render();
//    void Is(std::string type);

private:
    Mix_Chunk* chunk;
    int channel;

};

#endif // SOUND_H
