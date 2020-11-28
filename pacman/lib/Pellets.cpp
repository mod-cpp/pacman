#include "Pellets.hpp"

Pellets::Pellets(const Board & board) :
    positions(board.initialPelletPositions()) {}
