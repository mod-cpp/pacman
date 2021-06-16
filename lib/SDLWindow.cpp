#include "SDLWindow.hpp"

#include <SDL2/SDL_image.h>
#include <iostream>

SDLWindow::SDLWindow(SDL_Rect windowGeometry) {
  initSDL();
  initSDLImage();

  createWindow(windowGeometry.w, windowGeometry.h);
  createRenderer();
  createWindowSurface();
  setDrawColor();
  maze_texture = loadTexture("maze.png");
  sprite_texture = loadTexture("sprites32.png");
}

void SDLWindow::clear() {
  SDL_RenderClear(renderer.get());
}

void SDLWindow::render() {
  SDL_RenderPresent(renderer.get());
}

Sprite SDLWindow::getBackground() const {
  int w, h;
  if (SDL_QueryTexture(maze_texture.get(), nullptr, nullptr, &w, &h) != 0) {
    exitFailure("Failed to get texture geometry");
  }

  SDL_Rect maze_rect = { 0, 0, w, h };
  return { maze_texture.get(), maze_rect };
}

Sprite SDLWindow::getSprite(SDL_Rect rect) const {
  return { sprite_texture.get(), rect };
}

void SDLWindow::renderSprite(Sprite sprite, SDL_Rect target) const {
  if (SDL_RenderCopy(renderer.get(), sprite.texture, &sprite.rect, &target) < 0)
    exitFailure("Failed to copy texture to renderer");
}

void SDLWindow::initSDL() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    exitFailure("Failed to initialize the SDL2 library");
}

void SDLWindow::initSDLImage() {
  int img_flags = IMG_INIT_PNG;
  if (IMG_Init(img_flags) != img_flags)
    exitImgFailure("Failed to init SDL_Image with png");
}

void SDLWindow::createWindow(int width, int height) {
  window = std::unique_ptr<SDL_Window, SDL_Window_Deleter>(SDL_CreateWindow(
    "Pacman",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    width,
    height,
    SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI));

  if (!window)
    exitFailure("Failed to create window");
}

void SDLWindow::createRenderer() {
  renderer = std::unique_ptr<SDL_Renderer, SDL_Renderer_Deleter>(SDL_CreateRenderer(
    window.get(),
    -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));

  if (!renderer)
    exitFailure("Failed to create renderer");
}

void SDLWindow::createWindowSurface() {
  window_surface = std::unique_ptr<SDL_Surface, SDL_Surface_Deleter>(SDL_GetWindowSurface(window.get()));
  if (!window_surface)
    exitFailure("Failed to get the surface from the window");
}

void SDLWindow::setDrawColor() {
  if (SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, SDL_ALPHA_OPAQUE) < 0)
    exitFailure("Failed to set renderer color");
}

std::unique_ptr<SDL_Texture, SDL_Texture_Deleter>
SDLWindow::loadTexture(const std::string & path) {
  auto surface = std::unique_ptr<SDL_Surface, SDL_Surface_Deleter>(IMG_Load(path.c_str()));
  if (!surface)
    exitImgFailure("Failed to load image");

  auto texture = std::unique_ptr<SDL_Texture, SDL_Texture_Deleter>(
    SDL_CreateTextureFromSurface(renderer.get(), surface.get()));
  if (!texture)
    exitFailure("Failed to create texture from surface");
  return texture;
}

void SDLWindow::exitFailure(const std::string & message) {
  std::cerr << message << "\n";
  std::cerr << "SDL2 Error: " << SDL_GetError() << "\n";
  exit(1);
}

void SDLWindow::exitImgFailure(const std::string & message) {
  std::cerr << message << "\n";
  std::cerr << "SDL2_Image Error: " << IMG_GetError() << "\n";
  exit(1);
}
