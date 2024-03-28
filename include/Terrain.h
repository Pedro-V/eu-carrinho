#ifndef TERRAIN_H
#define TERRAIN_H

#include <GL/gl.h>

class Terrain {
private:

public:
    int **data;
    int max_z;
    int rows;
    int cols;
    GLenum drawMode;

    Terrain();
    ~Terrain();
    void init(const char *filename, GLenum _drawMode = GL_FILL);
    void readData(const char *filename);
    void draw();
    void drawMesh();
    void centralizeMesh();
    bool validPosition(int x, int y) const;
    int** getData();
};

#endif
