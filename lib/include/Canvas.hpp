#pragma once

#include "Position.hpp"
#include "Score.hpp"
#include <optional>

namespace pacman {

class Game;
class Ghost;
class PacMan;
class Pellets;
class SuperPellets;

class Canvas {
public:
  Canvas();
  void update(const Game & game);
  std::optional<sf::Event> pollEvent();

private:
  static constexpr uint16_t LEFT_MARGIN = 40 * 2;
  static constexpr uint16_t TOP_MARGIN = 40 * 2;
  static constexpr uint16_t BOTTOM_MARGIN = 40 * 2;
  static constexpr uint16_t DEFAULT_MAZE_WIDTH = 448;
  static constexpr uint16_t DEFAULT_MAZE_HEIGHT = 496;
  static constexpr uint16_t DEFAULT_MAZE_SCALE_UP = 2;
  static constexpr uint16_t DEFAULT_TARGET_MAZE_WIDTH = DEFAULT_MAZE_WIDTH * DEFAULT_MAZE_SCALE_UP;
  static constexpr uint16_t DEFAULT_TARGET_MAZE_HEIGHT = DEFAULT_MAZE_HEIGHT * DEFAULT_MAZE_SCALE_UP;
  static constexpr uint16_t SCORE_WIDTH = 200 * 2;
  static constexpr uint16_t DEFAULT_SPRITE_WIDTH = 32;
  static constexpr uint16_t DEFAULT_SPRITE_HEIGHT = 32;

  void clear();
  void render();
  void renderMaze();
  void renderPacMan(const PacMan & pac_man);
  void renderGhost(const Ghost & ghost);
  void renderPellets(const Pellets & pellets);
  void renderSuperPellets(const SuperPellets & superPellets);
  void renderSprite(Sprite sprite, Position pos);

  void renderScore(int score);
  void renderLives(int lives);

  static Rect windowDimensions();
  static sf::Texture loadTexture(std::string_view path);
  static sf::Font loadFont(std::string_view path);

  Sprite getSprite(GridPosition rect) const;

  sf::RenderWindow window;
  sf::Texture maze_texture;
  sf::Texture sprites_texture;
  sf::Font game_font;
};

} // namespace pacman
