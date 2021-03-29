//
// Created by maxwell on 2019/11/28.
//

#include "Semi.h"

Semi::Semi(Vec anchor,Vec re, Vec R, float ang, float r, float g, float b,bool k) {
    setAnchor(anchor);
    setRelation(re);
    setColor(r,g,b);
    this->R = R;
    this->Ang = ang;
    this->k = k;
}

void Semi::draw() {
    Vec temp = R;
    color();
    beginDraw(k);
    for(int i=0;i<PRECISION;i++){
        point(getpoint()+temp);
        temp>>= Ang/PRECISION;
    };
    point(getpoint()+temp);
    endDraw();
}

void Semi::zoom(float k) {
    zoomRe(k);
    R*=k;
}

void Semi::rotate(float ang) {
    turnRe(ang);
    R<<=ang;
}
