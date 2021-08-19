//
// Created by maxwell on 2019/12/10.
//

#ifndef P3_ELLIPSE_H
#define P3_ELLIPSE_H

#include "ColoredFig.h"
#include "general.h"

class Ellipse : public ColoredFig {
private:
    vector<Vec> pts;
    float ap,bp;
public:
    Ellipse(){};
    Ellipse(Vec anchor,Vec re,Vec paras,float ang,float r,float g,float b,bool k = true);
    void draw() override ;
    void zoom(float k) override ;
    void rotate(float ang) override ;
};

#endif //P3_ELLIPSE_H
