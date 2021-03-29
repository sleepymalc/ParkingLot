//
// Created by maxwell on 2019/11/29.
//

#ifndef P3_ARC_H
#define P3_ARC_H

#include "ColoredFig.h"
#include "draw.h"
#include "general.h"

class Arc : public ColoredFig {
private:
    Vec R;
    float Ang;//0-360
public:
    Arc(){};
    Arc(Vec anchor,Vec re, Vec R, float ang, float r, float g, float b, bool k = true);
    Vec getR(){return R;}
    float getAng(){return Ang;}
    void draw() override ;
    void zoom(float k) override ;
    void rotate(float ang) override ;
};





#endif //P3_ARC_H
