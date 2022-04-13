#include "Music.h"
#include <iostream>
#include <fstream>

Music::Music(){
    music = nullptr;
}

Music::Music(const char* file){
    music = nullptr;
    this->Open(file);
}

void Music::Play(int times){
    if(music!=nullptr){
        Mix_PlayMusic(music, times);
    }
}

void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(const char* file){
    music = Mix_LoadMUS(file);
    if(music==nullptr){
        std::string errorMsg = SDL_GetError();
        std::ofstream errorLog;
        errorLog.open("errorLog.txt", std::ios_base::app);
        errorLog << "Music retornou NULL." << std::endl << errorMsg << std::endl;
        std::cout << "Music retornou NULL." << std::endl << errorMsg << std::endl;
        errorLog.close();
    }else{
        this->Play();
    }
}

bool Music::IsOpen(){
    if(music!=nullptr){
        return true;
    }
    return false;
}

Music::~Music(){
    this->Stop();
    Mix_FreeMusic(this->music);
}
