//
// Created by maxwell on 2019/11/28.
//

#ifndef P3_TRIANGLE_H
#define P3_TRIANGLE_H

#include "ColoredFig.h"

//#include "../classes.h"

class Triangle : public ColoredFig{
private:
    Vec s1,s2;
    Vec *anchor;
public:
    Triangle(){};
    Triangle(Vec anchor,Vec re, Vec s1, Vec s2,float r,float g,float b,bool k = true);
    void draw() override ;
    void zoom(float k) override ;
    void rotate(float ang) override ;
};


#endif //P3_TRIANGLE_H
