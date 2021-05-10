#include "SuperPellets.hpp"

SuperPellets::SuperPellets(const Board & board) :
    positions(board.initialSuperPelletPositions()) {}
