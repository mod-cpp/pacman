#include "GameWindow.hpp"

#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "PacMan.hpp"
#include "Pellets.hpp"
#include "SuperPellets.hpp"

GameWindow::GameWindow(int width, int height) {
  initSDL();
  initSDLImage();
  auto sdl_window = createWindow(width * SCALE_FACTOR, height * SCALE_FACTOR);
  auto sdl_renderer = createRenderer(sdl_window);
  createWindowSurface(sdl_window);
  setDrawColor(sdl_renderer);
  maze_texture = loadTexture(sdl_renderer, "maze.png");
  sprite_texture = loadTexture(sdl_renderer, "sprites32.png");
}

void GameWindow::update(const PacMan & pacMan, const Pellets & pellets, const SuperPellets & superPellets) {
  SDL_RenderClear(renderer.get());

  renderMaze();
  renderPellets(pellets);
  renderSuperPellets(superPellets);
  renderPacMan(pacMan);

  SDL_RenderPresent(renderer.get());
}

void GameWindow::renderMaze() const {
  renderTexture(maze_texture.get(), nullptr, nullptr);
}

void GameWindow::renderSuperPellets(const SuperPellets & superPellets) const {
  SDL_Rect sprite_rect = superPellets.currentSprite();
  std::vector<SDL_Point> superPelletPositions = superPellets.currentPositions();
  for (const auto & pos : superPelletPositions) {
    SDL_Rect maze_rect = targetRect({float_t(pos.x), float_t(pos.y)}, 8 * SCALE_FACTOR);
    renderTexture(sprite_texture.get(), &sprite_rect, &maze_rect);
  }
}

void GameWindow::renderPellets(const Pellets & pellets) const {
  SDL_Rect sprite_rect = pellets.currentSprite();
  std::vector<SDL_Point> pelletPositions = pellets.currentPositions();
  for (const auto & pos : pelletPositions) {
    SDL_Rect maze_rect = targetRect({float_t(pos.x), float_t(pos.y)}, 8 * SCALE_FACTOR);
    renderTexture(sprite_texture.get(), &sprite_rect, &maze_rect);
  }
}

void GameWindow::renderPacMan(const PacMan & pac_man) const {
  Position maze_position = pac_man.currentPosition();
  SDL_Rect maze_rect = targetRect(maze_position, 8 * SCALE_FACTOR);
  SDL_Rect sprite_rect = pac_man.currentSprite();
  renderTexture(sprite_texture.get(), &sprite_rect, &maze_rect);
}

SDL_Rect GameWindow::targetRect(const Position & position, int pixel_increase) {
  int pixels = 16 * SCALE_FACTOR;
  int displacement = pixel_increase / 2;
  return {
      int(pixels * position.x) - displacement,
      int(pixels * position.y) - displacement,
      (pixels + pixel_increase),
      (pixels + pixel_increase)
  };
}

void GameWindow::renderTexture(SDL_Texture * texture, SDL_Rect * texture_rect, SDL_Rect * target_rect) const {
  if (SDL_RenderCopy(renderer.get(), texture, texture_rect, target_rect) < 0)
    exitFailure("Failed to copy texture to renderer");
}

void GameWindow::initSDL() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    exitFailure("Failed to initialize the SDL2 library");
}

void GameWindow::initSDLImage() {
  int img_flags = IMG_INIT_PNG;
  if (IMG_Init(img_flags) != img_flags)
    exitImgFailure("Failed to init SDL_Image with png");
}

SDL_Window * GameWindow::createWindow(int width, int height) {
  window = std::unique_ptr<SDL_Window, SDL_Window_Deleter>(SDL_CreateWindow(
      "Pacman",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      width,
      height,
      SDL_WINDOW_OPENGL));

  if (!window)
    exitFailure("Failed to create window");

  return window.get();
}

SDL_Renderer * GameWindow::createRenderer(SDL_Window * sdl_window) {
  renderer = std::unique_ptr<SDL_Renderer, SDL_Renderer_Deleter>(SDL_CreateRenderer(
      sdl_window,
      -1,
      SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));

  if (!renderer)
    exitFailure("Failed to create renderer");

  return renderer.get();
}

void GameWindow::createWindowSurface(SDL_Window * sdl_window) {
  window_surface = std::unique_ptr<SDL_Surface, SDL_Surface_Deleter>(SDL_GetWindowSurface(sdl_window));
  if (!window_surface)
    exitFailure("Failed to get the surface from the window");
}

void GameWindow::setDrawColor(SDL_Renderer * sdl_renderer) {
  if (SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE) < 0)
    exitFailure("Failed to set renderer color");
}

std::unique_ptr<SDL_Texture, SDL_Texture_Deleter>
GameWindow::loadTexture(SDL_Renderer * sdl_renderer, const std::string & path) {
  auto surface = std::unique_ptr<SDL_Surface, SDL_Surface_Deleter>(IMG_Load(path.c_str()));
  if (!surface)
    exitImgFailure("Failed to load image");

  auto texture = std::unique_ptr<SDL_Texture, SDL_Texture_Deleter>(
      SDL_CreateTextureFromSurface(sdl_renderer, surface.get()));
  if (!texture)
    exitFailure("Failed to create texture from surface");
  return texture;
}

void GameWindow::exitFailure(const std::string & message) {
  std::cerr << message << "\n";
  std::cerr << "SDL2 Error: " << SDL_GetError() << "\n";
  exit(1);
}

void GameWindow::exitImgFailure(const std::string & message) {
  std::cerr << message << "\n";
  std::cerr << "SDL2_Image Error: " << IMG_GetError() << "\n";
  exit(1);
}
