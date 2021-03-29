//
// Created by maxwell on 2019/11/29.
//

#include "Arc.h"
#include "classes.h"

Arc::Arc(Vec anchor,Vec re, Vec R, float ang, float r, float g, float b, bool k) {
    setAnchor(anchor);
    setRelation(re);
    setColor(r,g,b);
    this->k = k;
    this->R = R;
    this->Ang = ang;
}

void Arc::draw() {
    Vec temp = R;
    color();
    beginDraw(k);
    for(int i=0;i<PRECISION;i++){
        point(getpoint()+temp);
        temp>>= Ang/PRECISION;
    };
    point(getpoint()+temp);
    temp*=cos(pi_angle(Ang));
    point(getpoint()+temp);
    endDraw();
}

void Arc::zoom(float k) {
    zoomRe(k);
    R*=k;
}

void Arc::rotate(float ang) {
    turnRe(ang);
    R<<=ang;
}