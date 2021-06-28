#include "Game.hpp"

#include <chrono>

constexpr int DEFAULT_LIVES = 3;
constexpr int NORMAL_PELLET_POINTS = 10;
constexpr int POWER_PELLET_POINTS = 50;
//constexpr int GHOST_POINTS[] = {200, 400, 800, 1600};

Game::Game()
  : pacMan(board),
    pellets(board),
    superPellets(board),
    ghosts(Blinky(board), Speedy(board), Inky(board), Clyde(board)) {
  score.lives = DEFAULT_LIVES;
}


auto Game::now() {
  return std::chrono::system_clock::now();
}

void Game::run() {

  const std::chrono::milliseconds delta_time(1000 / 60);

  std::chrono::milliseconds t(0);
  std::chrono::milliseconds accumulator(0);
  auto current_time = now();

  InputState inputState;

  while (true) {
    auto newTime = now();
    auto frameTime = std::chrono::duration_cast<std::chrono::milliseconds>(newTime - current_time);
    current_time = newTime;
    accumulator += frameTime;
    processEvents(inputState);
    if (inputState.close)
      return;
    while (accumulator >= delta_time) {
      step(delta_time, inputState);
      accumulator -= delta_time;
      t += delta_time;
    }
    canvas.update(*this);
  }
}

void Game::step(std::chrono::milliseconds delta, InputState inputState) {
  pacMan.update(delta, inputState, board);

  std::apply([&](auto &... ghost) {
      (ghost.update(delta, board),...);
  }, ghosts);

  eatPellets();
}

void Game::eatPellets() {
  const auto pos = pacMan.positionInGrid();
  if (pellets.eatPelletAtPosition(pos)) {
    score.eatenPellets++;
    score.points += NORMAL_PELLET_POINTS;
  }

  if (superPellets.eatPelletAtPosition(pos)) {
    score.eatenPellets++;
    score.points += POWER_PELLET_POINTS;
  }
}

void Game::processEvents(InputState & inputState) {

  auto event = canvas.pollEvent();
  if (event && event->type == sf::Event::Closed) {
    inputState.close = true;
    return;
  }

  inputState.down = inputState.up = inputState.left = inputState.right = false;

  inputState.down = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
  inputState.up = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
  inputState.left = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
  inputState.right = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
}
