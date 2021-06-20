#include "Canvas.hpp"

#include "PacMan.hpp"
#include "Pellets.hpp"
#include "SuperPellets.hpp"
#include <fmt/format.h>
#include <string>
#include <vector>

Canvas::Canvas()
  : window(sf::VideoMode(windowDimensions().width, windowDimensions().height), "Pacman", sf::Style::Titlebar | sf::Style::Close) {
  window.setVerticalSyncEnabled(true);

  maze_texture = loadTexture("maze.png");
  sprites_texture = loadTexture("sprites32.png");
  game_font = loadFont("joystix.ttf");
}

void Canvas::update(const PacMan & pacMan, const Pellets & pellets, const SuperPellets & superPellets) {
  clear();

  renderMaze();
  renderPellets(pellets);
  renderSuperPellets(superPellets);
  renderPacMan(pacMan);
  renderScore(0);

  render();
}

void Canvas::clear() {
  window.clear(sf::Color::Black);
}

void Canvas::render() {
  window.display();
}

std::optional<sf::Event> Canvas::pollEvent() {
  sf::Event event;
  if (window.pollEvent(event))
    return event;
  return std::nullopt;
}

void Canvas::renderMaze() {
  Sprite maze(maze_texture);
  maze.setPosition(LEFT_MARGIN, TOP_MARGIN);
  window.draw(maze);
}

void Canvas::renderPellets(const Pellets & pellets) {
  Sprite pellet = getSprite(pellets.currentSprite());
  std::vector<PositionInt> pelletPositions = pellets.currentPositions();
  for (const auto & pos : pelletPositions) {
    renderSprite(pellet, pos);
  }
}

void Canvas::renderSuperPellets(const SuperPellets & superPellets) {
  Sprite pellet = getSprite(superPellets.currentSprite());
  std::vector<PositionInt> superPelletPositions = superPellets.currentPositions();
  for (const auto & pos : superPelletPositions) {
    renderSprite(pellet, pos);
  }
}

void Canvas::renderPacMan(const PacMan & pac_man) {
  Sprite pacmanSprite = getSprite(pac_man.currentSprite());
  const auto & pos = pac_man.position();
  renderSprite(pacmanSprite, { int(pos.x), int(pos.y) });
}

void Canvas::renderScore(int score) {
  const int x = LEFT_MARGIN + MAZE_WIDTH + LEFT_MARGIN;
  const int y = TOP_MARGIN * 2;

  sf::Text text;
  text.setPosition(x, y);
  text.setFont(game_font);
  text.setString(fmt::format("SCORE\n{}", score));
  text.setCharacterSize(20);
  text.setFillColor(sf::Color::White);
  window.draw(text);
}

Rect Canvas::windowDimensions() const {
  return { 0, 0, LEFT_MARGIN + MAZE_WIDTH + SCORE_WIDTH, TOP_MARGIN + MAZE_HEIGHT + BOTTOM_MARGIN };
}

Sprite Canvas::getSprite(PositionInt coordinate) const {
  sf::Sprite sprite;
  sprite.setTexture(sprites_texture);
  sprite.setTextureRect(sf::IntRect{ coordinate.x * DEFAULT_SPRITE_WIDTH,
                                     coordinate.y * DEFAULT_SPRITE_HEIGHT,
                                     DEFAULT_SPRITE_WIDTH,
                                     DEFAULT_SPRITE_HEIGHT });
  sprite.scale(0.5, 0.5);
  return sprite;
}

void Canvas::renderSprite(Sprite sprite, PositionInt pos) {
  pos.x = LEFT_MARGIN + (pos.x * DEFAULT_SPRITE_WIDTH / 2);
  pos.y = TOP_MARGIN + (pos.y * DEFAULT_SPRITE_HEIGHT / 2);
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
  if (!font.loadFromFile("joystix.ttf")) {
    exitFailure(fmt::format("Failed to load font {}", path));
  }
  return font;
}
