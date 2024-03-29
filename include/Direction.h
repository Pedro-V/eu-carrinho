#ifndef DIRECTION_H
#define DIRECTION_H

#include <tuple>

enum class Direction { North, NorthEast, East, SouthEast, South, SouthWest, West, NorthWest };

const int directionsNum = 8;

Direction& operator++(Direction& dir);

Direction& operator--(Direction& dir);

Direction operator-(Direction dir);

std::tuple<int, int> advanceDir(int x, int y, Direction dir, int scale = 1);

int getDistanceFrom(Direction d1, Direction d2);
#endif
