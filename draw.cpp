#include "draw.h"

void point(Vec p, float rate) {
    glVertex2f(p.getX(), rate * p.getY());
}

void beginDraw(bool k) {
    if (k)
        glBegin(GL_POLYGON);
    else {
        glBegin(GL_LINE_LOOP);
    }
}

void endDraw() {
    glEnd();
}