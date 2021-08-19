#ifndef P3_DRAW_H
#define P3_DRAW_H
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>

#include "Vec.h"

void point(Vec p, float rate = 1);
void beginDraw(bool k = false);
void endDraw();

#endif  //P3_DRAW_H
