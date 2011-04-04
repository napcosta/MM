#include "Lights.h"

namespace Micromachines {

Lights::Lights() : cg::Entity("LIGHTS") {}

Lights::~Lights() {}

void Lights::init() {

glEnable(GL_LIGHTING);
glEnable(GL_COLOR_MATERIAL);

// Luz ambiente
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 50.0 };
GLfloat light_position[]= {1.0, 1.0, 1.0, 0.0 };
GLfloat white_light[] = { 0.4, 0.4, 0.8, 1.0 };
GLfloat lmodel_ambient[]= { 1.0, 1.0, 1.0, 1.0 };
glClearColor(0.0, 0.0, 0.0, 0.0);
glShadeModel(GL_SMOOTH);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
glLightfv(GL_LIGHT0, GL_POSITION, light_position);
glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

glEnable (GL_COLOR_MATERIAL);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_DEPTH_TEST);

static GLfloat amblight_pos[] = { 0, 0, 0.0, 1.0};
static GLfloat amblight_diff[] = { 0.7, 0.7, 0.7, 1.0 };

// Luz direccional
//static GLfloat dirlight_pos[] = { 0.0, 0.0, 0.0, 0.0};
static GLfloat dirlight_dir[] = { 1.0, 0.0, 0.0, 1.0};
//static GLfloat dirlight_diff[] = { 0.7, 0.7, 0.7, 1.0 };
//static GLfloat dirlight_spec[] = { 0.0, 0.0, 1.0, 1.0 };

glLightfv(GL_LIGHT2, GL_POSITION, amblight_pos);
glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dirlight_dir);
glLightfv(GL_LIGHT2, GL_DIFFUSE, amblight_diff);

glEnable(GL_LIGHT2);
glEnable(GL_NORMALIZE);
}

}
