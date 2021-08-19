#ifndef P3_RECTANGLE_H
#define P3_RECTANGLE_H

#include "ColoredFig.h"

class Rectangle : public ColoredFig {
    Vec s1, s2;

   public:
    Rectangle(){};
    Rectangle(Vec anchor, Vec re, Vec sidea, Vec sideb, float r, float g, float b, bool k = true);
    void draw() override;
    void zoom(float k) override;
    void rotate(float ang) override;
    Vec getSide() { return s1; }
};

#endif  //P3_RECTANGLE_H
