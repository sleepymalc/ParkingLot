#include "Rectangle.h"

#include "../draw.h"

Rectangle::Rectangle(Vec anchor, Vec re, Vec s1, Vec s2, float r, float g, float b, bool k) {
    setAnchor(anchor);
    setRelation(re);
    setColor(r, g, b);
    this->s1 = s1;
    this->s2 = s2;
    this->k = k;
}

void Rectangle::draw() {
    color();
    beginDraw(k);
    point(getpoint());
    point(getpoint() + s1);
    point(getpoint() + s1 + s2);
    point(getpoint() + s2);
    endDraw();
}

void Rectangle::zoom(float k) {
    s1 *= k;
    s2 *= k;
    zoomRe(k);
}

void Rectangle::rotate(float ang) {
    s1 <<= ang;
    s2 <<= ang;
    turnRe(ang);
}
