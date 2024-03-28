#include <Direction.h>

#include <map>

// Goes to the next direction in clockwise order.
Direction& operator++(Direction& dir) {
  dir = static_cast<Direction>((static_cast<int>(dir) + 1) % 4);
  return dir;
}

// Goes to the next direction in counter-clockwise order.
Direction& operator--(Direction& dir) {
  // Increment by 4 to avoid negative modulo operand.
  dir = static_cast<Direction>((static_cast<int>(dir) - 1 + 4) % 4);
  return dir;
}

// Negating equals the opposing direction (North <=> South, East <=> West).
Direction operator-(Direction dir) {
    return static_cast<Direction>((static_cast<int>(dir) + 2) % 4);
}

std::tuple<int, int> advanceDir(int x, int y, Direction dir, int scale) {
    std::map<Direction, std::tuple<int, int>> Increments {
        {Direction::North, {0, 1}},
        {Direction::East, {1, 0}},
        {Direction::South, {0, -1}},
        {Direction::West, {-1, 0}}
    };

    auto inc = Increments[dir];
    auto [x_increment, y_increment] = inc;
    return std::make_tuple(x + scale * x_increment, y + scale * y_increment);
}
