#pragma once

#include "SDLWindow.hpp"

class PacMan;
class Pellets;
class SuperPellets;

class Canvas {
public:
  void update(const PacMan & pacMan, const Pellets & pellets, const SuperPellets & superPellets);

private:
  static constexpr int16_t SCALE_FACTOR = 1;
  static constexpr int16_t LEFT_MARGIN = 40;
  static constexpr int16_t TOP_MARGIN = 40;
  static constexpr int16_t BOTTOM_MARGIN = 40;
  static constexpr int16_t MAZE_WIDTH = 448;
  static constexpr int16_t MAZE_HEIGHT = 496;
  static constexpr int16_t SCORE_WIDTH = 200;
  static constexpr int16_t DEFAULT_TEXTURE_WIDTH = 32;
  static constexpr int16_t DEFAULT_TEXTURE_HEIGHT = 32;
  static constexpr float TEXTURE_SCALE_FACTOR = 0.5;

  void renderMaze() const;
  void renderPacMan(const PacMan & pac_man) const;
  void renderPellets(const Pellets & pellets) const;
  void renderSuperPellets(const SuperPellets & superPellets) const;

  SDLWindow window;
};
