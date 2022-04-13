#include "State.h"

State::State() : bg("img/ocean.jpg"), music("audio/stageState.ogg") {
    State::quitRequested = false;
}

void State::LoadAssets(){
    // Deixe  para  carregar  imagens/fontes/músicas  às  suas  variáveis
    // aqui  sempre  que for possível.

}

void State::Update(float dt){
    bool quitReq = SDL_QuitRequested();
    if(quitReq){
        State::quitRequested = true;
    }
}

void State::Render(){
    State::bg.Render(0,0);
}

bool State::QuitRequested(){
    return State::quitRequested;
}
