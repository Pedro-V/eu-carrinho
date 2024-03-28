#include <Car.h>
#include <utils.h>

#include <iostream>
#include <fstream>
#include <sstream>

#include <cstdio>

#include <GL/gl.h>


void Car::init(const Terrain& t) {
  parseObj("assets/Jeep.obj");
  x = 0;
  y = 0;
  dir = Direction::North;
  z = t.data[x][y];
}

bool Car::parseObj(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Failed to open file " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;
        if (type == "v") {
            Vec3f vertex;
            iss >> vertex.x >> vertex.y >> vertex.z;
            vertices.push_back(vertex);
        } else if (type == "vn") {
            Vec3f normal;
            iss >> normal.x >> normal.y >> normal.z;
            normals.push_back(normal);
        } else if (type == "vt") {
            Vec3f tex_coord;
            iss >> tex_coord.x >> tex_coord.y;
            texture_coords.push_back(tex_coord);
        } else if (type == "f") {
            FaceVertex face;
            char separator;
            for (int i = 0; i < 3; ++i) { // Assuming triangles
                iss >> face.v_index >> separator >> face.vt_index >> separator >> face.vn_index;
                faces.push_back(face);
            }
        }
    }

    file.close();
    return true;
}

void Car::renderMesh() {
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glBegin(GL_TRIANGLES);
  for (const auto& face : faces) {
      const auto& vertex = vertices[face.v_index - 1]; // OBJ indices start from 1
      const auto& normal = normals[face.vn_index - 1];
      const auto& tex_coord = texture_coords[face.vt_index - 1];
      glNormal3f(normal.x, normal.y, normal.z);
      glTexCoord2f(tex_coord.x, tex_coord.y);
      glVertex3f(vertex.x, vertex.y, vertex.z);
  }
  glEnd();
}

void Car::rotateModel() {
  switch (dir) {
    // Rotating 90º around x leaves the model poiting North.
    case Direction::North:
      glRotatef(180, 0.0, 0.0, 1.0);
      break;
    case Direction::East:
      glRotatef(90, 0.0, 0.0, 1.0);
      break;
    case Direction::South:
      glRotatef(0, 0.0, 0.0, 1.0);
      break;
    case Direction::West:
      glRotatef(270, 0.0, 0.0, 1.0);
      break;
  }
  glRotatef(90, 1.0, 0.0, 0.0);
}

void Car::draw() {
  glPushMatrix();

  glTranslatef(x, y, z + 0.1);
  rotateModel();
  glScalef(0.2, 0.2, 0.2);
  glColor3f(0.0, 1.0, 0.0);
  renderMesh();

  glPopMatrix();
}


void Car::advance(const Terrain& t) {
  auto [x_p, y_p] = advanceDir(x, y, dir);

  if (t.validPosition(x_p, y_p)) {
    x = x_p;
    y = y_p;
    z = t.data[x][y];
  }
}

void Car::rotate(bool clockwise) {
  dir = clockwise ? ++dir : --dir;
}

