#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Game.h"
#include <iostream>
#include <fstream>

Game* Game::instance;

Game& Game::GetInstance(){
    if(instance!=nullptr){
        return *instance;
    }else{
        instance = new Game("João Marcos Schmaltz Duda - 15/0132131", 1024, 600);
        return *instance;
    }
}

Game::Game(const char* title, int width, int height){
    if(instance!=nullptr){
        // ALGO DEU ERRADO
    }else{
        instance=this;

//        Uma observação: A SDL_Init retorna diferente de zero quando falha.
        bool failed_init = (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)!=0);
        if(failed_init){
            std::string errorMsg = SDL_GetError();
            std::ofstream errorLog;
            errorLog.open("errorLog.txt", std::ios_base::app);
            errorLog << "Erro na inicialização da SDL." << std::endl << errorMsg << std::endl;
            errorLog.close();
            // ABORT
        }else{
            // loads images
            int imageBitmask = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
            if(imageBitmask==0){
                std::string errorMsg = SDL_GetError();
                std::ofstream errorLog;
                errorLog.open("errorLog.txt", std::ios_base::app);
                errorLog << "Erro na inicialização dos loaders da SDL_Image." << std::endl << errorMsg << std::endl;
                errorLog.close();
            }

            // loads sounds
            int mixerBitmask = Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG);
            if(mixerBitmask==0){
                std::string errorMsg = SDL_GetError();
                std::ofstream errorLog;
                errorLog.open("errorLog.txt", std::ios_base::app);
                errorLog << "Erro na inicialização dos loaders da SDL_Mixer." << std::endl << errorMsg << std::endl;
                errorLog.close();
            }

            // se api for bem sucedida vai retornar zero
            bool openAudioSuccess = (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)) == 0;

            Mix_AllocateChannels(32);

            // creates window (se falham, retornam nullptr)
            Game::window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

            Game::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

            if(window==nullptr||renderer==nullptr){
                std::ofstream errorLog;
                errorLog.open("errorLog.txt", std::ios_base::app);
                errorLog << "Erro na criação de janela e/ou renderizador." << std::endl;
                std::cout << "Erro na criação de janela e/ou renderizador." << std::endl;
                errorLog.close();
            }
        }
    }
}

Game::~Game(){
    // ENCERRA STATE
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

State& Game::GetState(){
    return *state;
}

SDL_Renderer* Game::GetRenderer(){
    return renderer;
}

void Game::Run(){

    State* menuState = new State();

    state = menuState;


    while(!state->QuitRequested()){

        state->Update(50);
        state->Render();

        SDL_RenderPresent(renderer);
        SDL_Delay(33);


    }
}
