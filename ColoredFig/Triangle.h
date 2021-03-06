#ifndef P3_TRIANGLE_H
#define P3_TRIANGLE_H

#include "../draw.h"
#include "ColoredFig.h"

class Triangle : public ColoredFig {
   private:
    Vec s1, s2;

   public:
    Triangle(){};
    Triangle(Vec anchor, Vec re, Vec s1, Vec s2, float r, float g, float b, bool k = true);
    void draw() override;
    void zoom(float k) override;
    void rotate(float ang) override;
};

#endif  //P3_TRIANGLE_H
