#include "Game.h"

#include <SDL2/SDL.h>

#include <chrono>

Game::Game()
  : window(448*2, 496*2) {
}

auto Game::now() {
  return std::chrono::system_clock::now();
}

void Game::run() {
  InputState inputState;
  auto current_time = now();
  while (!inputState.close) {
    processEvents(inputState);
    auto time_delta = now() - current_time;
    auto milli_delta = std::chrono::duration_cast<std::chrono::milliseconds>(time_delta);
    pacMan.update(milli_delta, inputState, board);
    current_time += time_delta;
    window.update(pacMan, board);
  }
}

void Game::processEvents(InputState & inputState) {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        inputState.close = true;
        break;
      case SDL_KEYDOWN:
        keyToggle(event, inputState, true);
        break;
      case SDL_KEYUP:
        keyToggle(event, inputState, false);
        break;
    }
  }
}

void Game::keyToggle(const SDL_Event & event, InputState & inputState, bool on) {
  switch (event.key.keysym.sym) {
    case SDLK_UP:
      inputState.up = on;
      break;
    case SDLK_DOWN:
      inputState.down = on;
      break;
    case SDLK_LEFT:
      inputState.left = on;
      break;
    case SDLK_RIGHT:
      inputState.right = on;
      break;
  }
}
