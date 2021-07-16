#include "Game.hpp"
#include "GameState.hpp"

#include <chrono>

namespace pacman {

constexpr int DEFAULT_LIVES = 3;
constexpr int NORMAL_PELLET_POINTS = 10;
constexpr int POWER_PELLET_POINTS = 50;
constexpr int GHOST_POINTS = 200;

Game::Game() {
  score.lives = DEFAULT_LIVES;
}

void Game::run() {

  const std::chrono::milliseconds delta_time(1000 / 60);
  std::chrono::milliseconds accumulator(0);
  auto current_time = std::chrono::system_clock::now();

  InputState inputState;

  while (true) {
    auto newTime = std::chrono::system_clock::now();
    auto frameTime = std::chrono::duration_cast<std::chrono::milliseconds>(newTime - current_time);
    current_time = newTime;
    accumulator += frameTime;
    processEvents(inputState);
    if (inputState.close)
      return;
    while (accumulator >= delta_time) {
      step(delta_time, inputState);
      accumulator -= delta_time;
    }
    canvas.update(gameState, score);
  }
}

void Game::killPacMan() {
  gameState.pacMan.die();
  score.lives--;
  timeSinceDeath = std::chrono::milliseconds(1);
}

bool Game::pacManDying() const {
  return timeSinceDeath.count() != 0;
}

void Game::handleDeathAnimation(std::chrono::milliseconds delta) {
  timeSinceDeath += delta;

  if (timeSinceDeath.count() > 1000) {
    gameState.blinky.reset();
    gameState.pinky.reset();
    gameState.inky.reset();
    gameState.clyde.reset();
    gameState.pacMan.reset();
    timeSinceDeath = std::chrono::milliseconds(0);
  }
}

void Game::step(std::chrono::milliseconds delta, InputState inputState) {

  gameState.pacMan.update(delta, inputState.direction());

  if (pacManDying()) {
    handleDeathAnimation(delta);
    return;
  }

  if (!gameState.pacMan.hasDirection())
    return;

  gameState.blinky.update(delta);
  gameState.pinky.update(delta);
  gameState.inky.update(delta);
  gameState.clyde.update(delta);

  checkCollision(gameState.blinky);
  checkCollision(gameState.pinky);
  checkCollision(gameState.inky);
  checkCollision(gameState.clyde);

  eatPellets();
}

template<typename Ghost>
void Game::checkCollision(Ghost & ghost) {
  if (pacManDying() || ghost.isEyes())
    return;

  if (positionToGridPosition(ghost.position()) != gameState.pacMan.positionInGrid())
    return;

  if (ghost.isFrightened()) {
    ghost.die();
    score.points += GHOST_POINTS;
  } else {
    killPacMan();
  }
}

void Game::eatPellets() {
  const auto pos = gameState.pacMan.positionInGrid();
  if (gameState.pellets.eatPelletAtPosition(pos)) {
    score.eatenPellets++;
    score.points += NORMAL_PELLET_POINTS;
  }

  if (gameState.superPellets.eatPelletAtPosition(pos)) {
    score.eatenPellets++;
    score.points += POWER_PELLET_POINTS;

    gameState.blinky.frighten();
    gameState.pinky.frighten();
    gameState.inky.frighten();
    gameState.clyde.frighten();
  }
}

void Game::processEvents(InputState & inputState) {

  auto event = canvas.pollEvent();
  if (event && event.value().type == sf::Event::Closed) {
    inputState.close = true;
    return;
  }

  inputState.down = inputState.up = inputState.left = inputState.right = false;

  inputState.down = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
  inputState.up = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
  inputState.left = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
  inputState.right = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
}

} // namespace pacman
