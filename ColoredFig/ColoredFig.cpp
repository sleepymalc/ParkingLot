#define GL_SILENCE_DEPRECATION
#include "ColoredFig.h"

#include <GLUT/glut.h>

void ColoredFig::setColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void ColoredFig::color() {
    glColor3f(r, g, b);
}
