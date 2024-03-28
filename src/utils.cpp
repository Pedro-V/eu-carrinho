#include <utils.h>

#include <GL/gl.h>
#include <GL/glut.h>

void drawAxis()
{
  glPushAttrib(GL_LIGHTING_BIT);

  glDisable(GL_LIGHTING);
  glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(3.0, 0.0, 0.0);

    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 3.0, 0.0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 3.0);
  glEnd();

  glPopAttrib();
}

void drawSun(Vec3f pos) {
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glPushAttrib(GL_LIGHTING_BIT);
  glPushMatrix();

  glDisable(GL_LIGHTING);

  glTranslatef(pos.x, pos.y, pos.z);
  glColor3f(1.0, 1.0, 0.0);
  glutSolidSphere(4, 50, 50);

  glPopAttrib();
  glPopMatrix();
}

void drawCube() {
  glPushMatrix();
  glTranslatef(1.0, 0.0, 0.0);
  glColor3f(1.0, 0.0, 1.0);
  glutSolidCube(0.4);
  glPopMatrix();
}


void normalize(Vec3f& vec) {
  double magnitude = std::pow(vec.x, 2) + std::pow(vec.y, 2) + std::pow(vec.z, 2);
  magnitude = std::sqrt(magnitude);
  vec.x /= magnitude;
  vec.y /= magnitude;
  vec.z /= magnitude;
}
