//
// Created by maxwell on 2019/11/28.
//
#ifndef P3_COLOREDFIG_H
#define P3_COLOREDFIG_H

#include "Figure.h"

class ColoredFig : public Figure {
protected:
    float r,g,b;
    bool k = true;
public:
    void setColor(float r,float g,float b);
    void color();
};

#endif //P3_COLOREDFIG_H
