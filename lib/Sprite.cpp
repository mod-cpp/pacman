#include "Sprite.hpp"

Sprite::Sprite(SDL_Texture * texture, SDL_Rect rect)
  : m_texture(texture),
    m_rect(rect) {
}
