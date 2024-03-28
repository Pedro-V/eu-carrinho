#include <Camera.h>
#include <Direction.h>
#include <utils.h>

#include <GL/gl.h>
#include <GL/glu.h>

Camera::Camera() {
  init();
}

void Camera::init() {
  eye = { 0.0, -2.0, 1.0 };
  center = { 0.0, 0.0, 0.0 };
}

void Camera::position() {
  glLoadIdentity();
  gluLookAt(
    eye.x, eye.y, eye.z,
    center.x, center.y, center.z,
    0, 0, 1
  );
}

void Camera::rotateZ(bool clockwise) {
   float newX = eye.x, newY = eye.y;
   if (clockwise) {
     newX = eye.x * cos(-angleIncrement) - eye.y * sin(-angleIncrement);
     newY = eye.x * sin(-angleIncrement) + eye.y * cos(-angleIncrement);                      
   } else {
     newX = eye.x * cos(angleIncrement) - eye.y * sin(angleIncrement);
     newY = eye.x * sin(angleIncrement) + eye.y * cos(angleIncrement);                      
   }
   eye.x = newX;
   eye.y = newY;
}

void Camera::positionBehind(Car& car, Terrain& t) {
  std::tie(eye.x, eye.y) = advanceDir(car.x, car.y, -car.dir, 3);
  eye.z = car.z + 1.0;

  center.x = car.x;
  center.y = car.y;
  center.z = car.z;

  position();
}

void Camera::zoom(double factor) {
  normalize(eye);
  eye.x *= factor;
  eye.y *= factor;
  eye.z *= factor;
}

