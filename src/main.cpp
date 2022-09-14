#include <GL/glew.h>
#include <GL/glu.h>
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
    return -1;
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  auto window = SDL_CreateWindow("test", 0, 0, 800, 600, SDL_WINDOW_OPENGL);
  auto context = SDL_GL_CreateContext(window);

  if (!context) {
    cout << "OpenGL context creation error: " << SDL_GetError() << endl;
    return -1;
  }

  glewExperimental = GL_TRUE;
  glewInit();

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  auto close = false;
  while (!close) {
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
