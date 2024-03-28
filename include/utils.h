#ifndef UTILS_H
#define UTILS_H

#include <cmath>

struct Vec3f {
    float x, y, z;
};

struct FaceVertex {
    int v_index;
    int vt_index;
    int vn_index;
};

enum class SimulatorMode { Simulation, Visualization };

void drawAxis();
void drawSun(Vec3f pos);
void drawCube();

void normalize(Vec3f& vec);
#endif
