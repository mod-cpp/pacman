#pragma once

#include "Sprite.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
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

struct SDL_Font_Deleter {
  void operator()(TTF_Font* font) {
    TTF_CloseFont(font);
  }
};

using SDLTexturePtr = std::unique_ptr<SDL_Texture, SDL_Texture_Deleter>;
using SDLSurfacePtr = std::unique_ptr<SDL_Surface, SDL_Surface_Deleter>;


class PacMan;
class Pellets;
class SuperPellets;

class SDLWindow {
public:
  explicit SDLWindow(SDL_Rect windowGeometry);

  static constexpr auto White = SDL_Color{0xFF, 0xFF, 0xFF};

  void clear();

  void render();

  Sprite getBackground() const;
  Sprite getSprite(SDL_Rect rect) const;
  void renderSprite(Sprite sprite, SDL_Rect target) const;
  void drawText(const std::string &text, SDL_Point position, SDL_Color textColor = White) const;

private:
  static constexpr int16_t SCALE_FACTOR = 1;

  std::unique_ptr<SDL_Window, SDL_Window_Deleter> window;
  std::unique_ptr<SDL_Renderer, SDL_Renderer_Deleter> renderer;
  SDLSurfacePtr window_surface;
  SDLTexturePtr maze_texture;
  SDLTexturePtr sprite_texture;
  std::unique_ptr<TTF_Font, SDL_Font_Deleter> font;

  void createWindow(int width, int height);

  void createRenderer();

  void createWindowSurface();

  static void initSDL();

  static void initSDLImage();

  void initSDLTTF();

  void setDrawColor();

  static void exitFailure(const std::string & message);

  static void exitImgFailure(const std::string & message);

  std::unique_ptr<SDL_Texture, SDL_Texture_Deleter>
  loadTexture(const std::string & path);

  SDL_Rect windowDimensions() const;

  std::tuple<int, int> textureSize(SDL_Texture* texture) const;
};
