#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <iostream>

using namespace std;

int main() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    cout << SDL_GetError() << endl;
  }

  auto window = SDL_CreateWindow("test", 0, 0, 800, 600, 0);
  auto close = false;
  while(!close) {
    auto event = SDL_Event();
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          close = true;
          break;
        default:
          break;
      }
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
