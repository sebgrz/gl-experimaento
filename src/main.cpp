#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <iostream>

using namespace std;

int main() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    cout << SDL_GetError() << endl;
  }

  SDL_CreateWindow("test", 0, 0, 800, 600, 0);
  while(1);
  return 0;
}
