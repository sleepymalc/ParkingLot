#include "Ellipse.h"
Ellipse::Ellipse(Vec anchor, Vec re, Vec paras, float ang, float r, float g, float b, bool k) {
    this->k = k;
    setAnchor(anchor);
    setRelation(re);
    setColor(r, g, b);
    ap = paras.getX();
    bp = paras.getY();
    for (int i = 0; i < PRECISION; i++) {
        float tmpx = ap * Cos(i * 360 / PRECISION);
        float tmpy = bp * Sin(i * 360 / PRECISION);
        Vec tmp = {tmpx, tmpy};
        tmp = tmp << ang;
        pts.push_back(tmp);
    }
}

void Ellipse::draw() {
    color();
    beginDraw(k);
    for (auto i : pts) {
        point(getpoint() + i);
    };
    endDraw();
}

void Ellipse::zoom(float k) {
    zoomRe(k);
    for (int i = 0; i < PRECISION; i++) {
        pts.at(i) *= k;
    };
}

void Ellipse::rotate(float ang) {
    turnRe(ang);
    for (int i = 0; i < PRECISION; i++) {
        pts.at(i) <<= ang;
    };
}