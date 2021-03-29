//
// Created by maxwell on 2019/11/29.
//

#ifndef P3_LINE_H
#define P3_LINE_H

#include "ColoredFig.h"
#include "draw.h"
#include "general.h"

class Line : public ColoredFig {
private:
    Vec R ;
public:
    Line(){}
    Line(Vec anchor,Vec re, Vec R, float r, float g, float b);
    Vec getR(){return R;}
    void draw() override ;
    void zoom(float k) override ;
    void rotate(float ang) override ;
};




#endif //P3_LINE_H
