#include "Circle.h"

Circle::Circle(Vec anchor, Vec re, float R, float r, float g, float b, bool k) {
    this->R = R;
    this->k = k;
    setAnchor(anchor);
    setRelation(re);
    setColor(r, g, b);
}

void Circle::draw() {
    Vec temp = {R, 0};
    color();
    beginDraw(k);
    for (int i = 0; i < PRECISION; i++) {
        point(getpoint() + temp);
        temp >>= 360.0 / PRECISION;
    };
    point(getpoint() + temp);
    endDraw();
}

void Circle::zoom(float k) {
    zoomRe(k);
    R *= k;
}

void Circle::rotate(float ang) {
    turnRe(ang);
}
