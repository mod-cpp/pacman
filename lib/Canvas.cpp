#include "Canvas.hpp"
#include <vector>
#include <fmt/format.h>
#include "PacMan.hpp"
#include "Pellets.hpp"
#include "SuperPellets.hpp"

Canvas::Canvas()
  : window(windowDimensions()) {}

void Canvas::update(const PacMan & pacMan, const Pellets & pellets, const SuperPellets & superPellets) {
  window.clear();

  renderMaze();
  renderPellets(pellets);
  renderSuperPellets(superPellets);
  renderPacMan(pacMan);
  renderScore(0);

  window.render();
}

void Canvas::renderMaze() const {
  SDL_Rect maze_translated = { LEFT_MARGIN, TOP_MARGIN, MAZE_WIDTH, MAZE_HEIGHT };
  Sprite maze = window.getBackground();
  window.renderSprite(maze, maze_translated);
}

void Canvas::renderPellets(const Pellets & pellets) const {
  Sprite pellet = getSprite(pellets.currentSprite());
  std::vector<SDL_Point> pelletPositions = pellets.currentPositions();
  for (const auto & pos : pelletPositions) {
    renderSprite(pellet, pos);
  }
}

void Canvas::renderSuperPellets(const SuperPellets & superPellets) const {
  Sprite pellet = getSprite(superPellets.currentSprite());
  std::vector<SDL_Point> superPelletPositions = superPellets.currentPositions();
  for (const auto & pos : superPelletPositions) {
    renderSprite(pellet, pos);
  }
}

void Canvas::renderPacMan(const PacMan & pac_man) const {
  Sprite pacmanSprite = getSprite(pac_man.currentSprite());
  const auto & pos = pac_man.position();
  renderSprite(pacmanSprite, SDL_Point{ int(pos.x), int(pos.y) });
}

void Canvas::renderScore(int score) {
    const int x = LEFT_MARGIN + MAZE_WIDTH + LEFT_MARGIN;
    const int y = TOP_MARGIN * 2;
    window.drawText("SCORE", {x, y});
    window.drawText(fmt::format("{}", score), {x, y + 20});
}

SDL_Rect Canvas::windowDimensions() const {
  return { 0, 0, LEFT_MARGIN + MAZE_WIDTH + SCORE_WIDTH, TOP_MARGIN + MAZE_HEIGHT + BOTTOM_MARGIN };
}

Sprite Canvas::getSprite(SDL_Point coordinate) const {
  return window.getSprite(
    { coordinate.x * DEFAULT_SPRITE_WIDTH,
      coordinate.y * DEFAULT_SPRITE_HEIGHT,
      DEFAULT_SPRITE_WIDTH,
      DEFAULT_SPRITE_HEIGHT });
}

void Canvas::renderSprite(Sprite sprite, SDL_Point point) const {
  SDL_Rect target = {
    LEFT_MARGIN + int((point.x * DEFAULT_SPRITE_WIDTH - sprite.rect.w / 2) * TEXTURE_SCALE_FACTOR),
    TOP_MARGIN + int((point.y * DEFAULT_SPRITE_WIDTH - sprite.rect.h / 2) * TEXTURE_SCALE_FACTOR),
    sprite.rect.w,
    sprite.rect.h
  };
  window.renderSprite(sprite, target);
}
