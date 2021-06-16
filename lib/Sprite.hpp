#pragma once

#include <SDL2/SDL.h>
#include <memory>

class Sprite {
public:
  Sprite(SDL_Texture * texture, SDL_Rect rect);
  SDL_Texture * texture() { return m_texture; }
  SDL_Rect rect() { return m_rect; }

private:
  SDL_Texture * m_texture;
  SDL_Rect m_rect;
};
