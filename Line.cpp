//
// Created by maxwell on 2019/11/29.
//

#include "Line.h"

Line::Line(Vec anchor,Vec re, Vec R, float r, float g, float b){
setAnchor(anchor);
setRelation(re);
setColor(r,g,b);
this->R = R;
}

void Line::draw(){
    beginDraw();
    point(getpoint());
    point(getpoint()+R);
    endDraw();
}
void Line::zoom(float k){
    R*=k;
    zoomRe(k);
}
void Line::rotate(float ang){
    turnRe(ang);
    R<<=ang;
}