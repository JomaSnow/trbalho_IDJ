#include "State.h"
#include "Face.h"
#include "Sound.h"
#include "Vec2.h"
#include <cmath>

State::State() : bg("img/ocean.jpg"), music("audio/stageState.ogg") {
    State::quitRequested = false;
}

State::~State(){
    this->objectArray.clear();
}

void State::Input() {
    SDL_Event event;
    int mouseX, mouseY;

    // Obtenha as coordenadas do mouse
    SDL_GetMouseState(&mouseX, &mouseY);

    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
    while (SDL_PollEvent(&event)) {

        // Se o evento for quit, setar a flag para terminação
        if(event.type == SDL_QUIT) {
            quitRequested = true;
        }

        // Se o evento for clique...
        if(event.type == SDL_MOUSEBUTTONDOWN) {

            // Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
            for(int i = objectArray.size() - 1; i >= 0; --i) {
                // Obtem o ponteiro e casta pra Face.
                GameObject* go = (GameObject*) objectArray[i].get();
                // Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
                // O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
                // ao usar get(), violamos esse princípio e estamos menos seguros.
                // Esse código, assim como a classe Face, é provisório. Futuramente, para
                // chamar funções de GameObjects, use objectArray[i]->função() direto.

                if(go->box.Contains( (float)mouseX, (float)mouseY ) ) {
                    Face* face = (Face*)go->GetComponent( "Face" );
                    if ( nullptr != face ) {
                        // Aplica dano
                        face->Damage(std::rand() % 10 + 10);
                        // Sai do loop (só queremos acertar um)
                        break;
                    }
                }
            }
        }
        if( event.type == SDL_KEYDOWN ) {
            // Se a tecla for ESC, setar a flag de quit
            if( event.key.keysym.sym == SDLK_ESCAPE ) {
                quitRequested = true;
            }
            // Se não, crie um objeto
            else {
                //objPos é um vec2 resultado da soma de um vec(200,0) rotacionado + vec(mouseX, mouseY)

                Vec2* v1 = (new Vec2(200, 0))->GetRotated( -M_PI + M_PI*(rand() % 1001)/500.0 );
                Vec2* v2 = new Vec2(mouseX, mouseY);
                Vec2* objPos = v1->addVecs(v1, v2);
//                Vec2 objPos = objPos.addVecs(Vec2( 200, 0 ).GetRotated( -M_PI + M_PI*(rand() % 1001)/500.0 ), Vec2( mouseX, mouseY ));
                AddObject((int)objPos->x, (int)objPos->y);
            }
        }
    }
}

void State::LoadAssets(){
    // Deixe  para  carregar  imagens/fontes/músicas  às  suas  variáveis
    // aqui  sempre  que for possível.

}

void State::Update(float dt){
    this->Input();
    for(int i = this->objectArray.size() -1; i >= 0; i--){
        this->objectArray[i]->Update(dt);

        if(this->objectArray[i]->IsDead()){
            this->objectArray.erase(this->objectArray.begin() + i);
        }
    }
}

void State::Render(){
    for(int i =0; i < objectArray.size(); i++){
        objectArray[i]->Render();
    }
}

void State::AddObject(int mouseX, int mouseY){
    GameObject* obj = new GameObject();
    obj->box.x=mouseX;
    obj->box.y=mouseY;
//    Sprite* spriteCpt = new Sprite(obj, "img/penguin.png");
//    Sound* soundCpt = new Sound(obj, "audio/boom.wav");
//    Face* faceCpt = new Face(obj);
//    obj->AddComponent(spriteCpt);
//    obj->AddComponent(soundCpt);
//    obj->AddComponent(faceCpt);

    objectArray.emplace_back(obj);

}

bool State::QuitRequested(){
    return State::quitRequested;
}
