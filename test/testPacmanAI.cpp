#include <catch2/catch.hpp>
#include <PacManAI.hpp>

TEST_CASE("find pellet closest to pacman", "[AI]") {
    using namespace pacman;
    PacManAI AI;
    using TestData = std::tuple<GridPosition, std::vector<GridPosition>, GridPosition>;
    auto data = GENERATE(
                TestData{{5, 5}, {{5, 6}}, {5, 6}},
                TestData{{5, 5}, {{5, 5}}, {5, 5}},
                TestData{{5, 5}, {{0, 0}, {5, 6}}, {5, 6}},
                TestData{{5, 5}, {{6, 5}, {5, 6}}, {6, 5}},
                TestData{{5, 5}, {{6, 6}, {5, 6}}, {5, 6}}
                );

    CHECK(AI.pelletClosestToPacman(std::get<0>(data), std::get<1>(data)) == std::get<2>(data));
}

TEST_CASE("Is valid move", "[AI]") {
    using namespace pacman;
    using TestData = std::tuple<PacManAI::Move, bool>;
    auto data = GENERATE(
                TestData{{Direction::RIGHT, {13, 23}}, true},
                TestData{{Direction::LEFT, {13, 23}}, false}, // opposite direction
                TestData{{Direction::RIGHT, {13, 22}}, false} // wall
                );

    PacManAI AI;
    CHECK(AI.isValidMove(std::get<0>(data)) == std::get<1>(data));
}

TEST_CASE("is optimal direction", "[AI]") {
    using namespace pacman;
    //using TestData = std::tuple<std::array<PacManAI::Move, 4>, std::size_t>;
}
