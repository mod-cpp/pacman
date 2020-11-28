#include "../lib/Game.hpp"

extern "C" int main([[maybe_unused]] int argc, [[maybe_unused]] char * argv[]) {
  Game game;
  game.run();
  return 0;
}
