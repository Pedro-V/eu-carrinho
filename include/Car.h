#ifndef CAR_H
#define CAR_H

#include <vector>
#include <string>

#include <Terrain.h>
#include <Direction.h>
#include <utils.h>

class Car {
private:
  std::vector<Vec3f> vertices;
  std::vector<Vec3f> normals;
  std::vector<Vec3f> texture_coords;
  std::vector<FaceVertex> faces;

public:
  int x, y, z;
  Direction dir;

  void init(const Terrain& t);
  bool parseObj(const std::string& filename);
  void renderMesh();
  void rotateModel();
  void advance(const Terrain& t);
  void rotate(bool clockwise);
  void draw();
};

#endif
