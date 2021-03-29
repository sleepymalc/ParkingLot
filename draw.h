//
// Created by maxwell on 2019/11/28.
//

#ifndef P3_DRAW_H
#define P3_DRAW_H
#define GL_SILENCE_DEPRECATION
#include "Vec.h"
#include <GLUT/glut.h>

void point(Vec p,float rate=1);
void beginDraw(bool k = false);
void endDraw();

#endif //P3_DRAW_H

