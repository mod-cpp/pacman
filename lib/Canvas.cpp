#include "Canvas.hpp"
#include "Game.hpp"
#include <fmt/format.h>
#include <string>
#include <vector>

namespace pacman {

static const double SCALE_FACTOR = 0.5;

Canvas::Canvas()
  : window(sf::VideoMode(windowDimensions().width, windowDimensions().height),
           "Pacman",
           sf::Style::Titlebar | sf::Style::Close) {
  window.setFramerateLimit(60);
  window.setVerticalSyncEnabled(true);
  maze_texture = loadTexture("maze.png");
  sprites_texture = loadTexture("sprites32.png");
  game_font = loadFont("retro_font.ttf");
}

void Canvas::update(const Game & game) {
  clear();

  renderMaze();
  renderPellets(game.pellets);
  renderSuperPellets(game.superPellets);

  std::apply([&](const auto &... ghost) {
    (renderGhost(ghost), ...);
  },
             game.ghosts);

  renderScore(game.score.points);
  renderLives(game.score.lives);

  renderPacMan(game.pacMan);

  render();
}

void Canvas::clear() {
  window.clear(sf::Color::Black);
}

void Canvas::render() {
  window.display();
}

std::optional<sf::Event> Canvas::pollEvent() {
  sf::Event event{};
  if (window.pollEvent(event))
    return event;
  return std::nullopt;
}

void Canvas::renderMaze() {
  Sprite maze;
  maze.setTexture(maze_texture);
  maze.setTextureRect(sf::IntRect{
    0,
    0,
    DEFAULT_MAZE_WIDTH,
    DEFAULT_MAZE_HEIGHT });
  maze.setScale(DEFAULT_MAZE_SCALE_UP * SCALE_FACTOR, DEFAULT_MAZE_SCALE_UP * SCALE_FACTOR);
  maze.setPosition(LEFT_MARGIN * SCALE_FACTOR, TOP_MARGIN * SCALE_FACTOR);
  window.draw(maze);
}

void Canvas::renderPellets(const Pellets & pellets) {
  Sprite pellet = getSprite(pellets.currentSprite());
  std::vector<GridPosition> pelletPositions = pellets.currentPositions();
  for (const auto & pos : pelletPositions) {
    renderSprite(pellet, { double(pos.x), double(pos.y) });
  }
}

void Canvas::renderSuperPellets(const SuperPellets & superPellets) {
  Sprite pellet = getSprite(superPellets.currentSprite());
  std::vector<GridPosition> superPelletPositions = superPellets.currentPositions();
  for (const auto & pos : superPelletPositions) {
    renderSprite(pellet, { double(pos.x), double(pos.y) });
  }
}

void Canvas::renderPacMan(const PacMan & pac_man) {
  Sprite pacmanSprite = getSprite(pac_man.currentSprite());
  const auto & pos = pac_man.position();
  renderSprite(pacmanSprite, pos);
}

void Canvas::renderGhost(const Ghost & ghost) {
  Sprite sprite = getSprite(ghost.currentSprite());
  const auto & pos = ghost.position();
  renderSprite(sprite, pos);
}

void Canvas::renderScore(int score) {
  const int x = (LEFT_MARGIN + DEFAULT_TARGET_MAZE_WIDTH + LEFT_MARGIN) * SCALE_FACTOR;
  const int y = (TOP_MARGIN * 2) * SCALE_FACTOR;

  sf::Text text;
  text.setPosition(x, y);
  text.setFont(game_font);
  text.setString(fmt::format("SCORE\n{}", score));
  text.setCharacterSize(40 * SCALE_FACTOR);
  text.setFillColor(sf::Color::White);
  window.draw(text);
}

void Canvas::renderLives(int lives) {
  constexpr GridPosition liveSprite = Atlas::pacman_left_narrow;
  const size_t x = (LEFT_MARGIN + DEFAULT_TARGET_MAZE_WIDTH + LEFT_MARGIN) * SCALE_FACTOR;
  const size_t y = DEFAULT_TARGET_MAZE_HEIGHT * SCALE_FACTOR;

  Sprite pacmanSprite = getSprite(liveSprite);
  for (int i = 0; i < lives - 1; i++) {
    size_t life_position = i * (DEFAULT_SPRITE_WIDTH * SCALE_FACTOR);
    GridPosition pos{ x + life_position, y };
    pacmanSprite.setPosition(pos.x, pos.y);
    window.draw(pacmanSprite);
  }
}

Rect Canvas::windowDimensions() {
  const double width = (LEFT_MARGIN + DEFAULT_TARGET_MAZE_WIDTH + SCORE_WIDTH) * SCALE_FACTOR;
  const double height = (TOP_MARGIN + DEFAULT_TARGET_MAZE_HEIGHT + BOTTOM_MARGIN) * SCALE_FACTOR;
  return { 0, 0, int(width), int(height) };
}

Sprite Canvas::getSprite(GridPosition coordinate) const {
  sf::Sprite sprite;
  sprite.setTexture(sprites_texture);
  sprite.setTextureRect(sf::IntRect{ int(coordinate.x * DEFAULT_SPRITE_WIDTH),
                                     int(coordinate.y * DEFAULT_SPRITE_HEIGHT),
                                     DEFAULT_SPRITE_WIDTH,
                                     DEFAULT_SPRITE_HEIGHT });
  sprite.scale(SCALE_FACTOR, SCALE_FACTOR);
  return sprite;
}

void Canvas::renderSprite(Sprite sprite, Position pos) {
  pos.x = (LEFT_MARGIN * SCALE_FACTOR) + (pos.x * (DEFAULT_SPRITE_WIDTH * SCALE_FACTOR));
  pos.y = (TOP_MARGIN * SCALE_FACTOR) + (pos.y * (DEFAULT_SPRITE_HEIGHT * SCALE_FACTOR));
  sprite.setPosition(pos.x, pos.y);
  window.draw(sprite);
}

static void exitFailure(const std::string & message) {
  fmt::print("{}\n", message);
  exit(1);
}

sf::Texture Canvas::loadTexture(std::string_view path) {
  sf::Texture texture;
  if (!texture.loadFromFile(std::string{ path })) {
    exitFailure(fmt::format("Failed to load image {}", path));
  }
  return texture;
}

sf::Font Canvas::loadFont(std::string_view path) {
  sf::Font font;
  if (!font.loadFromFile("retro_font.ttf")) {
    exitFailure(fmt::format("Failed to load font {}", path));
  }
  return font;
}

} // namespace pacman
