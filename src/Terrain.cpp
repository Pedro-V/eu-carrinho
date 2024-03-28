#include <Terrain.h>

#include <cstdio>

#include <GL/gl.h>

Terrain::Terrain() : data(nullptr), rows(0), cols(0) {}

/*
Terrain::Terrain(const char* filename) {
  readData(filename);
}
*/

void Terrain::init(const char* filename, GLenum _drawMode) {
  readData(filename);
  drawMode = _drawMode;
}

Terrain::~Terrain() {
  for (int i = 0; i < rows; ++i) {
    delete[] data[i];
  }
  delete[] data;
}

void Terrain::readData(const char* filename) {
  FILE *input = fopen(filename, "r");
  fscanf(input, "%*3s%d %d\n%*d\n", &cols, &rows);

  data = new int*[rows];
  for (int i = 0; i < rows; i++)
    data[i] = new int[cols];

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      fscanf(input, "%d", &(data[i][j]));

  fclose(input);
}

int** Terrain::getData() {
  return data;
}

void Terrain::centralizeMesh() {
  glRotatef(-90, 0.0, 0.0, 1.0);
  glTranslatef(-rows/2, -cols/2, 0);
}

void Terrain::drawMesh() {
  glPolygonMode(GL_FRONT_AND_BACK, drawMode);
  glColor3f(0.64, 0.16, 0.16);
  for (int i = 0; i < (rows - 1); i++) {
    glBegin(GL_TRIANGLE_STRIP);
    for (int j = 0; j < cols; j++) {
      float x1 = (float) i;
      float x2 = (float) (i + 1);
      float y  = (float) j;
      float z1 = (float) data[i][j];
      float z2 = (float) data[i + 1][j];

      glVertex3f(x1, y, z1);
      glVertex3f(x2, y, z2);
    }
    glEnd();
  }
}

void Terrain::draw() {
  glPushMatrix();
  drawMesh();
  glPopMatrix();
}

bool Terrain::validPosition(int x, int y) const {
  return (x >= 0 && x < rows) && (y >= 0 && y < cols);
}
