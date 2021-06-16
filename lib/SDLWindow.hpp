#pragma once

#include "Sprite.hpp"
#include <SDL2/SDL.h>
#include <memory>
#include <string>

struct SDL_Window_Deleter {
  void operator()(SDL_Window * window) {
    SDL_DestroyWindow(window);
  }
};

struct SDL_Renderer_Deleter {
  void operator()(SDL_Renderer * renderer) {
    SDL_DestroyRenderer(renderer);
  }
};

struct SDL_Surface_Deleter {
  void operator()(SDL_Surface * surface) {
    SDL_FreeSurface(surface);
  }
};

struct SDL_Texture_Deleter {
  void operator()(SDL_Texture * texture) {
    SDL_DestroyTexture(texture);
  }
};

struct TextureSize {
  int width;
  int height;
};

class PacMan;
class Pellets;
class SuperPellets;

class SDLWindow {
public:
  explicit SDLWindow();

  void clear();

  void render();

  Sprite getBackground() const;
  Sprite getSprite(SDL_Point point) const;
  void renderSprite(Sprite sprite, SDL_Point point) const;
  void renderSprite(Sprite sprite, SDL_Rect target) const;

private:


  std::unique_ptr<SDL_Window, SDL_Window_Deleter> window;
  std::unique_ptr<SDL_Renderer, SDL_Renderer_Deleter> renderer;
  std::unique_ptr<SDL_Surface, SDL_Surface_Deleter> window_surface;
  std::unique_ptr<SDL_Texture, SDL_Texture_Deleter> maze_texture;
  std::unique_ptr<SDL_Texture, SDL_Texture_Deleter> sprite_texture;

  void createWindow(int width, int height);

  void createRenderer();

  void createWindowSurface();

  static void initSDL();

  static void initSDLImage();

  void setDrawColor();

  static void exitFailure(const std::string & message);

  static void exitImgFailure(const std::string & message);

  std::unique_ptr<SDL_Texture, SDL_Texture_Deleter>
  loadTexture(const std::string & path);

  SDL_Rect windowDimensions() const;

  // Given an x - y coordinate of a texture in the assets file,
  // returns a rectangle for the whole texture.
  // Assumes texture are laid out in a 32x32 grid
  SDL_Rect textureGeometry(SDL_Point) const;

  void renderTexture(SDL_Texture * texture, const SDL_Rect & src, SDL_Point) const;
  void renderTexture(SDL_Texture * texture, const SDL_Rect & src, const SDL_Rect & target) const;
};
