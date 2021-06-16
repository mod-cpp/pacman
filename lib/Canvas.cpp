#include "Canvas.hpp"

#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "PacMan.hpp"
#include "Pellets.hpp"
#include "SuperPellets.hpp"

void Canvas::update(const PacMan & pacMan, const Pellets & pellets, const SuperPellets & superPellets) {
  window.clear();

  renderMaze();
  renderPellets(pellets);
  renderSuperPellets(superPellets);
  renderPacMan(pacMan);

  window.render();
}

void Canvas::renderMaze() const {
  SDL_Rect maze_translated = { LEFT_MARGIN, TOP_MARGIN, MAZE_WIDTH, MAZE_HEIGHT };
  Sprite maze = window.getBackground();
  window.renderSprite(maze, maze_translated);
}

void Canvas::renderPellets(const Pellets & pellets) const {
  SDL_Rect sprite_rect = window.textureGeometry(pellets.currentSprite());
  std::vector<SDL_Point> pelletPositions = pellets.currentPositions();
  for (const auto & pos : pelletPositions) {
    window.renderTexture(sprite_texture.get(), sprite_rect, pos);
  }
}

void Canvas::renderSuperPellets(const SuperPellets & superPellets) const {
  SDL_Rect sprite_rect = window.textureGeometry(superPellets.currentSprite());
  std::vector<SDL_Point> superPelletPositions = superPellets.currentPositions();
  for (const auto & pos : superPelletPositions) {
    window.renderTexture(sprite_texture.get(), sprite_rect, pos);
  }
}

void Canvas::renderPacMan(const PacMan & pac_man) const {
  SDL_Rect sprite_rect = window.textureGeometry(pac_man.currentSprite());
  Position pacman_pos = pac_man.position();
  window.renderTexture(sprite_texture.get(), sprite_rect, SDL_Point{ int(pacman_pos.x), int(pacman_pos.y) });
}
