//
// Created by maxwell on 2019/11/28.
//

#include "Triangle.h"
#include "draw.h"


Triangle::Triangle(Vec anchor,Vec re, Vec s1, Vec s2,float r,float g,float b,bool k){
    setAnchor(anchor);
    setRelation(re);
    setColor(r,g,b);
    this->s1 = s1;
    this->s2 = s2;
    this->k = k;
}

void Triangle::draw() {
    color();
    beginDraw(k);
    point(getpoint());
    point(getpoint()+s1);
    point(getpoint()+s1+s2);
    endDraw();
}

void Triangle::zoom(float k) {
    s1 *=k;
    s2 *=k;
    zoomRe(k);
}

void Triangle::rotate(float ang) {
    s1 <<=ang;
    s2 <<=ang;
    turnRe(ang);
}
