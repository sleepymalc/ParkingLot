#ifndef P3_ELLIPSE_H
#define P3_ELLIPSE_H

#include "../general.h"
#include "ColoredFig.h"

class Ellipse : public ColoredFig {
   private:
    vector<Vec> pts;
    float ap, bp;

   public:
    Ellipse(){};
    Ellipse(Vec anchor, Vec re, Vec paras, float ang, float r, float g, float b, bool k = true);
    void draw() override;
    void zoom(float k) override;
    void rotate(float ang) override;
};

#endif  //P3_ELLIPSE_H
