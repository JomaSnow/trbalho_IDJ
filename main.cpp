//#include "SDL2/SDL.h"
//#include "SDL2/SDL_image.h"
//#include "SDL2/SDL_mixer.h"
//#include "SDL2/SDL_ttf.h"
#include "Game.h"
#include "Rect.h"
#include "Vec2.h"
#include <iostream>

//void test(){
//    Vec2* v1 = new Vec2(5, -3);
//    Vec2* v2 = new Vec2(-2, 1);
//    Vec2* v3 = v1->multiplyByScalar(v1, 3);

//    std::cout << "resultado: x: " << v3->x << ", y: " << v3->y << "." << std::endl;
//    std::cout << "magnitude: " << v1->getMagnitude() << std::endl;
//}

int main (int argc, char** argv) {

    Game game = Game::GetInstance();

//    test();

    game.Run();

    game.~Game();
    return 0;
}
