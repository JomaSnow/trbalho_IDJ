#include "Sprite.h"
#include "Game.h"
#include <iostream>
#include <fstream>

// se não tiver desenhando mais que o bg é pq tem q usar this nas chamadas de funções, preview pros trabs 2, 3, etc.

Sprite::Sprite(){
    texture = nullptr;
}

Sprite::Sprite(const char* file){
    texture = nullptr;
    Sprite::Open(file);
}

Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
}

void Sprite::Open(const char* file){
    if(texture!=nullptr){
        SDL_DestroyTexture(texture);
    }
    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file);
    if(texture==nullptr){
        std::string errorMsg = SDL_GetError();
        std::ofstream errorLog;
        errorLog.open("errorLog.txt", std::ios_base::app);
        errorLog << "Texture retornou NULL." << std::endl << errorMsg << std::endl;
        std::cout << "Texture retornou NULL." << std::endl << errorMsg << std::endl;
        errorLog.close();
    }else{
        SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
        Sprite::SetClip(0, 0, width, height);
    }
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x=x;
    clipRect.y=y;
    clipRect.w=w;
    clipRect.h=h;
}

void Sprite::Render(int x, int y){
    SDL_Rect dstrect;
    dstrect.x=x;
    dstrect.y=y;
    dstrect.w=clipRect.w;
    dstrect.h=clipRect.h;
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect);
}

int Sprite::GetWidth(){
    return width;
}

int Sprite::GetHeight(){
    return height;
}

bool Sprite::IsOpen(){
    if(texture!=nullptr){
        return true;
    }
    return false;
}
