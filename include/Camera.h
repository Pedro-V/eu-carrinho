#ifndef CAMERA_H
#define CAMERA_H

#include <cmath>

#include <Car.h>
#include <Terrain.h>
#include <utils.h>

class Camera {
private:
  Vec3f up = { 0.0, 0.0, 1.0 };
  float angleIncrement = 2*M_PI/180;

public:
  Vec3f eye;
  Vec3f center;

  Camera();
  void init();
  void rotateZ(bool clockwise);
  void position();
  void positionBehind(Car& car, Terrain& t);
  void zoom(double factor);
};

#endif
