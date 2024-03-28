#include <cstdio>

#include <GL/glut.h>

#include <Terrain.h>
#include <Car.h>
#include <Camera.h>
#include <utils.h>

Terrain terrain;
Camera camera;
Car car;
SimulatorMode mode;

Vec3f sunPos;

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT /*| GL_DEPTH_BUFFER_BIT*/ );

  if (mode == SimulatorMode::Simulation) {
    camera.positionBehind(car, terrain);
  } else {
    camera.position();
    glTranslatef(-car.x, -car.y, -car.z);
  }
  terrain.draw();
  car.draw();
  /*drawAxis();*/
  drawSun(sunPos);

  glFlush();
  /*glutSwapBuffers();*/
}

void simulationSpecial(int key, int x, int y) {
  switch (key) {
    case GLUT_KEY_LEFT:
      car.rotate(false);
      break;
    case GLUT_KEY_RIGHT:
      car.rotate(true);
      break;
    case GLUT_KEY_UP:
      car.advance(terrain);
      break;
  }
  glutPostRedisplay();
}

void visualizationSpecial(int key, int x, int y) {
  static double factor = 2.0;
  switch(key) {
    case GLUT_KEY_LEFT:
      camera.rotateZ(true);
      break;
    case GLUT_KEY_RIGHT:
      camera.rotateZ(false);
      break;
    case GLUT_KEY_UP:
      factor -= 0.1;
      break;
    case GLUT_KEY_DOWN:
      factor += 0.1;
      break;
    case GLUT_KEY_F1:
      factor = 2.0;
      break;
  }
  camera.zoom(factor);
  glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 'M':
    case 'm':
      if (mode == SimulatorMode::Simulation) {
        mode = SimulatorMode::Visualization;
        camera.init();
        glutSpecialFunc(visualizationSpecial);
      } else {
        mode = SimulatorMode::Simulation;
        glutSpecialFunc(simulationSpecial);
      }
      break;
  }
}

void setupLighting() {
  GLfloat light0_position[] = { sunPos.x, sunPos.y, sunPos.z, 0.0 };
  GLfloat light0_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };

  glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
}

void init(const char* filename) {
  glClearColor(0.0, 0.0, 0.0, 0.0);

  terrain.init(filename);
  car.init(terrain);
  mode = SimulatorMode::Simulation;
  sunPos = { 3.0, ((float)terrain.cols) + 3, 10.0 };

  glEnable(GL_COLOR_MATERIAL);
  setupLighting();

  /*glEnable(GL_DEPTH_TEST);*/
}

void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, 1.0, 0.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
  if (argc < 2) {
    printf("Usage: %s <image.ppm>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB /*| GLUT_DEPTH*/);
  glutInitWindowSize(1000, 800);
  glutInitWindowPosition(100, 100);
  glutCreateWindow(argv[0]);;

  init(argv[1]);

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutSpecialFunc(simulationSpecial);
  glutKeyboardFunc(keyboard);

  glutMainLoop();

  return 0;
}
