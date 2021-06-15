#pragma once

#include <memory>
#include <string>
#include <SDL2/SDL.h>

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
//class Position;
class SuperPellets;

class GameWindow {
public:
  explicit GameWindow();

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

  std::unique_ptr<SDL_Window, SDL_Window_Deleter> window;
  std::unique_ptr<SDL_Renderer, SDL_Renderer_Deleter> renderer;
  std::unique_ptr<SDL_Surface, SDL_Surface_Deleter> window_surface;
  std::unique_ptr<SDL_Texture, SDL_Texture_Deleter> maze_texture;
  std::unique_ptr<SDL_Texture, SDL_Texture_Deleter> sprite_texture;

  SDL_Window * createWindow(int width, int height);

  SDL_Renderer * createRenderer(SDL_Window * window);

  void createWindowSurface(SDL_Window * sdl_window);

  static void initSDL();

  static void initSDLImage();

  static void setDrawColor(SDL_Renderer * sdl_renderer);

  static void exitFailure(const std::string & message);

  static void exitImgFailure(const std::string & message);

  static std::unique_ptr<SDL_Texture, SDL_Texture_Deleter>
  loadTexture(SDL_Renderer * sdl_renderer, const std::string & path);

  void renderMaze() const;

  void renderPacMan(const PacMan & pac_man) const;

  void renderPellets(const Pellets & pellets) const;

  void renderSuperPellets(const SuperPellets & superPellets) const;

  //static SDL_Rect targetRect(const Position & position, int pixel_increase);

  SDL_Rect windowDimensions() const;

  // Given an x - y coordinate of a texture in the assets file,
  // returns a rectangle for the whole texture.
  // Assumes texture are laid out in a 32x32 grid
  SDL_Rect textureGeometry(SDL_Point) const;

  void renderTexture(SDL_Texture * texture, const SDL_Rect & src, SDL_Point) const;
  void renderTexture(SDL_Texture * texture, const SDL_Rect & src, const SDL_Rect & target) const;
};
