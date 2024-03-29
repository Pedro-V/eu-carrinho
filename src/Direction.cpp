#include <Direction.h>
#include <map>

// Goes to the next direction in clockwise order.
Direction& operator++(Direction& dir) {
  dir = static_cast<Direction>((static_cast<int>(dir) + 1) % directionsNum);
  return dir;
}

// Goes to the next direction in counter-clockwise order.
Direction& operator--(Direction& dir) {
  // Increment by directionsNum to avoid negative modulo operand.
  dir = static_cast<Direction>((static_cast<int>(dir) - 1 + directionsNum) % directionsNum);
  return dir;
}

// Negating equals the opposing direction (North <=> South, East <=> West).
Direction operator-(Direction dir) {
  int halfway = directionsNum / 2;
  return static_cast<Direction>((static_cast<int>(dir) + halfway) % directionsNum);
}

std::tuple<int, int> advanceDir(int x, int y, Direction dir, int scale) {
    std::map<Direction, std::tuple<int, int>> Increments {
        {Direction::North, {0, 1}},
        {Direction::NorthEast, {1, 1}},
        {Direction::East, {1, 0}},
        {Direction::SouthEast, {1, -1}},
        {Direction::South, {0, -1}},
        {Direction::SouthWest, {-1, -1}},
        {Direction::West, {-1, 0}},
        {Direction::NorthWest, {-1, 1}}
    };

    auto [x_increment, y_increment] = Increment[dir];
    return std::make_tuple(x + scale * x_increment, y + scale * y_increment);
}

int getDistanceFrom(Direction d1, Direction d2) {
  return static_cast<int>(d1) - static_cast<int>(d2);
}
