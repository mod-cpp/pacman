#ifndef PACMAN_GAMEWINDOW_H
#define PACMAN_GAMEWINDOW_H

#include <memory>
#include <string>

#include "PacMan.h"
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

class PacMan;

class GameWindow {
public:
  explicit GameWindow(int width, int height);
  void update(const PacMan & pacMan, Board board);

private:
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
  static void exitFailure(const std::string& message);
  static void exitImgFailure(const std::string& message);
  static std::unique_ptr<SDL_Texture, SDL_Texture_Deleter> loadTexture(SDL_Renderer * sdl_renderer, const std::string& path);
  void renderMaze() const;
  void renderPacMan(const PacMan & pac_man) const;
  void renderBoard(Board board);
  void renderPellets(Board & board) const;
  void renderSuperPellets(Board & board) const;
  static SDL_Rect targetRect(const Position & position, int pixel_increase);
  void renderTexture(SDL_Texture * texture, SDL_Rect * texture_rect, SDL_Rect * target_rect) const;
};

#endif //PACMAN_GAMEWINDOW_H
