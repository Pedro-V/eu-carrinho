#ifndef DIRECTION_H
#define DIRECTION_H

#include <tuple>

enum class Direction { North, East, South, West };

Direction& operator++(Direction& dir);

Direction& operator--(Direction& dir);

Direction operator-(Direction dir);

std::tuple<int, int> advanceDir(int x, int y, Direction dir, int scale = 1);

#endif
