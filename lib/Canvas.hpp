#pragma once

#include "Position.hpp"
#include <optional>

class PacMan;
class Pellets;
class SuperPellets;

class Canvas {
public:
  Canvas();
  void update(const PacMan & pacMan, const Pellets & pellets, const SuperPellets & superPellets);
  std::optional<sf::Event> pollEvent();

private:
  static constexpr int16_t LEFT_MARGIN = 40;
  static constexpr int16_t TOP_MARGIN = 40;
  static constexpr int16_t BOTTOM_MARGIN = 40;
  static constexpr int16_t MAZE_WIDTH = 448;
  static constexpr int16_t MAZE_HEIGHT = 496;
  static constexpr int16_t SCORE_WIDTH = 200;
  static constexpr int16_t DEFAULT_SPRITE_WIDTH = 32;
  static constexpr int16_t DEFAULT_SPRITE_HEIGHT = 32;

  void clear();
  void render();
  void renderMaze();
  void renderPacMan(const PacMan & pac_man);
  void renderPellets(const Pellets & pellets);
  void renderSuperPellets(const SuperPellets & superPellets);
  void renderSprite(Sprite sprite, Position pos);

  void renderScore(int score);

  Rect windowDimensions() const;

  sf::Texture loadTexture(std::string_view path);
  sf::Font loadFont(std::string_view path);

  Sprite getSprite(PositionInt rect) const;

  sf::RenderWindow window;
  sf::Texture maze_texture;
  sf::Texture sprites_texture;
  sf::Font game_font;
};
