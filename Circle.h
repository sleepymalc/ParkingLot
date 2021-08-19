//
// Created by maxwell on 2019/11/28.
//

#ifndef P3_CIRCLE_H
#define P3_CIRCLE_H

#include "ColoredFig.h"
#include "general.h"

class Circle : public ColoredFig {
   private:
    float R;

   public:
    Circle(){};
    Circle(Vec anchor, Vec re, float R, float r, float g, float b, bool k = true);
    float getR() { return R; }
    void draw() override;
    void zoom(float k) override;
    void rotate(float ang) override;
};

#endif  //P3_CIRCLE_H
