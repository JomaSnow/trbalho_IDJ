#ifndef MUSIC_H
#define MUSIC_H
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

class Music{
private:
    Mix_Music* music;
public:
    Music();
    Music(const char* file);
    void Play(int times=-1);
    void Stop(int msToStop=1500);
    void Open(const char* file);
    bool IsOpen();
    ~Music();
};

#endif // MUSIC_H
