#include "Sprite.h"
#include "Game.h"
#include <iostream>
#include <fstream>

// se não tiver desenhando mais que o bg é pq tem q usar this nas chamadas de funções, preview pros trabs 2, 3, etc.
// ou talvez pq tem q ser Sprite::Update sei la
// update: não precisa chamar Component::Update pq ela é virtual e foi feita pra ser overwriten.
// update 2: talvez no segundo construtor tenha que chamar o primeiro, q nem fiz em Sound.

Sprite::Sprite(GameObject& associated):Component(associated){
    texture = nullptr;
//    this->associated=associated;
}

Sprite::Sprite(GameObject& associated, const char* file):Component(associated){
    new Sprite(associated);
    Sprite::Open(file);
    if(this->IsOpen()){
        associated.box.h=this->GetHeight();
        associated.box.w=this->GetWidth();
    }
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

void Sprite::Render(){
    SDL_Rect dstrect;
    dstrect.x=associated.box.x;
    dstrect.y=associated.box.y;
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

void Update (float dt){}

bool Is(std::string type){
    if(type=="Sprite"){
        return true;
    }
    return false;
}
