#include "Sound.h"
#include <iostream>
#include <fstream>

Sound::Sound(GameObject& associated):Component(associated){
//    this->associated = associated;
    this->chunk = nullptr;
}

Sound::Sound(GameObject& associated, const char* file):Component(associated){
    new Sound(associated);
    this->Open(file);
}

void Sound::Play(int times){
    this->channel=Mix_PlayChannel(-1, this->chunk, times-1);
}

bool Sound::IsOpen(){
    if(this->chunk!=nullptr){
        return true;
    }
    return false;
}

void Sound::Stop(){
    if(this->IsOpen()){
        Mix_HaltChannel(this->channel);
    }
}

/*Just loads the sound into memory. To play, call Play()*/
void Sound::Open(const char* file){
    this->chunk = Mix_LoadWAV(file);
    if(this->chunk==nullptr){
        std::string errorMsg = SDL_GetError();
        std::ofstream errorLog;
        errorLog.open("errorLog.txt", std::ios_base::app);
        errorLog << "Sound retornou NULL." << std::endl << errorMsg << std::endl;
        std::cout << "Sound retornou NULL." << std::endl << errorMsg << std::endl;
        errorLog.close();
//    }else{
//        this->Play();
    }
}

Sound::~Sound(){
    this->Stop();
    Mix_FreeChunk(this->chunk);
}

void Update (float dt){}

bool Is(std::string type){
    if(type=="Sound"){
        return true;
    }
    return false;
}
