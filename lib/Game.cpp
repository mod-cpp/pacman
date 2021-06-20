#include "Game.hpp"

#include <chrono>

Game::Game()
  : pacMan(board),
    pellets(board),
    superPellets(board) {}

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
    eatPellets();
    current_time += time_delta;
    canvas.update(pacMan, pellets, superPellets);
  }
}

void Game::eatPellets() {
  const auto pos = pacMan.positionInGrid();
  pellets.eatPelletAtPosition(pos);
  superPellets.eatPelletAtPosition(pos);
}

void Game::processEvents(InputState & inputState) {

  auto event = canvas.pollEvent();
  if (event->type == sf::Event::Closed) {
    inputState.close = true;
    return;
  }

  inputState.down = inputState.up = inputState.left = inputState.right = false;

  inputState.down = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
  inputState.up = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
  inputState.left = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
  inputState.right = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
}
